#include <iostream>
#include "StdMyString.h"

int main ()
{
    // StdMyString s;
    // std::cin>>s;
    // std::cout<<s<<std::endl;
    // s1[0]='p';
    // std::cout<<s1<<std::endl; 
    // StdMyString s = "zhangshan,lisi";
    // MyStringList list = s.split(",");
    // std::cout<<list; 

    MyStringList list1;
    list1<<"zhangsan"<<"lisi";
    MyStringList list2;
    list2<<"mike"<<"simon";
    std::cout<<(list1 + list2);
    return 0;
}