#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Student.h"
#include "Teacher.h"

bool IsNameEqual(Stu *s,void *value)
{
    char *name = (char *)value;
    return strcmp(s->Name,name) == 0;
}

bool IsAgeEqual(Stu *s,void *value)
{
     
    return s->age ==(int)value;
}

bool IsScoreGreater(Stu *s,void *value)
{
    return s->score>= *(double*)value;
}

int main()
{
    Teach t;
    InitTeacher(&t,"zhangsan",40);
    InsertStu(&t,"李四",1,20,99);
    InsertStu(&t,"王五",1,20,99);
    InsertStu(&t,"李四",1,20,99);
    // PrintTeacher(&t);
    // RemoveStu(&t,"四李");
    // PrintTeacher(&t);

    Stu* s =FindFirstStu(&t,"李四",IsNameEqual);
    if(s)
    {
        PrintStu(s);
    }
    else
    {
        printf("没找到！\n");
    }
    return 0;
}