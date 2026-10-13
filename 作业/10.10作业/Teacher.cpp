#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string name,int age):name(name),age(age){}
    virtual ~Person(){std::cout <<"基类析构"<< std::endl;}
    void show()
    {
    std::cout << "name:" << name << std::endl;
    std::cout << "age:" << age << std::endl;
    }
protected:
    std::string name;
    int age;
};

class Teacher:public Person
{
public:
    Teacher(const std::string& name, int age,const std::string& title):Person(name, age), title(title) {}
    Teacher() : Person("未知", 0), title("无职称") {}
    virtual ~Teacher(){std::cout <<"子类析构"<< std::endl;}
    void show()
    {
    std::cout << "name:" << name << std::endl;
    std::cout << "age:" << age << std::endl;     
    std::cout << "title:" << title << std::endl;    
    }
private:
    std::string title;
};

int main ()
{
    Teacher teacher;
    teacher.show();
    return 0;
}