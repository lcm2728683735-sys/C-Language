#include "StdThread.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 线程结构体定义
struct StdThread {
    pthread_t tid;
    bool detached;
};

// 读写锁结构体定义
struct StdRwLock {
    pthread_rwlock_t rwlock;
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
    if (t == NULL || t->detached) return false;
    
    if (pthread_join(t->tid, retval) != 0) {
        perror("pthread_join failed");
        return false;
    }
    return true;
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