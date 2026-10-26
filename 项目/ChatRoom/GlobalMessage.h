#ifndef __GLOBALMESSAGE_H__
#define __GLOBALMESSAGE_H__

#include <stdbool.h>

#define NameSize 20
#define ContentSize 1024
struct ClientInfo
{
    char ClientName[NameSize];
    int sock;
};
typedef struct ClientInfo CInfo;

CInfo* CreateCInfo(const char * name,int sock);
void PrintCInfo(void * p);
bool IsClientNameEqual(void * ClientPtr,void * clientName);
bool IsClientSockEqual(void * ClientPtr,void * sock);
enum Request
{
    LOGIN,
    CHAT,
    BROADCAST,
    ONLINELIST, //在线链表
    SENDFILE
};


//信息结构体
struct GlobalMessage
{
    char FromName[NameSize];//信息来源
    char ToName[NameSize];//信息目标
    char Content[ContentSize];//信息主体

    int flag;//功能标志位
};
typedef struct GlobalMessage MSG;

#endif