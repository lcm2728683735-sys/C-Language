#include <iostream>
#include <map>
#include <string>
#include <time.h>
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
    // std::pair<int,std::string> p = {1,"zhangsan"};
    // std::pair<int,std::string> p = std::make_pair(1,"zhangsan");
    // std::cout << p.first << " " << p.second; 

    // std::map<int,std::string> m;
    // m.insert({1,"zhangsan"});
    // m.insert(std::make_pair(3,"lisi"));
    // m.insert(std::pair<int,std::string>(2,"wangwu"));

    // m[4] = "zhaoliu";


    // auto ite = m.find(10);
    // if(ite == m.end())
    // {
    //     std::cout << "没找到" << std::endl;
    // }
    // else
    // {
    //     std::cout << ite->second << std::endl;
    // }
    // m.erase(m.find(1));

    // auto node = m.extract(2);
    // m.insert(std::move(node));
    // for(auto ite = m.begin(); ite != m.end(); ite++)
    // {
    //     std::cout << ite->first <<" "<<ite->second << std::endl; 
    // }
    srand(time(nullptr));
    int a[100];
    for(int i =0;i< 100;i++)
    {
        a[i] = rand() % 10 + 1;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::map<int,int> m;
    for(int i = 0;i < 100;i++)
    {
        m[a[i]]++;
    }
    auto MaxIte = m.begin();
    for(auto ite = m.begin();ite != m.end();ite++)
    {
        if(ite->second > MaxIte->second)
            MaxIte = ite;   
    }
    std::cout<< MaxIte->first<< " " << MaxIte->second << std::endl;
    return 0;
}