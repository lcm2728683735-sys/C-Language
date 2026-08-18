#include "Student.h"
#include <stdio.h>
#include <string.h>

void PrintStu(const Stu *s)
{
    printf("名字：%s 学号：%d 年龄：%d 分数：%.1lf\n",s->Name,s->id,s->age,s->score);
}

void SetStuValue(Stu * s,const char * name,int id,int age,double score)
{
    s->id = id;
    s->age = age;
    s->score = score;
    strcpy(s->Name,name); 
}