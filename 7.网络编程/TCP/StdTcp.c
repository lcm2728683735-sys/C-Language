#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "StdTcp.h"
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>

struct StdTcpServer
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

    //设置地址复用
    int on = 1;
    if(setsockopt(s->sock,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
    {
        perror("setsockopt");
        free(s);
        return NULL;
    }
    if(bind(s->sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("blind");
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

bool TcpServerSend(int clientSock, void *p, size_t size)
{
    if(send(clientSock,p,size,0) < 0)
    {
        perror("send");
        return false;
    }
    return true;
}

bool TcpServerRecv(int clientSock, void *p, size_t size)
{
    char *buf = (char *)p;
    size_t total = 0;

    while(total < size)
    {
        ssize_t n = recv(clientSock,buf + total, size - total,0);
        if(n == 0)
        {
            printf("客户端关闭了连接\n");
            return false;
        }
        if(n < 0)
        {
            if (errno == EINTR)
                continue;

            perror("recv");
            return false;
        }
        total += (size_t)n;
    }
    return true;
}

void ClearTcpServer(TcpS *s)
{
    close(s->sock);
    free(s);
}

struct StdTcpClient
{
    int sock;
};

TcpC *TcpClientInit(const char *ServerIP, unsigned short ServerPort)
{
    TcpC *c = ( TcpC *)malloc(sizeof(TcpC));
    if(c == NULL)
    {
        printf("TcpC malloc error!\n");
        return NULL;
    }

    c->sock = socket(AF_INET,SOCK_STREAM,0);
    if(c->sock < 0)
    {
        perror("socket");
        free(c);
        return NULL;
    }

    //客户端连接服务器函数
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;//使用的是 IPv4 协议。
    addr.sin_port = htons(ServerPort);
    addr.sin_addr.s_addr = inet_addr(ServerIP);
    if(connect(c->sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("connect");
        free(c);
        return NULL;
    }
    return c;
}

bool TcpClientSend(TcpC *c, void *p, size_t size)
{
    if(send(c->sock,p,size,0) < 0)
    {
        perror("send");
        return false;
    }
    return true;
}

bool TcpClientRecv(TcpC *c, void *p, size_t size)
{
    char *buf = (char *)p;
    size_t total = 0;

    while(total <size )
    {
        ssize_t n = recv(c->sock,buf + total,size - total,0);

        if(n == 0)
        {
            fprintf(stderr,"服务器关闭了连接\n");
            return false;
        }
        if(n < 0)
        {
            if(errno == EINTR)
                continue;
            perror("recv");
            return false;
        }

        total += (size_t)n;
    }

    return true;
}

void ClearTcpClient(TcpC *c)
{
    close(c->sock);
    free(c);
}
