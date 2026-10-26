#include "StdTcp.h"
#include "ClientFunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StdThread.h"
#include <unistd.h>
#define ip "192.168.191.129"
#define port 8080


static char MyName[NameSize];

void Login(TcpC *c)
{
    MSG m;
    m.flag = LOGIN; //注册用户名
    printf("请输入你的用户名:");
    scanf("%s",m.FromName);
    printf("请输入你的密码:");
    scanf("%s",m.Content);
    strcpy(MyName,m.FromName);
    TcpClientSend(c,&m,sizeof(m));

    if(TcpClientRecv(c,&m,sizeof(MSG)) == false)
    {
        exit(-1);
    }
    if(strcmp(m.Content,"注册成功") == 0)
    {
        printf("注册成功！欢迎来到聊天室!\n");
        sleep(2);
    }
    else
    {
        printf("注册错误:%s\n",m.Content);
        Login(c);
    }
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

void AnalysisRecv(MSG *m)
{
    switch(m->flag)
    {
    case CHAT:
        
    case BROADCAST:
        printf("接收到来自|%s|的消息:%s\n",m->FromName,m->Content);
        break;
    case ONLINELIST:
        ShowOnlineList(m);
        break;
    defalut:
        break;
    }
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
        AnalysisRecv(&m);
    }
}

int main(int argc,char * argv[])
{
    if(argc != 3)
    {
        printf("参数数量不对！\n");
        return -1;
    }
    TcpC*c = TcpClientInit(argv[1],atoi(argv[2]));

    Login(c);
    Thread * t = ThreadInit(ThreadHandle,c);
    while(1)
    {
        int choice = Interface();
        MSG m;

        switch(choice)
        {
        case CHAT:
            m = ChatToClient();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break;
        
        //广播
        case BROADCAST:
            m = ChatBoradCast();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break; 
        default:
            break;

        case ONLINELIST:
            m = GetServerOnlineList();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break; 
        }
    }
    return 0;
}