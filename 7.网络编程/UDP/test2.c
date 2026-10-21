#include "StdUdp.h"
#include "StdThread.h"
#include <stdio.h>

#define ip "192.168.191.129"
#define port 8081

void* ThreadHandle(void * arg)
{
    Udp *u = (Udp*)arg;
    while(1)
    {
        char msg[100] = {0};
        if(UdpRecv(u,msg,sizeof(msg)) == false)
        {
            return NULL;
        }
        printf("接收到信息:%s\n",msg);
    }
}
int main()
{
    Udp * u = UdpInit(ip,port);
    Thread *t = ThreadInit(ThreadHandle,u);
    while(1)
    {
        char msg[100] = {0};
        printf("请输入你要发送的消息:");
        scanf("%s",msg);
        if(UdpSend(u,msg,100,ip,port - 1)==false)
        {
            return -1;
        }
    }

    ClearUdp(u);
    return 0;
}