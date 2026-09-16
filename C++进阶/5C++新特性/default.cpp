#include <iostream>


class Test
{
public:
    Test() = default;
    Test(int a){}
    Test(const Test& t) = delete;
    Test &operator=(const Test& t) = delete;
};

int main()
{
    Test t;
    Test t1 = t;
    return 0;
}