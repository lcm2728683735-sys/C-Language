#include <iostream>

class Base
{
protected:
    int a;
public:
    virtual void show()
    {
        std::cout<<"Base"<<a<<std::endl;
    }
};

class Derived1:public Base
{
public:
    void show()
    {
        std::cout<<"Derived1"<<std::endl;
    }
};

class Derived2:public Base
{
public:
    void show()
    {
        std::cout<<"Derived2"<<std::endl;
    }
};

int main()
{
    //向上转型 
    Base* a[2];
    a[0]= new Derived1;
    a[1]= new Derived2;
    for(int i = 0;i<2;i++)
    {
        a[i]->show();
    }
    return 0;
}