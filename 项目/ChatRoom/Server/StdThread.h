#ifndef STD_THREAD_H
#define STD_THREAD_H

#include <pthread.h>
#include <stdbool.h>

// 前向声明不透明结构体
typedef struct StdThread Thread;
typedef struct StdRwLock StdRwLock;
typedef struct StdMutex StdMutex;
typedef struct StdCond Cond;
extern Cond *queueNotFull;
// 1. 线程核心接口
Thread* ThreadInit(void* (*func)(void*), void *arg);
bool ThreadJoin(Thread *t, void **retval);
bool ThreadDetach(Thread *t);
bool ThreadCancel(Thread *t);
void ThreadExit();
bool IsCurrentThread(Thread * t);
void ClearThread(Thread *t);
void Thread_Join(Thread *t);

//互斥锁接口
StdMutex *MutexInit(void);
bool MutexLock(StdMutex *mutex);
bool MutexUnlock(StdMutex *mutex);
void ClearMutex(StdMutex *mutex);
// 2. 读写锁接口
StdRwLock* RwLockInit(void);
void RwLockRlock(StdRwLock *lock);   // 加读锁
void RwLockWlock(StdRwLock *lock);   // 加写锁
void RwLockUnlock(StdRwLock *lock);  // 解锁
void ClearRwLock(StdRwLock *lock);

//线程池
// struct StdThreadPool;
// typedef struct StdThreadPool ThreadP;

//环境变量
Cond* CondInit(void);
bool CondWait(Cond *cond, StdMutex *mutex) ;
void CondSignal(Cond *cond) ;
void CondBroadcast(Cond *cond);
void ClearCond(Cond *cond);


#endif 