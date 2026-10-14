#include <iostream>
#include <string>

class Student
{
public:

    static const Student& getInstance()
    {
        static Student s;
        return s;
    } 
    //声明

    void SetName(std::string name) 
    {
        m_name = name; 
    }
    void SetAge(int age)
    {
        m_age = age; 
    }
    //成员函数（方法）
    void show()
    {
        std::cout<<"学生姓名"<<m_name<<"学生年龄："<<m_age<<std::endl;
    };

    Student(){};
    Student(const Student& stu)
    {
        
    }

private:
    //成员变量（属性）
    std::string m_name;
    int m_age;
};

struct Test
{
public:
    void SetA(int a)
    {
        m_a = a;
    }
    void show()
    {
        std::cout<<"a = "<<m_a<<std::endl;
    }
private:
    int m_a;
};

int main()
{
    // Student s;
    // s.SetName("zhangsan ");
    // s.SetAge(10);
    // s.show();

    Test t;
    t.SetA(100);
    t.show();
    return 0;

}