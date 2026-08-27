#include <iostream>

// class Test
// {};

// int main()
// {
//     std::cout<<sizeof(class Test)<<std::endl;
//     return 0;
// } 


using namespace std;

class A
{
public:
    int x;
};

class B
{
public:
    int x;
    virtual void test(){}
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
}