#include <iostream>
#include <forward_list>

template<typename T>
void Print(const T &v)
{
    for(auto ite = v.begin(); ite != v.end(); ite++)
    {
        std::cout << *ite <<" "; 
    }
    std::cout << std::endl;
}

int main ()
{
    std::forward_list<int> l1;
    // l.push_front(100);
    // Print(l);
    // auto ite = l.begin();
    // l.insert_after(ite,1);
    for(int i =0; i< 10; i++)
    {
        l1.push_front(i + 1);
    }
    Print(l1);
    std::forward_list<int> l2;
    for(int i =0; i< 10; i++)
    {
        l2.push_front(i + 1);
    }
    Print(l2);
    l1.merge(l2);
    Print(l1);
    return 0;
}