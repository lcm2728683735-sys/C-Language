#ifndef __STDRWMUTEX_H__
#define __STDRWMUTEX_H__

#include <mutex>
#include <condition_variable>

class StdRWMutex
{
public:
    StdRWMutex();
    ~StdRWMutex() = default;
    //读锁
    void ReadLock();
    void ReadUnlock();
    void WriteLock();
    void WriteUnlock();

private:
    std::mutex m;
    bool isWrite;
    int ReadNums;//在读的线程数量
    int WaitWriteNums;//等待写的线程数量
    std::condition_variable readCond;
    std::condition_variable writeCond;
};



#endif