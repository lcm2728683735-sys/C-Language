#include <iostream>

class Student
{
public:
    // 无参构造（缺省构造）
    Student() { std::cout << "无参构造函数!\n"; }
    Student(std::string name, int age)
    {
        std::cout << "带参构造函数！\n";
        m_name = name;
        m_age = age;
    }
    Student(Student &s)
    {
        std::cout << "拷贝构造函数!\n";
        m_name = s.m_name;
        m_age = s.m_age;
    }
    // 赋值运算符的重载  调用时机：s = s1
    void operator=(Student &s)
    {
        std::cout << "赋值运算符的重载\n";
        m_name = s.m_name;
        m_age = s.m_age;
    }
    //析构函数：无返回值  函数名和类型相同 ~ 无参数
    ~Student()
    {
        std::cout<<"析构函数\n";
    }
    void SetName(std::string name);
    void SetAge(int age);
    void show();

private:
    std::string m_name;
    int m_age;
};
void Student::SetName(std::string name)
{
    m_name = name;
}
void Student::SetAge(int age)
{
    m_age = age;
}
void Student::show()
{
    std::cout << "学生姓名" << m_name << "学生年龄：" << m_age << std::endl;
};

int main()
{
    Student s("zhangsan", 21);
    Student s1;
    s1 = s;  
    s1.show();
    return 0;
}