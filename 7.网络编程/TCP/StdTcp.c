#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "StdTcp.h"


struct StdTcp
{
    int sock;
};

TcpS *TcpServerInit(const char *ip, unsigned short port)
{
    TcpS *s =(TcpS *)malloc(sizeof(TcpS));
    if(s == NULL)
    {
        printf("Tcps malloc error !\n");
        return NULL;
    }
    s->sock = socket(AF_INET,SOCK_STREAM,0);
    if(s->sock < 0)
    {
        perror("socket");
        free(s);
        return NULL;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//使用的是 IPv4 协议。
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if(bind(s->sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("blind");
        free(s);
        return NULL;
    }
    //设置地址复用
    int on = 1;
    if(setsockopt(s->sock,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
    {
        perror("setsockopt");
        free(s);
        return NULL;
    }
    //监听端口:最大等待队列
    if(listen(s->sock,10)<0)
    {
        perror("listen");
        free(s);
        return NULL;
    }
    return s;
}

int TcpServerAccept(TcpS *s)
{
    struct sockaddr_in clientAddr;
    socklen_t len = sizeof(clientAddr);
    int clientSock = accept(s->sock,(struct sockaddr*)&clientAddr,&len);
    if(clientSock < 0)
    {
        perror("accept");
        return -1;
    }
    return clientSock;
}

bool TcpServerSend(TcpS *s, void *p, size_t size)
{
    if(send(s->sock,p,size,0) < 0)
    {
        perror("send");
        return false;
    }
    return true;
}
