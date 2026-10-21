#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>  
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "StdUdp.h"
#include <string.h>

struct StdUdp
{
    int sock;
};

Udp *UdpInit(const char *ip, unsigned short port)
{
    Udp * u = (Udp*)malloc(sizeof(Udp));
    if(u == NULL)
    {
        printf("udp malloc");
        return NULL;
    }

    u->sock = socket(AF_INET,SOCK_DGRAM,0);
    if(u->sock == -1)
    {
        perror("socket");
        free(u);
        return NULL;
    }

    struct sockaddr_in addr;
    addr.sin_family =  AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    //绑定端口号
    if(bind(u->sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("bind");
        free(u);
        return NULL;
    }
    return u;
}

bool UdpSend(Udp *u, void *p, size_t size, const char *destIP, unsigned short destPort)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(destPort);
    addr.sin_addr.s_addr = inet_addr(destIP); 
    if(sendto(u->sock,p,size,0,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("sendto");
        return false;
    }
    return true;
}

bool UdpRecv(Udp *u, void *p, size_t size)
{
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    socklen_t len = sizeof(addr);
    if(recvfrom(u->sock,p,size,0,(struct sockaddr*)&addr,&len)< 0)
    {
        perror("recvfrom");
        return false;
    }
    return true;
}

void ClearUdp(Udp *p)
{
    //关闭文件描述符
    close(p->sock);
    free(p);
}
