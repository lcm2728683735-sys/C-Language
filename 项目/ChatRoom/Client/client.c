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
    case SENDFILE:
        WriteToLocal(m);
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

void LoginSignUp(TcpC*c)
{
    while(1)
    {
        int choice = LoginFace();
        MSG m;
        switch (choice)
        {
        case LOGIN:
            m = Login(MyName);
            TcpClientSend(c,&m,sizeof(MSG));
            if(TcpClientRecv(c,&m,sizeof(MSG)) == false)
            {
                exit(-1);
            }
            if(IsLoginSuccess(&m)== true)
            {
                return;
            }
            break;
        case SIGNUP:
            m = SignUp(MyName);
            TcpClientSend(c,&m,sizeof(MSG));
            if(TcpClientRecv(c,&m,sizeof(MSG)) == false)
            {
                exit(-1);
            }
            if(IsSignUpSuccess(&m) == true)
            {
                return;
            }
        default:
            break;
        }
        sleep(2);
        system("clear");
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

    LoginSignUp(c);    

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

        case ONLINELIST:
            m = GetServerOnlineList();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break; 

        case SENDFILE:
            m = SendFile();
            strcpy(m.FromName,MyName);
            char *fileName = GetFileNameFromPath(m.Content);
            PackFile * pf = PacketFileInit(m.Content);
            
            memset(m.Content,0,sizeof(m.Content));
            strcpy(m.Content + 4,fileName);
            int size = 1000;
            int count = 0;
            while(IsFileEnd(pf) == false)
            {
                ReadFromFile(pf,m.Content + 24,&size);
                //填入读取的文件内容大小
                memcpy(m.Content,&size,sizeof(int));
                TcpClientSend(c,&m,sizeof(MSG));

                count++;
                printf("这是第%d包数据,大小:%d\n",count,size);
            }
            free(fileName);
            ClearPacketFile(pf);
        default:
            break;
        }
    }
    return 0;
}