#include "GlobalMessage.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

CInfo *CreateCInfo(const char * name,int sock)
{
    CInfo * c = (CInfo*)malloc(sizeof(CInfo));
    if(c == NULL)
    {
        return NULL;
    }
    strcpy(c->ClientName,name);
    c->sock = sock;
    return c;
}

void PrintCInfo(void * p)
{
    CInfo * c = (CInfo *)p;
    printf("用户名：%s  套接字：%d\n",c->ClientName,c->sock);
}

bool IsClientNameEqual(void *ClientPtr, void *clientName)
{
    CInfo *c = (CInfo*)ClientPtr;
    char *CName= (char *) clientName;
    return strcmp(c->ClientName,CName) == 0;
}


bool IsClientSockEqual(void *ClientPtr, void *sock)
{
    if (ClientPtr == NULL || sock == NULL)
        return false;

    CInfo *c = (CInfo *)ClientPtr;
    int s = *(int *)sock;

    return c->sock == s;
}
