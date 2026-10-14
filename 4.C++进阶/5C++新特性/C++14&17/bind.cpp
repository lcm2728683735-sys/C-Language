#include <iostream>
#include <map>

std::pair<int,std::string> func()
{
    return {1,"zhangsan"};
}

struct Test
{
    int x;
    char b;
    double c;
};

int main()
{
    std::map<int,std::string> m = 
    {
        {1,"zhangsan"},
        {2,"wangwu"}
    };

    Test t = {1,'a',3.14};
    auto[a,b,c] = t;
    std::cout << a << " " << b<<" "<< c<< std::endl;
    a=100;
    std::cout <<t.x<<std::endl;
    return 0;
}