#include "StdTcp.h"
#include "GlobalMessage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StdThread.h"
#define ip "192.168.191.129"
#define port 8080


static char MyName[NameSize];

void Login(TcpC *c)
{
    MSG m;
    m.flag = LOGIN; //注册用户名
    printf("请输入你的用户名:");
    scanf("%s",m.FromName);
    strcpy(MyName,m.FromName);
    TcpClientSend(c,&m,sizeof(m));
}

MSG ChatToClient()
{
    MSG m;
    m.flag = CHAT;
    printf("请输入你要发送的用户名称:");
    scanf("%s",m.ToName);
    printf("请输入你要发送的信息:");
    scanf("%s",m.Content);
    strcpy(m.FromName,MyName);

    return m;
}

void * ThreadHandle(void* arg)
{
    TcpC * c = (TcpC*)(arg);
    while(1)
    {
        MSG m;
        if(TcpClientRecv(c,&m,sizeof(m)) == false)
        {
            printf("读线程接收错误");
            exit(-1);
        }
        printf("接收到来自|%s|的消息:%s\n",m.FromName,m.Content);
    }
}

int main()
{
    TcpC*c = TcpClientInit(ip,port);

    Login(c);
    Thread * t = ThreadInit(ThreadHandle,c);
    while(1)
    {
        MSG m = ChatToClient();
        if(TcpClientSend(c,&m,sizeof(m)) == false)
        {
            return -1;
        }
    }
    return 0;
}