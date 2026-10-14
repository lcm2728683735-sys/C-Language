#include <iostream>

class Test
{
private:
public:
    Test(){std::cout<<"构造函数!\n";}
    ~Test(){std::cout<<"析构函数!\n";}
    void show()
    {
        std::cout<<"helloworld\n";
    }

};

class SmartPoint
{
private:Test *t;
public:
    SmartPoint(Test *t):t(t){}
    ~SmartPoint()
    {
        delete t;
    }
    Test* operator->()
    {
        return t;
    }
    Test& operator *()
    {
        return *t;
    }
};

int main()
{
    SmartPoint p(new Test);
    (*p).show();
    return 0;
}