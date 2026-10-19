#include <iostream>
#include "StdShrdMem.h"

struct Student
{
    int id;
    char name[16];
};

int main ()
{
    StdShrdMem m("./",1);

    Student s;

    m.Read(&s,sizeof(s));
    printf("%d %s",s.id,s.name);
    return 0;
}