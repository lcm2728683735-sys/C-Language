#include "StdRWMutex.h"
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <shared_mutex>

int count = 0;

StdRWMutex m;

std::shared_mutex sm;

void Read(int id)
{
    while(1)
    {
    // m.ReadLock();
    std::shared_lock<std::shared_mutex> lock(sm);
    std::cout << "读线程" << id << "读count:"<< count <<std::endl;
    m.ReadUnlock();
    sleep(1);
    }
}

void Write(int id)
{
    while(1)
    {
    // m.WriteLock();
    //独占形式上锁
    std::unique_lock<std::shared_mutex> lock(sm);
    count++;
    std::cout << "写线程" << id << "写入count:"<< count <<std::endl;
    // m.WriteUnlock();
    // sleep(3);
    }
}

int main()
{
    int pnum = 3;
    int cnum = 3;
    std::vector<std::thread> producers(pnum);
    std::vector<std::thread> costumers(cnum);
    for(int i = 0; i< pnum ; i++)
    {
        producers[i] = std::thread(Read,i);
    }

    for(int i = 0; i< cnum ; i++)
    {
        costumers[i] = std::thread(Write,i);
    }
    for(auto &t : producers)
    {
        t.join();
    }
    for(auto &t : costumers)
    {
        t.join();
    }
    return 0;

    return 0;

}