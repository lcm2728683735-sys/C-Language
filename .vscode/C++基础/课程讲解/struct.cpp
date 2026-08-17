#include <iostream>

struct Student
{
    void show()
    {
        std::cout<<Name<<" "<<age<<std::endl;
    }
    char Name[20];
    int age;
};



int main()
{
    Student s= {"zhangsan",21};
    s.show();
    return 0;
}
