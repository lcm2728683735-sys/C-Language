#include "StdUdp.h"
#include "StdThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ip "192.168.191.129"
#define port 8080

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
int main(int argc,char * argv[])
{
    if(argc != 5)
    {
        printf("输入参数数量不对\n");
        return -1;
    }
    char MyIp[20] = {0};
    strcpy(MyIp,argv[1]);
    int MyPort = atoi (argv[2]);

    char DestIp[20] = {0};
    strcpy(DestIp,argv[3]);
    int destPort = atoi(argv[4]);

    Udp * u = UdpInit(MyIp,MyPort);
    Thread *t = ThreadInit(ThreadHandle,u);
    while(1)
    {
        char msg[100] = {0};
        printf("请输入你要发送的消息:");
        scanf("%s",msg);
        if(UdpSend(u,msg,100,DestIp,destPort)==false)
        {
            return -1;
        }
    }

    ClearUdp(u);
    return 0;
}