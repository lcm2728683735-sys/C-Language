#ifndef STD_THREAD_H
#define STD_THREAD_H

#include <pthread.h>
#include <stdbool.h>

// 前向声明不透明结构体
typedef struct StdThread Thread;
typedef struct StdRwLock StdRwLock;

// 1. 线程核心接口
Thread* ThreadInit(void* (*func)(void*), void *arg);
bool ThreadJoin(Thread *t, void **retval);
bool ThreadDetach(Thread *t);
bool ThreadCancel(Thread *t);
void ClearThread(Thread *t);

// 2. 读写锁接口
StdRwLock* RwLockInit(void);
void RwLockRlock(StdRwLock *lock);   // 加读锁
void RwLockWlock(StdRwLock *lock);   // 加写锁
void RwLockUnlock(StdRwLock *lock);  // 解锁
void ClearRwLock(StdRwLock *lock);

#endif // STD_THREAD_H