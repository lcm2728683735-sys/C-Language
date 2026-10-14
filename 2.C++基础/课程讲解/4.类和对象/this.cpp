#include <iostream>

class Test
{

public:
    static int a,b;//静态成员变量
    static void func()//静态成员函数
    //不需要依赖对象调用
    //普通成员变量不能使用
    //使用静态成员变量
    {
            b++;
        }
    //不属于某个特性的对象，属于整个类
    Test()
    {
        a++;
    }
    ~Test()
    {
        a--;
    }
private:
};
int Test::a = 0;//不能在静态环境中初始化，只能在类外单独定义

int main()
{
    // Test t;
    // Test t2;
    // t.a++;
    // std::cout<<sizeof(t)<<std::endl;
    Test *t1 = new Test;
    Test *t2 = new Test;
    delete t1;
    delete t2;
    std::cout<<Test::a<<std::endl;
    return 0;
}