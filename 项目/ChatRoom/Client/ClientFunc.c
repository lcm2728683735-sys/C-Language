#include "ClientFunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Interface()
{
    printf("========================欢迎来到聊天室==========================\n");
    printf("1、私聊\n");
    printf("2、广播\n");
    printf("3、查看在线用户\n");
    printf("4、文件发送\n");
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

void ShowOnlineList(MSG *m)
{
    char str[ContentSize] = {0};
    strcpy(str,m->Content);
    char *dest = strtok(str,",");
    int count =1;
    while(dest != NULL)
    {
        printf("%d:%s\n",count++,dest);
        dest =strtok(NULL,",");
    }
}

void SendFile(const char *FilePath)
{
    FILE *f = fopen(FilePath,"r");
    if(f== NULL)
    {
        printf("打开|%s|文件打开失败!\n",FilePath);
        return;
    }
    fseek(f,0,SEEK_END);
    long FileSize = ftell(f);
    fseek(f,0,SEEK_SET);
}


struct PacketFile
{
    FILE *f;
    long FileSize;
    long currentPosition;
};


PackFile *PacketFileInit(const char *FilePath)
{
    PackFile *pf = (PackFile *)malloc(sizeof(PackFile));
    if(pf == NULL)
    {
        printf("PacketFileInit malloc error!\n");
        return NULL;
    }
    pf -> f = fopen(FilePath,"r");
    if(pf -> f == NULL)
    {
        printf("打开|%s|文件失败！\n",FilePath);
        free(pf);
        return NULL;
    }
    fseek(pf->f,0,SEEK_END);
    pf->FileSize = ftell(pf->f);
    fseek(pf->f,0,SEEK_SET);

    pf->currentPosition = 0;
    return pf;
}

void ReadFromFile(PackFile *f, void *p, int *size)
{
    if(*size + f->currentPosition > f->FileSize)
    {
        *size = f->FileSize - f->currentPosition;
    }
    fread(f->f,*size,1,f->f);
    f->currentPosition += *size;
}

bool IsFileEnd(PackFile *f)
{
    return feof(f->f) != 0;
}
