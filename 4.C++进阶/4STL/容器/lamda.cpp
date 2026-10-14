#include <iostream>



int main ()
{
    int c= 10;
    auto f =[c](int a,int b)
    {
        return a+b+c;
    };
    std::cout<<f(1,2)<<std::endl;
    return 0;
}