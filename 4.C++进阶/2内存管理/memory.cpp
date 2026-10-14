#include <iostream>
#include <memory>

class Test
{
public:
    Test():a(std::make_unique<int>())
    {
        std::cout << "构造函数!\n";
    }
    ~Test()
    {
        std::cout << "析构函数!\n";
    }
    void show()
    {
        std::cout << "helloworld\n";
    }
private:
    std::unique_ptr<int> a;
};

int main()
{
    //独占指针
    //RAII+模板+运算符重载
    //make_unique

    std::unique_ptr<Test> p = std::make_unique<Test>();
    // p->show();
    // (*p).show();

    // std::unique_ptr<Test> p2;
    // p2 = p;

    // Test* t = p.get(); 
    // t->show();
    // delete t; 

    // Test t1;
    // Test t2(t1);
    return 0;

}