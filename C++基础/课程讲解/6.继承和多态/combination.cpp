#include <iostream>

class Base1
{
protected:
    int a;
public:
    Base1(int a):a(a){std::cout<<"Base1\n";}
    void show()
    {
        std::cout<<"a:"<<a<<std::endl;
    }
};

class Base2
{
protected:
    int b;
public:
    Base2(int b):b(b){std::cout<<"Base2\n";}
    void show()
    {
        std::cout<<"b:"<<b<<std::endl;
    }
};

class Derived:public Base2
{
private:
Base1 b1;
public:
    Derived(int a,int b):b1(a),Base2(b){}
    void show()
    {
        b1.show();
        Base2::show();
    }
};

int main()
{
    Derived d(1,2);
    d.show();
    return 0;
}