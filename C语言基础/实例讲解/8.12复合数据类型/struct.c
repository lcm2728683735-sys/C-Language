#include <stdio.h>
#include "student/Student.h"
#include "student/Teacher.h"
#include <string.h> 
// #define INT int*
struct Student
{
    char Name[20];
    int id;
    int age;
    double score; 
}; 
typedef struct Student Stu;

void PrintStu(const Stu *s)
{
    printf("名字：%s 学号：%d 年龄：%d 分数：%.1lf\n",s->Name,s->id,s->age,s->score);
}

struct Teacher
{
    char Name[24];
    int age;
    int size;
    Stu s[10];
};

typedef struct Teacher Teach;
void InitTeacher(Teach *t,const char *name,int age)
{
    strcpy(t->Name,name);
    t->age = age;
}

void PrintTeacher (Teach *t)
{
    printf("名字:%s 年龄:%d\n",t->Name,t->age);
    for(int i = 0; i<t->size; i++)
    {
        PrintStu(t->s+i);
    }

}

void SetStuValue(Teach *t,const char *name,int id, int age,double score)
{

}
// typedef int* TypeInt;
// int main()
// {
//     INT a,b;
//     TypeInt c,d;
//     printf("%ld %ld\n",sizeof(a),sizeof(b));
//     printf("%ld %ld\n",sizeof(c),sizeof(d));
//     return 0;
// }

int main()
{
    // Stu s = {"zhangsan",1,20,99};
    // s.age = 21;
    // strcpy(s.Name,'lisi');
    // PrintStu(&s);

    // Stu s[3];
    // for(int i = 0;i<3;i++)
    // {
    //     scanf("%s %d %d %lf",&s[i].Name,&s[i].id,&s[i].age,&s[i].score);
    // }
    // for (int i = 0;i<3;i++)
    // {
    //     PrintStu(s+i);
    // }
    Teach t;
    InitTeacher(&t,"zhangsan",40);
    PrintTeacher(&t);
    return 0;
}