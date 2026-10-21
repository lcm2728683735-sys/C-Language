#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <vector>

const int MaxSize = 5;
int buffer[MaxSize]; //数据缓冲区
int count = 0; //缓冲区数据数量

std::mutex m;
std::condition_variable notFull;
std::condition_variable notEmpty;
void producer(int id)
{
    while(1)
    {
        std::unique_lock<std::mutex> lock(m);
        while(count == MaxSize)
        {
            notFull.wait(lock);
        }
        int num = rand()% 100;//生成一个随机数
        buffer[count++] = num;
        std::cout << "生产者" << id <<"放入一个数据："<< num <<std::endl;
        notEmpty.notify_one();
        sleep(rand() % 3);
    }
}


//消费者
void costumer(int id)
{
    while(1)
    {
        std::unique_lock<std::mutex> lock(m);
        while(count == 0)
        {
            notEmpty.wait(lock);
        }
        count--;
        std::cout<<"消费者" << id <<"消费了数据:count:" <<count<<"num :"  << buffer[count] << std::endl;
        notFull.notify_one();
        sleep(rand() % 3);
    }
}

int main ()
{
    int pnum = 2;
    int cnum = 2;
    std::vector<std::thread> producers(2);
    std::vector<std::thread> costumers(2);
    for(int i = 0; i< pnum ; i++)
    {
        producers[i] = std::thread(producer,i);
    }

    for(int i = 0; i< cnum ; i++)
    {
        costumers[i] = std::thread(costumer,i);
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
}