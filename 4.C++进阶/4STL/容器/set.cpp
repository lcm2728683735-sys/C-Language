#include <iostream>
#include <set>
#include <string>
template<typename T>
void Print(const T &v)
{
    for(auto ite = v.begin(); ite != v.end(); ite++)
    {
        std::cout << *ite <<" "; 
    }
    std::cout << std::endl;
}

struct Student
{
    int id;
    std::string name;
};

bool operator<(const Student &s1,const Student &s2)
{
    return s1.id < s2.id;
}
bool operator>(const Student &s1,const Student &s2)
{
    return s1.id > s2.id;
}

std::ostream& operator<<(std::ostream& os,const Student &s)
{
    os<<s.id << " " << s.name << std::endl;
    return os;
}

int main()
{
    // int a[] = {5,3,1,4,2};
    // std::set<int> s;
    // for(int i = 0;i < 5;i++)
    // {
    //     s.insert(a[i]);
    // }
    // auto ite = s.find(1);
    // if(ite != s.end())
    //     s.erase(ite);
    // Print(s);

    std::set<Student,std::greater<Student>> s;
    s.insert({1,"zhangsan"});
    s.insert({2,"lisi"});
    Print(s);
    return 0;
}