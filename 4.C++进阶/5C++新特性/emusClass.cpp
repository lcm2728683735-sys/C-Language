#include <iostream>

enum class color:char //选择底层类型
{
    white,
    black
};

enum class thickness:char
{
    fat,
    thin
};

int main ()
{
    //   if(color::white == thickness::fat)
    //   {
    //     std::cout << "相等" << std::endl;
    //   }
    return 0;
}
