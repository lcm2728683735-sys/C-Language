#include <thread>
#include <atomic>   //原子量:原子性，可重入性:线程安全  只能被一个线程管理
#include <iostream>



int main ()
{
    //支持int和char   比互斥锁效率高得多
    //实现原理：把包含的变量放入寄存器中
    std::atomic<int> count = 0;
    std::thread t([&count]()
    {        
        for(int i = 0; i< 10000;i++)
            count++;
    });

    std::thread t2([&count]()
    {
        for(int i = 0;i < 10000;i++)
            count++;
    });

    t.join();
    t2.join();
    std::cout <<count << std::endl;
    return 0;
}