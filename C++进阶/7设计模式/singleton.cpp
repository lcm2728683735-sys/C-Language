#include <iostream>

//懒汉式：对象在调用时进行构建
//饿汉式：程序开始时就构建

// class Singleton
// {
// public:
//     static Singleton* GetInstance()
//     {
//         if(instance == nullptr)
//         {
//             instance = new Singleton;
//         }
//     }
//     void show()
//     {
//         std::cout<<"helloworld\n";
//     }
//     return instance;
// private:
//     Singleton(){}//构造函数私有化
//     static Singleton *instance;
// };

// Singleton *Singleton::instance = nullptr;

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        return instance;
    }
    void show()
    {
        std::cout<<"helloworld\n";
    }
private:
    Singleton(){}//构造函数私有化
    static Singleton *instance;
};

Singleton *Singleton::instance = new Singleton;



int main()
{
    auto obj = Singleton::GetInstance();
    return 0;
}