#include <iostream>
#include <variant>
#include <string>

int main()
{
    std::variant<int,double,std::string> v;
    v = 123;
    v = "helloworld";

    std::cout << v.index() << std::endl;
    std::cout << std::get<2>(v) << std::endl;
}