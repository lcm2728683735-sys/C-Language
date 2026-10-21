#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>  //struct addr_in
#include <arpa/inet.h>

#define ip "192.168.191.12"
#define port 8080
int main()
{
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock == -1)
    {
        perror("socket");
        return -1;
    }

    char msg[100] = "helloworld";


    //地址结构体赋值
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//使用的是 IPv4 协议。
    //设置 16 位的端口号，并将其从主机字节序转换为网络字节序。
    addr.sin_port = htons(port);
    //将IP地址转换为计算机能识别的 32 位二进制网络字节序整数
    addr.sin_addr.s_addr = inet_addr(ip);

    //绑定端口号
    if(bind(sock,(struct sockaddr*)&addr,sizeof(addr))<0)
    {
        perror("bind");
        return -1;
    }

    //无连接发送数据
    // if(sendto(sock,msg,100,0,(struct sockaddr*)&addr,sizeof(addr))<0);
    // {
    //     perror("sendto");
    //     return -1;
    // }

    // printf("发送成功!\n");

    char msg[100] = {0};
    socklen_t len = sizeof(addr);
    if(recvfrom(sock,msg,100,0,(struct sockaddr*)&addr,&len)< 0)
    {
        perror("recvfrom");
        return -1;
    }
    printf("收到来自ip:%s 端口 :%d 的信息 msg:%s\n",inet_ntos(addr.sin_addr),ntohs(addr.sin_port),msg);
    return 0;
}