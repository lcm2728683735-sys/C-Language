#include <iostream>
#include <deque>

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
    std::deque<int> d;
    for(int i = 0;i < 10; i++)
    {
        d.push_back(i+1);
    }
    for(int i = 0;i < 10; i++)
    {
        d.push_front(i+1);
    }
    Print(d);
    d.pop_front();
    Print(d);
    return 0;
}
