#include <iostream>

class Func
{
public:
    int operator()(int a,int b)
    {
        return a + b;
    }
};

int add(int a,int b) 
{
    return a+b ;
}

int minus(int a, int b)
{
    return a-b;
}

void func (int (*ptr)(int,int),int a,int b)
{
    std::cout << ptr(a,b) << std::endl;
}

int main()
{
    Func f;
    std::cout<<f(1,2)<<"\n"<<std::endl;
    return 0;
}