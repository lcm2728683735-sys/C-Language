#include <iostream>
#include <any>
#include <exception>
class Test
{};

template<typename T>
T TypeCast(const std::any & a)
{
    try
    {
        T b = std::any_cast<T>(a);
        return b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return T();
    }
}

int main ()
{
    std::any a = 1;
    int b = TypeCast<double>(a);
    std::cout << b << std::endl;
    return 0;
}