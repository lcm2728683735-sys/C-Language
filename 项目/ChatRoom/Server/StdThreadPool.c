#include "StdThreadPool.h"
#include "LinkQueue.h"
#include "List.h"
#include "StdThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>

typedef struct
{
    void * (*func)(void*);
    void * arg;
}Task;

Task* CreateTask(void* (*func)(void*),void * arg)
{
    Task * t = (Task *)malloc(sizeof(Task));
    if(t == NULL)
    {
        printf("CreateTask malloc error!\n");
        return NULL;
    }

    t ->func = func;
    t->arg = arg;
    return t;
}

struct StdThreadPool
{
    List threads; //线程列表
    LinkQueue taskQueue;//任务队列
    int MaxThrdNum;  //最大线程
    int MinThrdNum;     //最小线程
    int MaxQueueSize;   //最大任务数量

    int BusyThrdNum;        //忙碌线程数量
    int MinusNum;
    StdMutex * BusyThrdMutex; //忙线程锁
    StdMutex * PoolMutex; //线程池锁
    Cond * QueueNotFull;   //队列不满的条件变量
    Cond * QueueNotEmpty;  //队列不为空的条件变量

    Thread * manager;//管理者线程
    int SleepTime;    //管理者线程的管理间隔
    bool IsClose;       //是否关闭线程池
};

bool IsThreadEqual(void * thread1,void * thread2)
{
    Thread * t = (Thread*)thread1;
    return IsCurrentThread(t);
}

void * ThreadWork(void * arg)
{
    ThreadP *p = (ThreadP*)arg;
    while(p->IsClose == false)
    {
        //取任务
        if(!MutexLock(p->PoolMutex))
        {
            perror("MutexLock errro");
            return NULL;
        }
        //任务队列为空
        while(LinkQueue_IsEmpty(&p->taskQueue) == true)
        {
            if(!CondWait(p->QueueNotEmpty,p->PoolMutex))
                perror("pthread_cond_wait failed");

            if(p->IsClose == true)
            {
                if(!MutexUnlock(p->PoolMutex))
                    perror("MutexUnlock errro");
                ThreadExit();
            }
            //如果需要削减线程
            if(p->MinusNum > 0)
            {
                //线程退出
                List_RemoveByElement(&p->threads,NULL,IsThreadEqual,free);
                p->MinusNum--;
                MutexUnlock(p->PoolMutex);
                ThreadExit();
            }
        }
        Task * t = (Task*)LinkQueue_GetFront(&p->taskQueue);
        LinkQueue_Pop(&p->taskQueue);
        CondSignal(p->QueueNotFull);
        MutexUnlock(p->PoolMutex);

        MutexLock(p->BusyThrdMutex);
        p->BusyThrdNum++;
        //做任务
        MutexUnlock(p->BusyThrdMutex);
        t->func(t->arg);

        MutexLock(p->BusyThrdMutex);
        p->BusyThrdNum--;
        MutexUnlock(p->BusyThrdMutex); 
        //销毁任务
        free(t);
    }
    return NULL;
}

//管理者线程
void * ThreadManager(void * arg)
{
    ThreadP *p = (ThreadP*)arg;
    while(p->IsClose == false)
    {
        sleep(p->SleepTime);
        MutexLock(p->PoolMutex);
        //线程多了
        if(p->BusyThrdNum * 2 <= p->threads.size)
        {
            p->MinusNum = (p->threads.size - p->BusyThrdNum)/2;
            if(p->threads.size - p->MinThrdNum < p->MinusNum)
                p->MinusNum = p-> threads.size - p->MinThrdNum;
            CondBroadcast(p->QueueNotEmpty);
        }
        //线程少了
        else if(LinkQueue_Size(&p->taskQueue) >= p->BusyThrdNum)
        {
            int addNum = LinkQueue_Size(&p->taskQueue) / 2;
            if(addNum + p->threads.size >= p->MaxThrdNum)
                addNum = p->MaxThrdNum - p->threads.size;
            for(int i = 0;i< addNum;i++)
            {
                Thread * t = ThreadInit(ThreadWork,p);
                List_InsertTail(&p->threads,t); //插入新的线程
            }
        }
        MutexUnlock(p->PoolMutex);
    }
    return NULL;
}


ThreadP *ThreadPoolInit(int MaxThrdNum, int MinThrdNum, int MaxQueueSize,int SleepTime)
{
    ThreadP * pool = (ThreadP*)malloc(sizeof(ThreadP));
    if(pool == NULL)
    {
        printf("ThreadPoolInit malloc error!\n");
        return  NULL;
    }

    List_Init(&pool -> threads);
    LinkQueue_Init(&pool->taskQueue);

    pool->PoolMutex = MutexInit();
    pool->QueueNotFull = CondInit();
    pool->QueueNotEmpty = CondInit();
    pool->BusyThrdMutex = MutexInit();

    pool->MaxQueueSize = MaxQueueSize;
    pool->MaxThrdNum = MaxThrdNum;
    pool->MinThrdNum = MinThrdNum;

    pool->BusyThrdNum = 0;
    pool->MinusNum = 0;

    pool->IsClose = false;

    for(int i = 0;i < pool->MaxThrdNum;i++)
    {
        Thread * t = ThreadInit(ThreadWork,pool);
        List_InsertTail(&pool->threads,t);
    }

    pool->manager = ThreadInit(ThreadManager,pool);
    pool->SleepTime = SleepTime;
    return pool;
}

void ThreadPoolAddTask(ThreadP *p, void *(*func)(void *), void *arg)
{
    MutexLock(p->PoolMutex);
    //任务达到上限
    while(LinkQueue_Size(&p->taskQueue) == p->MaxQueueSize)
    {
        //等待队列不满的条件
        if(!CondWait(p->QueueNotFull,p->PoolMutex))
            perror("pthread_cond_wait failed");
        if(p->IsClose == true)
        {
            MutexUnlock(p->PoolMutex);
            return;
        }
    }

    LinkQueue_Push(&p->taskQueue,CreateTask(func,arg));
    CondSignal(p->QueueNotEmpty);

    MutexUnlock(p->PoolMutex);
}

void ClearThreadPool(ThreadP *p)
{
    p->IsClose = true;

    //管理线程回收
    Thread_Join(p->manager);
    ClearThread(p->manager);

    //任务队列回收
    CondBroadcast(p->QueueNotFull);
    LinkQueue_Destroy(&p->taskQueue);

    //线程列表回收
    CondBroadcast(p->QueueNotEmpty);
    for(int i = 0; i < p->threads.size;i++)
    {
        Thread_Join((Thread*)List_FindByIndex(&p->threads,i));
    }
    List_Clear(&p->threads);

    //锁和条件变量
    ClearMutex(p->BusyThrdMutex);
    ClearMutex(p->PoolMutex);

    ClearCond(p->QueueNotEmpty);
    ClearCond(p->QueueNotFull);

    free(p);
}
