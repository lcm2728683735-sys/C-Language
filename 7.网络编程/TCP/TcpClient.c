#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#define ip "192.168.191.129"
#define port 8080

int main ()
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("socket");
        return -1;
    }

    //客户端连接服务器函数
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//使用的是 IPv4 协议。
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if(connect(sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("connect");
        return -1;
    }
    printf("连接服务器成功!\n");
    while(1)
    {
        char msg[100] = {0};
        printf("请输入你要发送的消息:");
        scanf("%s",msg);
        if(send(sock,msg,100,0) < 0)
        {
            perror("send");
            return -1;
        }
    }
    close(sock);
    return 0;
}