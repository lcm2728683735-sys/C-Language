#include <iostream>

class Base
{
private:
public:
    virtual void show()
    {
        std::cout<<"Base"<<std::endl;
    }

};

class Derived:public Base
{
public:
    void show()
    {
        std::cout<<"Derived"<<std::endl;
    }
};

int main()
{
    Base *b = new Derived;
    b->show();
    return 0;
}
