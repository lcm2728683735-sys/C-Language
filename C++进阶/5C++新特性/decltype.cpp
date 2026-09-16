#include <iostream>

// auto func()
// {
//     std::cout << " func " << std::endl;
//     return "hello";
// }

template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y) { // 在函数参数声明后推导类型
    return x + y;
}


int main ()
{
    //编译期推导不会调用，推导可以不需要初始化对象
    int a = 10;
    int b = 20;
    decltype(a+=b)c = a;
    return 0;
}