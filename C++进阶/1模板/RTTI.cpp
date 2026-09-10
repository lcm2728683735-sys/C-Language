#include <iostream>
#include <typeinfo>
template<typename T>
void print(const T& a)
{
    if(typeid(a)==typeid(int))
        std::cout << "int :";
    if(typeid(a)==typeid(std::string))
        std::cout << "string:" ;
    std::cout << a << std::endl;
}

int main ()
{
    const std::type_info & info = typeid(int );
    std::cout<< info.name() << std::endl;
    std::cout<< info.hash_code() << std::endl;   
    return 0; 
}