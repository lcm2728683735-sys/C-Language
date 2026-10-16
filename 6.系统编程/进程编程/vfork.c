#include <sys/types.h>//系统调用
#include <sys/wait.h>//wait pid
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int a = 1;

int main ()
{
    pid_t pid = vfork();
    if(pid == 0)
    {
        printf("子进程\n");
    }
    else
    {
        printf("父进程\n");
    }
    return 0;
}