#include <stdio.h>
#include <pthread.h>
#include <SysHeader.h>
void* ThreadHandle(void *arg)
{
    long num = (long)arg;
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    while (1)
    {
        printf("我是%ld线程!\n",num);
        sleep(1);
        //线程的退出
        // pthread_exit(-1);
    }
    return NULL;
}
int main ()
{
    //int pthread_create(pthread_t *__restrict__ __newthread, 
    //const pthread_attr_t *__restrict__ __attr, 
    //void *(*__start_routine)(void *), void *__restrict__ __arg)
    pthread_t thread1,thread2;

    //并发任务：多个线程同时执行任务
    pthread_create(&thread1,NULL,ThreadHandle,(void*)(1));
    // pthread_create(&thread2,NULL,ThreadHandle,(void*)(2));

    //线程分离   join:可结合态：pthread_join调用之后,才会释放资源
    // pthread_detach(thread1);
    sleep(3);
    //线程的等待

    //取消某个线程
    pthread_cancel(thread1);
    if(pthread_join(&thread1,NULL)!= 0)
    {
        printf("pthread join error\n");
        return -1;
    }
    // pthread_join(&thread2,NULL);

    //while(1)阻塞了进程
    // while(1);
    return 0;
}