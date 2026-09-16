#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <algorithm>

void BubbleSort(std::vector<int> & v)
{
    for(int i = 0;i < v.size() - 1; i++)
    {
        for(int j= 0 ;j< v.size() - i - 1; j++)
        {
            if(v[j]>v[j+1])
            {
                std::swap(v[j],v[j+1]);
            }
        }
    }
}

class Timer
{
public:
    void Start()
    {
        start = std::chrono::steady_clock::now();
    }
    void Stop()
    {
        end = std::chrono::steady_clock::now();
    }
    long GetDuration()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
};


int main()
{
    // while (1)
    // {
    //     sleep(1);
    //     time_t t = time(nullptr);
    //     tm *m = localtime(&t);
    //     // std::cout<<m->tm_year + 1900<<"年" <<m->tm_mon + 1<<"月" <<m->tm_mday<<"日"
    //     //         <<m->tm_hour<<"时" <<m->tm_min<<"分" <<m->tm_sec<<"秒"<<std::endl;

    //     printf("%d年%d月%d日%d时%d分%d秒\r", m->tm_year + 1900, m->tm_mon,
    //            m->tm_mday, m->tm_hour, m->tm_min, m->tm_sec);
    //     fflush(stdout);//刷新输出缓冲区
    // }
    // auto time = std::chrono::system_clock::now();
    // auto t = time.time_since_epoch().count()/1000;
        // std::cout << ctime(&t) << std::endl;
    // clock:时钟
    // time_point : 时间点
    // duration : 时间间隔
    // 系统时钟：系统时间
    //std::chrono::system_clock
    // 系统开机运行的时间
    //std::chrono::steady_clock
    //高精度时钟
    //std::chrono::high_resolution_clock

    std::vector<int> v;
    for(int i = 0; i < 10000;i++)
    {
        v.push_back(rand() % 100000 + 1);
    }

    std::vector<int> v2 = v;

    Timer t;
    t.Start();
    std::sort(v.begin(),v.end());
    t.Stop();
    std::cout << t.GetDuration() << std::endl;
    
    t.Start();
    BubbleSort(v2);
    t.Stop();
    std::cout << t.GetDuration() << std::endl;
    return 0;
}