#include <iostream>

void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int& func()
{
    static int a = 10;
    return a;
}

void func(const int &a)
{
    std::cout<<a<<std::endl;
}

int main()
{ 
    // int b = 20;
    // Swap(&a,&b);
    // int&a = b;
    // a=20;
    // std::cout<<"a="<<a<<" b="<<b<<std::endl;
    // std::cout<<"b = "<<b<<std::endl;

 
    const int &a = func();
    return 0;
}