#include <stdio.h>
#include "DynamicArray.h"

struct Student
{
    char *name;
    int age;
};
typedef struct Student Stu;

void PrintStu(void* s)
{
    Stu *ps = (Stu*)s;//把void指针转成stu指针
    printf("学生姓名：%s 学生年龄：%d\n",ps->name,ps->age);
}

int main()
{
    // DArray *a = InitDArray(10);

    // for(int i = 1;i<= 20;i++)
    // {
    //     InsertTail(a,i);
    // }
    // PrintArray(a);
    // FreeDArray(a);
    Stu s;
    s.name ="zhangsan";
    s.age = 1;

    
    DArray *a = InitDArray(10);
    InsertTail(a,&s); 
    PrintArray(a,PrintStu);
    return 0;
}