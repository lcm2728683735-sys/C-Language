#include "StdThread.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "List.h"


// 线程结构体定义
struct StdThread 
{
    pthread_t tid;
    bool detached;
};

struct StdMutex 
{
    pthread_mutex_t mutex;
};
// 读写锁结构体定义
struct StdRwLock 
{
    pthread_rwlock_t rwlock;
};

//环境变量
struct StdCond 
{
    pthread_cond_t cond;
};

// 1. 初始化并启动线程
Thread* ThreadInit(void* (*func)(void*), void *arg) {
    Thread *t = (Thread*)malloc(sizeof(Thread));
    if (t == NULL) {
        perror("Thread malloc failed");
        return NULL;
    }

    t->detached = false;
    if (pthread_create(&t->tid, NULL, func, arg) != 0) {
        perror("pthread_create failed");
        free(t);
        return NULL;
    }

    return t;
}

// 2. 等待线程结束（回收资源）
bool ThreadJoin(Thread *t, void **retval) {
    if (t == NULL || t->detached) 
        return false;
    
    if (pthread_join(t->tid, retval) != 0) {
        perror("pthread_join failed");
        return false;
    }
    return true;
}


void Thread_Join(Thread *t) 
{
    if (t == NULL) {
        return;
    }

    // 如果线程既没有被 Detach，也没有结束，就等待它结束
    if (!t->detached) {
        if (pthread_join(t->tid, NULL) != 0) {
            perror("pthread_join failed");
        }
    }
}


// 3. 设置线程分离（自动回收）
bool ThreadDetach(Thread *t) {
    if (t == NULL || t->detached) return false;

    if (pthread_detach(t->tid) != 0) {
        perror("pthread_detach failed");
        return false;
    }
    t->detached = true;
    return true;
}

// 4. 取消线程
bool ThreadCancel(Thread *t) {
    if (t == NULL) return false;

    if (pthread_cancel(t->tid) != 0) {
        perror("pthread_cancel failed");
        return false;
    }
    return true;
}

// 5. 释放线程包装对象内存
void ClearThread(Thread *t) {
    if (t == NULL) return;
    // 注意：如果线程既没有 Join 也没有 Detach，直接 free 可能导致资源泄漏，
    // 但通常由使用者保证生命周期或配合 Detach 使用。
    free(t);
}


//==========================互斥锁实现====================================

// 初始化互斥锁
StdMutex *MutexInit(void)
{
    StdMutex *mutex = (StdMutex *)malloc(sizeof(StdMutex));
    if (mutex == NULL) {
        perror("malloc mutex");
        return NULL;
    }

    int ret = pthread_mutex_init(&mutex->mutex, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_mutex_init failed: %s\n", strerror(ret));
        free(mutex);
        return NULL;
    }

    return mutex;
}

// 加锁
bool MutexLock(StdMutex *mutex)
{
    if (mutex == NULL) {
        return false;
    }

    int ret = pthread_mutex_lock(&mutex->mutex);
    if (ret != 0) {
        fprintf(stderr, "pthread_mutex_lock failed: %s\n", strerror(ret));
        return false;
    }

    return true;
}

// 解锁
bool MutexUnlock(StdMutex *mutex)
{
    if (mutex == NULL) {
        return false;
    }

    int ret = pthread_mutex_unlock(&mutex->mutex);
    if (ret != 0) {
        fprintf(stderr, "pthread_mutex_unlock failed: %s\n", strerror(ret));
        return false;
    }

    return true;
}

// 销毁互斥锁
void ClearMutex(StdMutex *mutex)
{
    if (mutex == NULL) {
        return;
    }

    int ret = pthread_mutex_destroy(&mutex->mutex);
    if (ret != 0) {
        fprintf(stderr, "pthread_mutex_destroy failed: %s\n", strerror(ret));
        return;
    }

    free(mutex);
}



// ================= 读写锁实现 =================

StdRwLock* RwLockInit(void) {
    StdRwLock *lock = (StdRwLock*)malloc(sizeof(StdRwLock));
    if (lock == NULL) {
        perror("RwLock malloc failed");
        return NULL;
    }

    if (pthread_rwlock_init(&lock->rwlock, NULL) != 0) {
        perror("pthread_rwlock_init failed");
        free(lock);
        return NULL;
    }

    return lock;
}

void RwLockRlock(StdRwLock *lock) {
    if (lock != NULL) {
        pthread_rwlock_rdlock(&lock->rwlock);
    }
}

void RwLockWlock(StdRwLock *lock) {
    if (lock != NULL) {
        pthread_rwlock_wrlock(&lock->rwlock);
    }
}

void RwLockUnlock(StdRwLock *lock) {
    if (lock != NULL) {
        pthread_rwlock_unlock(&lock->rwlock);
    }
}

void ClearRwLock(StdRwLock *lock) {
    if (lock == NULL) return;
    pthread_rwlock_destroy(&lock->rwlock);
    free(lock);
}

Cond* CondInit(void) 
{
    Cond *c = (Cond*)malloc(sizeof(Cond));
    if (c == NULL) {
        perror("Cond malloc failed");
        return NULL;
    }

    if (pthread_cond_init(&c->cond, NULL) != 0) {
        perror("pthread_cond_init failed");
        free(c);
        return NULL;
    }
    return c;
}

bool CondWait(Cond *cond, StdMutex *mutex)
{
    if (cond == NULL || mutex == NULL) {
        return false;
    }

    int ret = pthread_cond_wait(&cond->cond, &mutex->mutex);

    if (ret != 0) {
        fprintf(stderr, "pthread_cond_wait failed: %s\n",
                strerror(ret));
        return false;
    }

    return true;
}

void CondSignal(Cond *cond) {
    if (cond != NULL) {
        pthread_cond_signal(&cond->cond);
    }
}

void CondBroadcast(Cond *cond) {
    if (cond != NULL) {
        pthread_cond_broadcast(&cond->cond);
    }
}

void ClearCond(Cond *cond) {
    if (cond == NULL) return;
    pthread_cond_destroy(&cond->cond);
    free(cond);
}

void ThreadExit()
{
    pthread_exit(NULL);
}

bool IsCurrentThread(Thread *t)
{
    return t->tid == pthread_self();
}

