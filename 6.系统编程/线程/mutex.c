#include <stdio.h>
#include <pthread.h>

int count =0;

//静态初始化
pthread_mutex_t mutex;// = PTHREAD_MUTEX_INITIALIZER;

void * handle(void * arg)
{
    int *c = (int*)arg;
    for(int i = 0;i < 90000000;i++)
    {
        //上锁：上锁失败，阻塞线程
        pthread_mutex_lock(&mutex);
        (*c)++;
        //解锁：放开锁，其他线程都可以抢锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main ()
{
    pthread_mutex_init(&mutex,NULL);

    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,handle,&count);
    pthread_create(&thread2,NULL,handle,&count);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("%d\n",count);

    //释放锁的资源
    pthread_mutex_destroy(&mutex);
    return 0;
}