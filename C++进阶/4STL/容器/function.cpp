#include <iostream>
#include <functional>

void Print()
{
    std::cout << "helloworld\n";
}

class test
{
public:
    void operator()()
    {
        std::cout << "仿函数！\n";
    }
}; 
int main()
{
    std::function<void()>f = []()
    {std::cout << "lambda!\n";};
    f();
    return 0;
}