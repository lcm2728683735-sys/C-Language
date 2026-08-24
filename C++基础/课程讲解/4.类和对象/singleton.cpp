#include <iostream>

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        static Singleton s;
        return &s;
    }
    void show()
    {
        std::cout<<"helloworld\n";
    }
private:
    Singleton(){}//构造函数私有化

};

int main()
{
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();
    Singleton *s3 = Singleton::GetInstance();

    printf("%p %p %p\n",s1,s2,s3);
    s1->show();
    s2->show();
    s3->show();
    return 0;
}