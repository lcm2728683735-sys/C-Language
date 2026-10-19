#include <iostream>
#include "StdShrdMem.h"
#include <SysHeader.h>
#include "StdSem.h"


struct Student
{
    int id;
    char name[16];
};

int main ()
{
    StdShrdMem m("./",1);
    int count = 0;
    m.Write(&count,4);

    StdSem sem("./",1);
    for(int i = 0;i<5 ;i++)
    {
        sem.P();
        count = 0;
        m.Read(&count,4);
        std::cout << "2进程读出count:" << count <<std::endl;
        count++;
        m.Write(&count,4);
        std::cout << "2进程写入count:" << count <<std::endl;
        sem.V();
    }
    return 0;
}