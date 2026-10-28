#include "ClientFunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int LoginFace()
{
    printf("========================聊天室登录==========================\n");
    printf("1、注册\n");
    printf("2、登录\n");
    printf("===============================================================\n");
    printf("请选择你要的功能:");
    int choice = 0;
    scanf("%d",&choice);
    return choice * (-1);

}

MSG SignUp(char *MyName)
{
    MSG m;
    m.flag = SIGNUP; //注册用户名
    printf("========================注册新用户==========================\n");
    printf("请输入你的用户名:");
    scanf("%s",m.FromName);
    printf("请输入你的密码:");
    scanf("%s",m.Content);
    printf("========================欢迎来到聊天室==========================\n");
    strcpy(MyName,m.FromName);
    return m;
    // if(TcpClientRecv(c,&m,sizeof(MSG)) == false)
    // {
    //     exit(-1);
    // }
    // if(strcmp(m.Content,"注册成功") == 0)
    // {
    //     printf("注册成功！欢迎来到聊天室!\n");
    //     sleep(2);
    // }
    // else
    // {
    //     printf("注册错误:%s\n",m.Content);
    //     SignUp(c);
    // }
}

bool IsSignUpSuccess(MSG *m)
{
    if(strcmp(m->Content,"注册成功") == 0)
    {
        printf("注册成功!\n");
        return true;
    }
    else
    {
        printf("注册错误:%s\n",m->Content);
        return false;
    }
}

MSG Login(char *MyName)
{
    MSG m;
    m.flag = LOGIN; //注册用户名
    printf("==========================登录用户==========================\n");
    printf("请输入你的用户名:");
    scanf("%s",m.FromName);
    printf("请输入你的密码:");
    scanf("%s",m.Content);
    printf("======================================================\n");
    strcpy(MyName,m.FromName);
    return m;
}

bool IsLoginSuccess(MSG *m)
{
    if(strcmp(m->Content,"登录成功") == 0)
    {
        printf("登录成功!\n");
        return true;
    }
    else
    {
        printf("登录错误:%s\n",m->Content);
        return false;
    }
}

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

MSG SendFile()
{
    MSG m;
    m.flag = SENDFILE;
    printf("请输入你要发送的文件路径：");
    scanf("%s",m.Content);
    printf("请输入你要发送的用户:");
    scanf("%s",m.ToName);
    return m;
}

char *GetFileNameFromPath(const char *filePath)
{
    char str[ContentSize] = {0};
    strcpy(str,filePath);

    char *dest = strtok(str,"/");
    char *fileName = NULL;
    while(dest != NULL)
    {
        fileName = dest;
        dest = strtok(NULL,"/");
    }
    char * result = strdup(fileName);
    return result;
}

void WriteToLocal(MSG *m)
{
    int size = 0;
    memcpy(&size,m->Content,sizeof(int));
    char fileName[ContentSize] = {0};
    strcpy(fileName,m->Content + 4);

    char filePath[ContentSize] = {0};
    sprintf(filePath,"./%s",fileName);
    FILE *f = fopen(filePath,"a");
    fwrite(m->Content+24,size,1,f);
    fclose(f);
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
    if (pf->f == NULL)
    {
        printf("文件打开失败！\n");
        printf("传入路径：[%s]\n", FilePath);
        printf("错误原因：%s\n", strerror(errno));

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
    fread(p,*size,1,f->f);
    f->currentPosition += *size;
}

bool IsFileEnd(PackFile *f)
{
    return f->currentPosition == f->FileSize;
}

void ClearPacketFile(PackFile *f)
{
    fclose(f->f);
    free(f);    
}
