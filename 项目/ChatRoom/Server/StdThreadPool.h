#ifndef STDTHREADPOOL_H__
#define STDTHREADPOOL_H__

struct StdThreadPool;
typedef struct StdThreadPool ThreadP;

ThreadP * ThreadPoolInit(int MaxThrdNum,int MinThrdNum,int MaxQueueSize,int SleepTime);
void ThreadPoolAddTask(ThreadP *p,void*(*func)(void *),void * arg);
void ClearThreadPool(ThreadP* p);

#endif