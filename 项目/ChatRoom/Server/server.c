#include "StdTcp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StdThread.h"
#include "../GlobalMessage.h"
#include "List.h"
#define ip "192.168.191.129"
#define port 8080

List ClientList;

char* GetOnlinelist()
{
    char* content = (char*)malloc(ContentSize);
    if(content == NULL)
    {
        printf("GetOnlinelist malloc error!\n");
        exit(-1);
    }
    memset(content,0,ContentSize);
    Node * travelPoint = ClientList.head;
    while(travelPoint != NULL)
    {
        CInfo * c = (CInfo*)travelPoint->data;
        strcat(content,c->ClientName);
        strcat(content,",");
        travelPoint = travelPoint ->next;
    }
    content[strlen(content) -1 ] = '\0';
    return content;
}

void SolveRequest(MSG *m,int clientSock)
{
    switch(m->flag)
    {
    case LOGIN:
        List_PushBack(&ClientList,CreateCInfo(m->FromName,clientSock));
        List_Travel(&ClientList,PrintCInfo);
        break;
    case CHAT:
        List findList = List_FindElement
        (&ClientList, m->ToName, IsClientNameEqual);
        if(findList.size == 0)
        {
            printf("没有找到名称为|%s|的用户\n",m->ToName); 
        }
        else
        {
            CInfo *c =  (CInfo*)findList.head->data;
            if(c!= NULL)
            {
            printf("准备给|%s|用户：|%d|套接字发送消息\n",c->ClientName,c->sock);
            TcpServerSend(c->sock,m,sizeof(MSG));
            }
        }
        List_Clear(&findList);
        break;
    case BROADCAST:
        Node * travelPoint = ClientList.head;
        while(travelPoint != NULL)
        {
            CInfo * c = (CInfo*)travelPoint->data;
            if(strcmp(c->ClientName,m->FromName)!= 0)
            {
                TcpServerSend(c->sock,m,sizeof(MSG));
            }
            travelPoint = travelPoint->next;
        }
        break;

    case ONLINELIST:
        char * content = GetOnlinelist();
        printf("在线列表为:%s\n",content);
        strcpy(m->Content,content);
        TcpServerSend(clientSock,m,sizeof(MSG));
        free(content);
        break;
    }
}

void * ClientHandle(void * arg)
{
    int clientSock = *((int *) arg);
    while(1)
    {
        MSG m;
        if(TcpServerRecv(clientSock,&m,sizeof(MSG)) == false)
        {
            printf("客户端|%d|已下线\n",clientSock);
            break;
        }
        // printf("收到来自客户端|%d|的消息:%s\n",clientSock,msg);
        SolveRequest(&m,clientSock);
    }
    //删除用户 
    List_RemoveByElement(&ClientList,&clientSock,IsClientSockEqual,free);
    return NULL;
}

int main ()
{
    TcpS *s = TcpServerInit(ip,port);

    int clientSock = -1;
    while((clientSock = TcpServerAccept(s)) >= 0)
    {
        printf("接入新的客户端,套接字是:%d\n",clientSock);
        Thread * t = ThreadInit(ClientHandle,&clientSock);
    }


    return 0;
}