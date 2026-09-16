#include <iostream>
#include <vector>
#include <memory>
class Test
{
public:
    Test() {a = new int;}
    Test(const Test& t)
    {
        std::cout << "拷贝构造！\n";
        a= new int(*t.a);
    }
    Test(Test &&t)//移动构造
    {
        std::cout << "移动构造!\n";
        a= t.a;
        t.a = nullptr;
    }
private:
    int *a;
};
int main()
{
    // Test t1;
    // Test t2 = std::move(t1);
    //STL支持移动语义
    // std::vector<std::vector<int>> v;

    // std::vector<int> v1 = {1,2,3,4,5};
    // v.push_back(std::move(v1));

    // std::unique_ptr<int> p = std::make_unique<int>();
    // *p = 10;
    // std::cout << *p << std::endl;
    // auto p1 = std::move(p);
    // std::cout << *p1 << std::endl; 

    std::vector<std::unique_ptr<int>> v;
    std::unique_ptr<int> p = std::make_unique<int>();
    v.push_back(std::move(p));
    return 0;

}