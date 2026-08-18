#ifndef __TEAHCER_H_
#define __TEACHER_H_
#include <stdbool.h> 

#include "Student.h"
struct Teacher
{
    char Name[24];
    int age;
    int size;
    Stu s[10];
};

typedef struct Teacher Teach;
void InitTeacher(Teach *t,const char *name,int age);
void PrintTeacher (Teach *t);
void InsertStu(Teach *t,const char *name,int id,int age,double score);
void RemoveStu(Teach *t,const char *name);
void RemoveByIndex(Teach *t,int index);
// Stu* FindFirstStu(Teach *t,const char * name);
Stu* FindFirstStu(Teach *t,void * value,bool(*p)(Stu *,void*));
#endif