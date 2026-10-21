#include <iostream>
#include <thread>

void run ()
{
    std::cout << "helloworld\n";
}


int main ()
{
    //初始化对象线程T
    //参数：1可调用对象2可变参数模板
    //可调用对象：1.指针函数2.仿函数3.lambda表达式
    std::thread t(run);
    // t.detach();
    // std::cout << t.get_id()<< std::endl;
    // std::cout << t.hardware_concurrency()<< std::endl;

    std::thread t2 = std::move(t);

    std::cout << t2.joinable() << std::endl;
    std::cout << t.joinable() << std::endl;


    //布尔判断
    // if(t.joinable())
    //     t.join();
    return 0;
}