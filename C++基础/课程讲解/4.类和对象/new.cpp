#include <iostream>
class Test
{
public:
Test()
{
    std::cout<<"无参构造函数"<<std::endl;
}
~Test()
{
    std::cout<<"析构函数"<<std::endl;
}
private:

};
int main()
{
    // Test *t = new Test;
    // delete t;
    // return 0;

    Test *t = new Test[10];
    delete []t;
    return 0;
}
 