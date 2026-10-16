#include <sys/types.h>//系统调用
#include <sys/wait.h>//wait pid
#include <unistd.h>
#include <stdio.h>

int main ()
{
    //进程号：默认 0- 32767
    //64位 ： 0 ~ 2^31 -1
    // pid_t pid = getpid();
    // printf("pid : %d\n",pid);
    // printf("ppid : %d\n",getppid());
    // return 0;

    //进程的创建函数
    pid_t pid = fork();
    if(pid  == 1)
    {
        printf ("进程创建失败!");
        return-1;
    }
    if(pid == 0)//子进程
    {
        // sleep(2);//进程挂起,让出cpu,进程进行等待
        // scanf();//阻塞函数
        printf("子进程pid : %d\n",getpid());
        printf("ppid : %d\n",getppid());
        return 125;
    }
    else
    {
        printf("父进程pid : %d\n",getpid());
        printf("收到的子进程id : %d\n",pid);    
        //进程的等待
        //等待子进程结束，在此之前会一直阻塞
        int status = 0;
        // wait(&status);
        waitpid(-1,&status,0);
        exit(128);
        //状态值存在于高8位
        printf("子进程退出状态:%d\n",WEXITSTATUS(status));
    }
    return 0;
}