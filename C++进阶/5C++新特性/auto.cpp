#include <iostream>
#include <vector>
int main ()
{

    // const int a = 10;
    // auto b= 1.5;
    // auto c =a ;
    // c++;
    // std::cout << c << std::endl;

    int a[] = {1,2,3,4,5};
    std::vector<int> v = {1,2,3,4,5};
    for(auto& value:v)
    {
        std::cout << value <<std::endl;
    }

    return 0;
}