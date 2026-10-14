#include <iostream>
#include <functional>
#include <map>
int add(int a,int b,int c)
{
    return a + b;
}

int minus(int a , int b)
{
    return a - b;
}

int multiply(int a , int b)
{
    return a * b;
}

int divide (int a, int b)
{
    return  a/ b;
}
//std::map    红黑树映射器将char类型的字符作为值储存   
//std::function函数包装器 表示接受两个int，返回一个int
std::map<char,std::function<int(int,int)>> m;//注册机

int calculate(int a,int b,char symbol)
{
    return m[symbol](a,b);
}


int main()
{
    //适配器：将原有逻辑改变转换成新的逻辑
    //函数绑定器
    //std::placeholders::_1 占位符
    // auto f = std::bind(add,std::placeholders::_1,std::placeholders::_2,0);
    auto f = [](int a,int b){return add(a,b,0);};
    m['+'] = f;
    m['-'] = minus;
    m['*'] = multiply;
    m['/'] = divide;

    std::cout << calculate(1,2,'+') << std::endl;
}
