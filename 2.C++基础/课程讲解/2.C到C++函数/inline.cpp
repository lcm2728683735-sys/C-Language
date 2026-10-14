#include <iostream>

inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    std::cout<<add(1,2)<<"\n";
    return 0 ;
}