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
void DeleteDouble(T &v)
{
    for(auto ite = v.begin(); ite != v.end();)
    {
        if(*ite % 2 ==0)
        {
            ite = v.erase(ite);
        }
        else
        {
            ++ite;
        }
    }
}

int main ()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    DeleteDouble(v);
    Print(v);
    return 0;
}