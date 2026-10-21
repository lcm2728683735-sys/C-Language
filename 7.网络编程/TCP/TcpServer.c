#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#define ip "192.168.191.129"
#define port 8080

int main()
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//使用的是 IPv4 协议。
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if(bind(sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("blind");
        return -1;
    }
    //设置地址复用
    int on = 1;
    if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
    {
        perror("setsockopt");
        return -1;
    }
    //监听端口:最大等待队列
    if(listen(sock,10)<0)
    {
        perror("listen");
    }

    //accept函数是阻塞的,当有客户端接入时才返回新客户端套接字
    //客户端的连接套接字
    printf("等待客户端连接\n");
    struct sockaddr_in clientAddr;
    socklen_t len = sizeof(clientAddr);
    int clientSock = accept(sock,(struct sockaddr*)&clientAddr,&len);
    if(clientSock < 0)
    {
        perror("accept");
        return -1;
    }
    printf("接收到客户端连接，套接字是:%d\n",clientSock);

    while(1)
    {
        char msg[100] = {0};
        if((recv(clientSock,msg,100,0)) <= 0)
        {
            printf("客户端已下线\n");
            return -1;
        }
        printf("收到来自客户端的消息：%s\n",msg);
    }

    close(clientSock);
    close(sock);
    return 0;
}