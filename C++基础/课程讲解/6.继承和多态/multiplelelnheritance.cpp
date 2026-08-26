#include <iostream>

class UltraBase
{
protected:int c;
public:
    UltraBase(int c):c(c){};
};

class Base1:virtual public UltraBase
{
protected:
    int a;
public:
    Base1(int c,int a):UltraBase(c),a(a){std::cout<<"Base1\n";}
    void show()
    {
        std::cout<<"a:"<<a<<std::endl;
    }
};

class Base2:virtual UltraBase
{
protected:
    int b;
public:
    Base2(int c,int b):UltraBase(c),b(b){std::cout<<"Base2\n";}
    void show()
    {
        std::cout<<"b:"<<b<<std::endl;
    }
};

class Derived:public Base1,public Base2
{
public:
    Derived(int a,int b):UltraBase(c),Base1(c,b),Base2(c,a)
    {

    }
    void show()
    {
        Base1::show;
        Base2::show;
        std::cout<<"c:"<<c<<std::endl;
    }
};

int main()
{
    return 0;
}