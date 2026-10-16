#include "SysHeader.h"

int main()
{
    int fd[2];
    if(pipe(fd) == -1);
    { 
        perror("pipe:");//打印系统调用的错误
        return -1;
    }

    pid_t pid = fork();
    if(pid == 0)
    {
        //子进程负责写
        char str[1024] = {0};
        scanf("%s",str);
        write(fd[1],str,1024);
        exit(0);
    }
    else
    {
        //父进程负责读
        char str[1024] = {0};
        //read是一个阻塞的函数，直到管道中有可读数据才读取执行
        read(fd[0],str,1024);
        printf("父进程读取子进程的数据:%s\n",str);
    }
    return 0;
}