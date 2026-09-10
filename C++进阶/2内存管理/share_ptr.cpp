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
    std::shared_ptr<Test> p = std::make_shared<Test>();
    p->show();
    std::cout << p.use_count << 
    std::shared_ptr<Test> p1=p;
    return 0;
}