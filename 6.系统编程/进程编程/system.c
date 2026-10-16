#include <sys/types.h>//系统调用
#include <sys/wait.h>//wait pid
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

int main()
{   
    for(int i= 0;i<10;i++)
    {
        char str[10] = {0};
        sprintf(str,"touch %d.txt",i);
        system("./2");
    }
    return 0;
}