#include <iostream>
#include <MyStd/StdFIFO.h>
#include <SysHeader.h>

void SignalHandler(int sig)
{
    printf("接收到来自别的进程的信号");
}

int main()
{
    StdFIFO fifo("myfifo",StdFIFO::mode::WriteOnly);

    fifo.Write(std::to_string(getpid()));
    signal(SIGALRM,SignalHandler);
    while(1)
    {
        printf("进程运行\n");
        sleep(1);
    }
    return 0;
}