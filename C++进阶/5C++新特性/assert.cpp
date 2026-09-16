#include <iostream>
#include <cassert>
#include <exception>

int StrLen(char *s)
{
    //如果表达式不成立会终止程序
    // assert(s ! = nullptr);
    int count = 0;
    while(*(s++) != '\0')
        count++;
    return count;
}

constexpr int func()
{
    const int a = 1;
    static_assert(a != 0, "a为0");
    return 10;
}

int main ()
{
    // const char * s;
    //编译期断言
    func();
    return 0;
}