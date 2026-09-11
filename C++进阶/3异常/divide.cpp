#include <iostream>

int divide(int a,int b)
{
    if(b == 0)
        throw 0;
    return a/b;
}

int main ()
{
    try//尝试运行
    {
        std::cout << divide(3 ,1) << std::endl;


        
    }
    //根据异常的类型捕获
    catch(int & a)//捕获某类异常
    {
        //异常处理
        std::cout << "除0异常！ \n";
    }
    catch(...)
    {
        std::cout << "其他异常！\n";
    }
    return 0;
}