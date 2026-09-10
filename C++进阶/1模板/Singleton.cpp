#include <iostream>
template<typename T>
class Singleton
{
public:
    static T& getinstance()
    {
        static T instance;
        return instance;
    }
protected:
    Singleton(){}
};

class Student:public Singleton<Student>
//继承的类模板的模板参数是类本身
{
public:
    Student(){}
};
int main()
{
    Student s;
    return 0;

}