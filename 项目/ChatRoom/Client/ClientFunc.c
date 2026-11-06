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
    printf("5、我的网盘\n");
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

//mode 1 清空新建 mode 2 末尾追加写猜
void WriteToLocal(MSG *m, int mode, const char *realFileName)
{
    char filePath[ContentSize] = {0};

    if (realFileName != NULL && strlen(realFileName) > 0) 
    {
        sprintf(filePath, "./%s", realFileName);
    } else {
        sprintf(filePath, "./%s", m->Content + 4); 
    }

    FILE *f = fopen(filePath, (mode == 1) ? "wb" : "ab");
    if(f == NULL)
    {
        printf("*错误* 无法打开本地文件进行写入: %s\n", filePath);
        return;
    }

    int32_t size = 0;
    memcpy(&size, m->Content, sizeof(int));

    if(size > 0)
    {
        fwrite(m->Content + 24, size, 1, f);
    }
    
    fclose(f);
}



int CloudInterface()
{
    printf("=====================我的网盘=====================\n");
    printf("1.查看网盘文件\n");
    printf("2.上传文件\n");
    printf("3.下载文件\n");
    printf("4.退回到主界面\n");
    printf("====================================================\n");
    int choice = 0;
    printf("请输入你的选择:");
    scanf("%d",&choice);
    return FILELIST + choice - 1;
}

char** Split(const char * str,const char *delim,int * size)
{
    char *splitStr = strdup(str);

    char** result = (char **)malloc(sizeof(char*) * 50);
    if(result == NULL)
    {
        printf("Split malloc error!\n");
        return NULL;
    }

    int count = 0;
    char *dest = strtok(splitStr,delim);
    while(dest != NULL)
    {
        result[count++] = strdup(dest);
        dest = strtok(NULL,delim);
    }
    free(splitStr);
    *size = count;
    return result;
}

void FreeStrList(char ** strList,int size)
{
    for(int i = 0;i < size;i++)
    {
        free(strList[i]);
    }
    free(strList);
}

void ShowFileList(MSG *m)
{
    if(strcmp(m->Content,"FILE ERROR") == 0)
    {
        printf("获取网盘文件失败");
        return;
    }

    int fileCount = 0;
    char ** file = Split(m->Content,",",&fileCount);
    for(int i = 0;i < fileCount; i++)
    {
        int count = 0;
        char ** fileInfo = Split(file[i],";",&count);
        if(count != 2)
        {
            FreeStrList(fileInfo,count);
            continue;
        }
        printf("%d : 文件名:|%s| 文件大小：|%s|\n",i+1,fileInfo[0],fileInfo[1]);
        FreeStrList(fileInfo,count);
    }
    FreeStrList(file,fileCount);
}


MSG UpLoadFile()
{
    MSG m;
    m.flag = UPLOAD;
    printf("请输入上传的文件路径:");
    scanf("%s",m.Content);
    return m;
}


MSG DownLoadFile()
{
    MSG m;
    memset(&m, 0, sizeof(MSG)); 
    
    m.flag = DOWNLOAD;

    char filename[NameSize] = {0};
    printf("请输入要下载的文件名(包含后缀): ");
    scanf("%s", filename);

    strncpy(m.Content, filename, sizeof(m.Content) - 1);
    return m;
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
