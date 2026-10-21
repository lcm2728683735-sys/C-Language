#include <stdio.h>
#include <pthread.h>
#include <SysHeader.h>

#include <semaphore.h> //线程信号量

sem_t sem1,sem2,sem3;

void * handle1(void * arg)
{
    while(1)
    {
        sem_wait(&sem1);
        printf("A\n");
        sleep(1);
        sem_post(&sem2);
    }
    return NULL;
}

void * handle2(void * arg)
{
    while(1)
    {
        sem_wait(&sem2);
        printf("B\n");
        sleep(1);
        sem_post(&sem3); 
    }
    return NULL;
}

void * handle3(void * arg)
{
    while(1)
    {
        sem_wait(&sem3);
        printf("C\n");
        sleep(1);
        sem_post(&sem1);
    }
    return NULL;
}

int main ()
{
    //初始化信号量
    //pshared：1进程信号量共享 0： 线程信号量共享
    //unsigned int value初始值：1：实现互斥锁，初始状态下资源可用
    //设为0：表示初始状态下没有任何资源
    sem_init(&sem1,0,1);
    sem_init(&sem2,0,0);
    sem_init(&sem3,0,0);

    pthread_t thread1,thread2,thread3;
    pthread_create(&thread1,NULL,handle1,NULL);
    pthread_create(&thread2,NULL,handle2,NULL);
    pthread_create(&thread2,NULL,handle3,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);

    return 0;
}