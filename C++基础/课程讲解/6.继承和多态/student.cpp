#include <iostream>
#include <string>



using CStrRef = const std ::string &;
class Person
{
private:
    std::string name;
    int age;
    std::string ID;
public:
    Person():name(""),age(0),ID(""){};
    Person(CStrRef name,int age,CStrRef ID):name(name),age(age),ID(ID)
    {
        std::cout<<"父类构造函数\n";   
    };

    ~Person()
    {
        std::cout<<"父类析构函数\n";
    }
    void show()
    {
        std::cout<<"名字:"<<name<<" 年龄:"<<age<<" 身份证："<<ID<<std::endl;
    }
};

class Student:public Person
{
private:
    int score;
public:
    Student(CStrRef name, int age,CStrRef ID,int score):Person(name,age,ID)
    {
        std::cout<<"子类构造函数！\n";
        this->score = score;
    }
    ~Student()
    {
        std::cout<<"子类析构函数！\n";
    }

    void show()
    {
        Person::show();
        std::cout<<"分数："<<score<<std::endl;
    }
};

int main()
{
    Student s("张三",20,"123",98);
    s.show();
    return 0;
}