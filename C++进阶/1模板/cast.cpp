#include <iostream>

class Base
{
public:
    virtual void show()
    {
        std::cout << "Base" << std::endl;
    }
private:
};

class Derived:public Base
{
public:
    virtual void show()
    {
    }
};

int main()
{
    //静态转换
    //基础数据类型转换
    //不能用于不同类型的指针转换
    //可以用于void * 和其他指针的转换
    //可以用于父子类指针的转换，不会进行转换安全检查
    // int a = 97;
    // double b = static_cast<char>(a);
    // int a = 10;
    // int* p = &a;
    // void * p1 = static_cast<void*>(p);
    // std::cout << p << std::endl;

    Base*b = new Base();
    //动态转换
    //运行期检查   检查指针是否能够完成转换
    //如果不能转换 返回nullptr

    // Derived * d = dynamic_cast<Derived *>(b);
    // if(d == nullptr)
    //     std::cout << "转换失败!\n";
    // printf("%p %p\n", b, d);
    
    //常量转换
    // const int a = 10;
    // int * p = const_cast<int*>(&a);  
    // *p = 20; 
    // std::cout << a << " "<< *p << std::endl;

    //重解释
    int a = 10;
    int * p = &a;
    long c = reinterpret_cast<long>(p);
    return 0;
}