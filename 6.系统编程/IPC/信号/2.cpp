#include <iostream>
#include <MyStd/StdFIFO.h>
#include <SysHeader.h>

void SignalHandler(int sig)
{
    printf("接收到来自别的进程的信号");
}

int main()
{
    StdFIFO fifo("myfifo",StdFIFO::mode::ReadOnly);
    std::string pidStr = fifo.Read(1024);
    signal(SIGALRM,SignalHandler);
    while(1)
    {
        sleep(3);
        kill(atoi(pidStr.c_str()),SIGALRM);
        printf("给pid: %s发送信号!\n",pidStr.c_str());
    }
    return 0;
}