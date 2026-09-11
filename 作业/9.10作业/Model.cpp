#include <iostream>
#include <string>
#include <sstream>

// template <typename T>
// void show(const T& name)
// {
    // std::string name1 = static_cast<T>(name1);
//     std::string s(name);
//     std::cout<<s<<std::endl;                                   
// };


// template <>
// void show<char*>(const char& *name)
// {       
//     if(name == nullptr)
//     {
//         std::cout<< "nullptr!"<<std::endl;
//         return;
//     }
//     std::string s(name);
//     std::cout<< s <<std::endl;
// };

struct UserInfo
{
public:
    
    friend std::ostream& operator<<(std::ostream &os, const UserInfo &a);
private:
    int id;
    std::string name;
};


std::ostream& operator<<(std::ostream &os, const UserInfo &a)
{
    os << "id :"<< a.id << "Name" << a.name ;
    return os;
}

template<typename T>
std::string show(const T& t)
{
    std::cout << t << std::endl;
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template<>
std::string show<char*>(char* const & t)
{
    if(t == nullptr)
    {
        std::cout<< "nullptr!"<<std::endl;
        return "";
    }
    std::string a = static_cast<char*>(t);
    std::cout << t << std::endl;
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

int main ()
{
    show<double>(1.131);
    show<int>(2.0);
    char a[10]  = "asdasdaf";
    char *b = nullptr;
    show<char*>(a);
    show<char*>(b);
    return 0;
}