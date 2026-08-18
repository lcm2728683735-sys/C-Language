#include <stdio.h>
#include <string.h>
#include "Teacher.h"
#include "Student.h"
#include <stdbool.h> 



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

void InsertStu(Teach * t,const char * name,int id,int age,double score)
{
    SetStuValue(&t->s[t->size],name,id,age,score);
    t->size++;
}

void RemoveByIndex(Teach *t,int index)
{
        for(int i =index;i<t->size - 1;i++)
        {
            t->s[i] = t->s[i+1];
        }
        t->size--;
}

void RemoveStu(Teach * t, const char * name)
{
    for(int i = 0; i<t->size;i++)
    {
        if(strcmp(t->s[i].Name,name)==0)
        {
            RemoveByIndex(t,i);
            i--;
        }
    }
}

// Stu* FindFirstStu(Teach *t,const char * name)
// {
//     for(int i =0;i<t->size; i++)
//     {
//         if(strcmp(t->s[i].Name,name) == 0)
//             return &t->s[i];
//     }
//     return NULL;
// }

Stu* FindFirstStu(Teach *t,void * value,bool(*p)(Stu *,void*))
{
    for(int i =0;i<t->size; i++)
    {
        if(p(&t->s[i],value) == true)
            return &t->s[i];
    }
    return NULL;
}
