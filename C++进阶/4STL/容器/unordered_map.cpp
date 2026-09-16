#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
    // std::unordered_set<int> s;
    // s.insert(2);
    // s.insert(1);
    // s.insert(3);
    // std::cout << *ite<<std::endl;
    // s.erase(1);
    // Print(s);
    std::unordered_map<int,std::string> m;
    m[1] = "zhangsan";
    m[2] = "lisi";
    m[3] = "wangwu";

    for(auto ite = m.begin(); ite != m.end();ite++)
    {
        std::cout << ite->first<< " " <<ite->second << std::endl;
    }
    return 0;
}