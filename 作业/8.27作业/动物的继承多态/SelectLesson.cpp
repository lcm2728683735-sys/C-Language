#include <iostream>

class Person
{
public:
    Person() : name(""), age(0) {};
    Person(const std ::string &name, int age) : name(name), age(age) {};
    void show()
    {
        std::cout << "名字:" << name << " 年龄:" << age << std::endl;
    }

private:
    std::string name;
    int age;
};

class Student : public Person
{
public:
    Student(const std ::string &name, int age, int Number, const std::string &major) : Person(name, age) 
    {
        this->Number = Number;
        this->major = major;
    };
    void show();

private:
    int Number;
    std::string major;
};
void Student::show()
{
    Person::show();
    std::cout << "学号:" << Number << " 专业:" << major << std::endl;
}

class Course:public Student
{
public:
    Course(const std ::string & name, int age,int Number,const std::string & major,const std::string LessonName ,int score):Student(name,age,Number,major)
    {
        this->LessonName = LessonName;
        this->score = score;
    };
    void show()
    {
        Student::show();
        std::cout<<"课程:"<<LessonName<<" 分数:"<<score<<std::endl;
    }
private:
    std::string LessonName;
    int score;
};

int main()
{
    // Person a("张三", 20);
    // a.show();
    // Student b("张三", 20, 5235, "电子信息");
    // b.show();
    Course c("张三",20,5235,"电子信息","数字电路",90);
    c.show();
    return 0;
}