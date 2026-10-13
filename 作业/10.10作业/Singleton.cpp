#include <iostream>

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        if(instance == nullptr)
        {
            instance = new Singleton;
        }
        return instance;
    }
    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton(){}
    static Singleton *instance;
};

Singleton *Singleton::instance = nullptr;

int main()
{
    auto obj1 = Singleton::GetInstance();
    auto obj2 = Singleton::GetInstance();

    std::cout << "地址1:" << obj1 <<std::endl;
    std::cout << "地址2:" << obj2 <<std::endl;
    if(obj1 == obj2)
    {
        std::cout << "两个指针指向同一个实例" << std::endl;
    }
    return 0;
}