#include <iostream>

class Integer
{
public:
    explicit Integer(int a):a(a){}
    void show(){std::cout<<a<<std::endl;}
private:
    int a;
};

int main()
{
    Integer i(10);
    i.show();
    return 0;
}