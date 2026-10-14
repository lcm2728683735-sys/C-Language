#include <iostream>
#include <exception>

class MyException:public std::exception   
{
public:
    virtual const char *what() const noexcept
    {
        return "这是我的自定义异常";
    }
};

void func()
{
    throw MyException();
}

int main()
{
    try
    {
        func();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}