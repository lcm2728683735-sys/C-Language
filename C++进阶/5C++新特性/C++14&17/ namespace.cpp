#include <iostream>
#include <variant>
#include <string>

namespace A::B::C
{
    void func(){};
}

int main ()
{
    A::B::C::func();
    return 0;
}