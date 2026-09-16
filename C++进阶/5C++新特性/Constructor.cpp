#include <iostream>
#include <memory>
class Test
{
public:
    Test(){}
    Test(int a):a(std::make_shared<int>(a)){}
    //委托构造：用已有的构造函数构建新的构造函数
    Test(int a,char b):Test(a)
    {
        this->b =b;
    }
    Test(int a,char b,double c):Test(a,b)
    {
        this->c = c;
    }
private:
    std::shared_ptr<int> a;
    char b;
    double c;
};

class Derived:public Test
{
public:
    using Test::Test; //继承父类的构造函数
};

int main()
{
    Derived d(1);
    return 0;
}