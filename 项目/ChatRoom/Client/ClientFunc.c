#include "ClientFunc.h"
#include <stdio.h>

int Interface()
{
    printf("========================欢迎来到聊天室==========================\n");
    printf("1、私聊\n");
    printf("2、广播\n");
    printf("3、查看在线用户\n");
    printf("===============================================================\n");
    printf("请选择你要的功能:");
    int choice = 0;
    scanf("%d",&choice);
    return choice;
}

MSG CharToClient()
{
    MSG m;
    m.flag = CHAT;
    printf("请输入你要发送的用户名称:");
    scanf("%s",m.ToName);
    printf("请输入你要发送的信息:");
    scanf("%s",m.Content);

    return m;
}

MSG ChatBoradCast()
{
    MSG m;
    m.flag = BROADCAST;
    printf("请输入你要发送的信息:");
    scanf("%s",m.Content);
    return m;
}

MSG GetServerOnlineList()
{
    MSG m;
    m.flag = ONLINELIST;
    return m;
}
