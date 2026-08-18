#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
    char *Name;
    int age;
    int id;
};
typedef struct Student Stu;
int main()
{
    Stu *s = (Stu*)malloc(sizeof(Stu));
    if(s == NULL)
    {
        printf("malloc error!\n");
        return -1;
    }
    s->Name = (char*)malloc(strlen("zhangsan")+1);
    strcpy(s->Name,"zhangsan");
    s->id = 1;
    s->age = 20;
    printf("%s %d %d\n",s->Name,s->age,s->id);
    //
    free(s->Name);
    free(s);
    return 0;
}