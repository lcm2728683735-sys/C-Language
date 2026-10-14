#include <iostream>

class Test
{
public:
    Test(){std::cout << "构造函数!\n";}
    Test(const Test & t){std::cout << "拷贝构造函数";}
    ~Test(){std::cout << "析构函数!\n";}
};

class Derived:public Test
{

};

void func() 
{
    throw Derived();
}



int main ()
{

try
{ 
    Test t;
    func();
}
catch(...)
{
    std::cout << "捕获异常！\n";
}
    int a,b;
    std::swap(a,b);
    return 0;
}