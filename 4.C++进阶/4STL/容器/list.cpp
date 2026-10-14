#include <iostream>
#include <list>

template<typename T>
void Print(const T &v)
{
    for(auto ite = v.begin(); ite != v.end(); ite++)
    {
        std::cout << *ite <<" "; 
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> l;
    for(int i =0; i< 10; i++)
    {
        l.push_back(i + 1);
    }
    Print(l);

    // auto ite = l.begin();
    // ite++;
    // ite++;
    // l.insert(ite,99);
    // Print(l);
    return 0; 
}