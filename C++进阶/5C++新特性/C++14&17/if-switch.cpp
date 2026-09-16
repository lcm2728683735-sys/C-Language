#include <iostream>

int Get()
{
    return 100;
}

int main()
{
    if(int a = Get();a>=100)
    {
        std::cout << a << std::endl;
    }
    else
    {
        std::cout << "不大于\n";
    }
}