#include "StdRWMutex.h"

StdRWMutex::StdRWMutex():isWrite(false),ReadNums(0),WaitWriteNums(0)
{
}

void StdRWMutex::ReadLock()
{
    std::unique_lock<std::mutex> lock(m);
    while(isWrite == true)   //有线程在写 ,等待读的条件变量
    {
        readCond.wait(lock);
    }
    ReadNums++;
}

void StdRWMutex::ReadUnlock()
{
    std::unique_lock<std::mutex> lock(m);
    ReadNums--;
    if(ReadNums == 0)
    {
        writeCond.notify_all();
    }
}

void StdRWMutex::WriteLock()
{
    std::unique_lock<std::mutex> lock(m);
    while(isWrite == true || ReadNums > 0)
    {
        WaitWriteNums++;
        writeCond.wait(lock);
    }
    WaitWriteNums--;
    isWrite = true;
}

void StdRWMutex::WriteUnlock()
{
    std::unique_lock<std::mutex> lock(m);
    isWrite = false;
    if(WaitWriteNums > 0)
    {
        writeCond.notify_all();
    }
    else
    {
        readCond.notify_all();
    }
}
