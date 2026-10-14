#include <iostream>

class Test
{
public:
    Test() = default;
    Test(int a) {}
    
    // 1. 声明虚析构函数，确保 delete 基类指针时能正确调用子类析构函数
    virtual ~Test() = default;

    // 2. 声明虚函数，给子类提供覆盖（override）的接口
    virtual void show() 
    {
        std::cout << "Test Base" << std::endl;
    }

    Test(const Test& t) = delete;
    Test &operator=(const Test& t) = delete;
};

class Derived : public Test
{
public:
    // 覆盖基类的虚函数
    void show() override
    {
        std::cout << "Derived show" << std::endl;
    }
};

int main()
{
    Test *t = new Derived();
    
    t->show(); // 正确触发多态，输出 "Derived show"
    
    delete t;  // 释放内存（需配合 virtual ~Test()）
    return 0;
}