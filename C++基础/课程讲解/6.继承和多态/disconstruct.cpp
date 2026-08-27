#include <iostream>

class Base 
{
public:
    Base()
    {
        std::cout<<"父类构造\n";
        a = new int;
    }
    virtual ~Base()
    {
        std::cout<<"父类析构\n";
        delete a;
    }
private:
    int *a;
};

class Derived:public Base
{
public:
    Derived():Base()
    {
        std::cout<<"子类构造\n";
        b = new int ;
    }
    ~Derived()
    {
        std::cout<<"子类析构\n";
        delete b;
    }
private:
    int *b;
};

int main()
{
    Base *d = new Derived;
    delete d;
    return 0;
}