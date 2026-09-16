#include <iostream>

void print(int& a)
{
    std::cout << "左值引用" << std::endl;
    std::cout << a << std::endl;
}

void print(int&& a)
{
    std::cout << "右值引用" << std::endl;
    std::cout << a << std::endl;
}

template <typename T>
void func(T&& a)//万能引用： 模板 + && 既能接左值又能接右值
{
    //万能引用默认会当成左值
    print(std::forward<T>(a));
    //完美转发：保持原有的左右值属性
}


int main()
{
    int a = 10;
    func(a);
    func(10);
    return 0;
}