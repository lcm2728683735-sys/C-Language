#include <SysHeader.h>

void SignalHander(int sig)
{
    if(sig == SIGALRM)
    {
        printf("闹钟信号!\n");
        alarm(3);
    }
    else if(sig == SIGINT)
    {
        printf("发出中断信号!\n");
    }
    else if(sig == SIGTSTP)
    {
        printf("发送停止信号");
    }
}


int main ()
{
    // pid_t pid = fork();
    // if(pid == 0)
    // {
    //     while(1)
    //     {
    //         printf("子进程\n");
    //         sleep(1);
    //     }
    // }
    // else
    // {
    //     sleep(4);
    //     printf("向子进程发送信号\n");
    //     kill(pid,SIGINT);
    // }


    signal(SIGALRM,SignalHander);
    signal(SIGINT,SignalHander);
    signal(SIGTSTP,SignalHander);
    alarm(3);
    while(1)
    {
        printf("进程运行!\n");
        sleep(1);
    }
    return 0;
}