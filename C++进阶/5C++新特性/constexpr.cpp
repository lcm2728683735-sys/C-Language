#include <iostream>

constexpr int add(int n)
{
    if(n == 1 || n == 2)
        return 1;
    return add(n - 1) + add(n - 2);
}

int main ()
{
    int b = 1 + 2;
    constexpr int a = add(10);
    constexpr int c = add(9);
    return 0;
}