#include <iostream>


class Base
{
public:
    static int GetNum()
    {
        return a;
    }

    static void add()
    {
        a++;
    }
protected:
    static int a;
};

int Base::a = 0;

class Derived:public Base
{
public:
    static int GetNum()
    {
        return a;
    }
private:
    static int a;
};

int Derived::a = 10;

int main()
{
    Derived d;
    Base::add();
    std::cout<<d.GetNum()<<std::endl;
    d.add();
    std::cout<<Base::GetNum()<<std::endl;
    std::cout<<d.GetNum()<<std::endl;
    return 0;
}