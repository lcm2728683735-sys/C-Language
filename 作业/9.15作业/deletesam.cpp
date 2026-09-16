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
void DeleteSam(T &v)
{
    for(auto ite = v.begin(); ite != v.end();)
    {
        if(ite + 1 != v.end() &&*ite == *(ite+1))
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
    std::vector<int> v = {1, 1, 2, 2, 2, 3, 4, 4, 5 ,5};
    DeleteSam(v);
    Print(v);
    return 0;
}