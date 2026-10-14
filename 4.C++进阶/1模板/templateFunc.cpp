#include <iostream>

//模板函数
template <typename T>
T add(T a,T b)
{
    return a + b;
}

template <typename T>
void Swap(T & a,T & b)
{
    T temp = a;
    a = b;
    b = temp;
}

struct Student
{
    int id;
    std::string name;
    bool operator>(const Student& S)
    {
        return id > S.id;
    }
};
template <>
void Swap<Student>(Student& s1,Student& s2)//模板具体化
{
    int temp = s1.id;
    s1.id = s2.id;
    s2.id = temp;
}

template<typename T>
void Sort(T * a, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0;j < size - i - 1;j++)
        {
            if(a[j] > a[j+1])
            {
                Swap<T>(a[j],a[j+1]);
            }
        }
    }
}
int main()
{
    // //模板的显式调用
    // std::cout<<add<int>(1,2) <<std::endl;

    // //模板的类型推导：编译器自动推导模板类型
    // std::cout << add(1,2) << std::endl;
    Student s1 = { 1, "zhangsan"};
    Student s2 = { 2, "lisi"};
    Swap(s1,s2);
    std::cout  << s1.id << " " << s1.name << std::endl; 
    std::cout  << s2.id << " " << s2.name << std::endl; 
    return 0;
}