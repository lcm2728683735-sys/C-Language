#include <iostream>

class USB
{
public:
    virtual void showUSB()
    {
        std::cout<<"USB接口"<< std::endl;
    }
};

class TypeC
{
public:
    virtual void showTypeC()
    {
        std::cout<<"TypeC接口"<< std::endl;
    }
};
//类适配器:多继承
// class Adapter:public USB,public TypeC
// {
// public: 
//     void showUSB()
//     {
//         showTypeC();
//     }
// };

//对象适配器：单继承+ 组合
class Adapter:public USB
{
public: 
    void showUSB()
    {
        c.showTypeC();
    }
private: TypeC c;
};


int main ()
{
    USB *u = new Adapter;
    u->showUSB();
    return 0;
}