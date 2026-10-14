#include <iostream>
class Test
{
public:
    //初始化列表
    //const变量必须在初始化列表进行初始化
    Test():a(0)
    {
    } 

    void show()
    {
        std::cout<<this->a<<std::endl;
    }
private:
    const int a;
};

int main ()
{
    Test t;
    t.show();
    return 0;
}