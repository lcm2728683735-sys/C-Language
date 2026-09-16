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

int main()
{
    std::vector<int> v = {1,2,3,4};
    Print(v);

    // v.insert(v.begin() + 2,99);
    // Print(v);
    // v.erase(v.begin()+ 2);
    // Print(v);
    // std::vector<int>::iterator
    // auto ite = v.begin();    
    //容器的头部迭代器 指向容器的第一个元素
    // std::cout << *ite << std::endl;
    //自动类型推导，必须初始化
    // auto ite_end = v.end();
    // std::cout << *ite_end << std::endl;
    //容器的尾部迭代器，指向容器的最后一个元素的下一个
    // v.push_back(1);//尾插
    // v.pop_back();//尾删
    // std::cout << v.capacity() << std::endl;
    // std::cout << v.size() << std::endl;

    // for(auto ite = v.begin();ite != v.end();ite++)
    // {
    //     if(*ite == 99)
    //     {
             //元素被删除迭代器失效
    //         ite = v.erase(ite);
    //     }
    //     else
    //     {
    //         ite++;
    //     }
    // }
    v.at(10);//抛出越界异常;
    v.resize(20);
    v.shrink_to_fit();//缩减内存到size
    std::cout<< v.capacity() << std::endl;
    return 0;
}