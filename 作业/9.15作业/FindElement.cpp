#include <iostream>
#include <vector>

template<typename T>
void Print(const T &v)
{
    for(auto ite = v.begin(); ite != v.end(); ite++)
    {
        std::cout << *ite <<" "; 
    }
    std::cout << std::endl;
}

template<typename T>
void FindElement(T &v,const auto num)
{
    for(auto ite = v.begin(); ite != v.end(); ite++)
    {
        ite = v.erase(v.find())
        *ite = num;
    }
    std::cout << std::endl;
}

int main ()
{
    std::vector<int> v = {10, 20, 30, 40, 50};
    FindElement(v,30);
    Print(v);
    return 0;
}