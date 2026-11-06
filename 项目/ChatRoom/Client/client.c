#include "StdTcp.h"
#include "ClientFunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "StdThread.h"
#include <unistd.h>
#define ip "192.168.191.129"
#define port 8080

static char MyName[NameSize];
static volatile bool isDownloadFinished = false;
static char currentDownloadFileName[NameSize] = {0};

MSG ChatToClient()
{
    MSG m;
    m.flag = CHAT;
    printf("请输入你要发送的用户名称:");
    scanf("%s",m.ToName);
    printf("请输入你要发送的信息:");
    scanf("%s",m.Content);
    strcpy(m.FromName,MyName);
    return m;
}

void PrintProgress(int64_t current, int64_t total)
{
    if (total <= 0) return;
    int percentage = (int)(((double)current / (double)total) * 100.0);
    
    int numbar = percentage / 2;
    printf("\33[2K\r["); 
    for (int i = 0; i < 50; i++) 
    {
        if (i < numbar) printf("=");
        else printf(" ");
    }
    printf("] %d%% (%ld/%ld Bytes)", percentage, (long)current, (long)total);
    fflush(stdout); 
}

void AnalysisRecv(MSG *m)
{
    static int64_t totalFileSize = 0;
    static int64_t recvFileSize = 0;

    switch(m->flag)
    {
    case CHAT:
    case BROADCAST:
    {
        printf("\n接收到来自|%s|的消息:%s\n",m->FromName,m->Content);
        break;
    }
    case ONLINELIST:
    {
        ShowOnlineList(m);
        break;
    }
    case SENDFILE:
    case DOWNLOAD:
    {
        int32_t size = 0;
        memcpy(&size,m->Content,sizeof(int));
        // 收到服务器的信息小包
        if(size == -2)
        {
            struct MetaInfo 
            {
                int32_t type;
                int64_t total_size;
            } __attribute__((packed));

            struct MetaInfo info;
            memcpy(&info,m->Content,sizeof(struct MetaInfo));

            totalFileSize = info.total_size;
            recvFileSize = 0;

            // 新建或者清空本地文件
            WriteToLocal(m,1,currentDownloadFileName);

            printf("\n开始下载文件,总大小: %ld 字节...\n",totalFileSize);
            PrintProgress(0,totalFileSize);
            break;
        }
        // 收到传输包
        if(size > 0)
        {
            WriteToLocal(m,0,NULL);
            recvFileSize += size;
            PrintProgress(recvFileSize,totalFileSize);
        }
        else if(size == -1)
        {
            PrintProgress(totalFileSize,totalFileSize);
            printf("\n网盘文件下载完成,已经保存到当前目录.\n");
            totalFileSize = 0;
            recvFileSize = 0;
            isDownloadFinished = true;
        }
        break;
    }
    case UPLOAD:
    {
        if(strcmp(m->Content,"UPDATEOK") == 0)
        {
            printf("\n上传文件成功!\n");
        }
        break;
    }
    case FILELIST:
    {
        ShowFileList(m);
        break;
    }
    }
}

void * ThreadHandle(void* arg)
{
    TcpC * c = (TcpC*)(arg);
    while(1)
    {
        MSG m;
        if(TcpClientRecv(c,&m,sizeof(m)) == false)
        {
            printf("读线程接收错误\n");
            exit(-1);
        }
        AnalysisRecv(&m);
    }
}

void LoginSignUp(TcpC*c)
{
    while(1)
    {
        int choice = LoginFace();
        MSG m;
        switch (choice)
        {
        case LOGIN:
            m = Login(MyName);
            TcpClientSend(c,&m,sizeof(MSG));
            if(TcpClientRecv(c,&m,sizeof(MSG)) == false)
            {
                exit(-1);
            }
            if(IsLoginSuccess(&m) == true)
            {
                return;
            }
            break;
        case SIGNUP:
            m = SignUp(MyName);
            TcpClientSend(c,&m,sizeof(MSG));
            if(TcpClientRecv(c,&m,sizeof(MSG)) == false)
            {
                exit(-1);
            }
            if(IsSignUpSuccess(&m) == true)
            {
                return;
            }
        default:
            break;
        }
        sleep(2);
        system("clear");
    }
}

void SendFileToServer(MSG * m ,TcpC *c)
{
    int currentFlag = m->flag;
    char *fileName = GetFileNameFromPath(m->Content);
    FILE *tempF = fopen(m->Content, "rb");

    int64_t totalFileSize = 0;
    if(tempF != NULL)
    {
        fseek(tempF, 0, SEEK_END);
        totalFileSize = (int64_t)ftell(tempF);
        fclose(tempF);
    }

    PackFile * pf = PacketFileInit(m->Content);
    if(pf == NULL)
    {
        printf("*错误* 无法打开本地文件: %s\n", m->Content);
        free(fileName);
        return;
    }

    printf("\n开始上传文件: %s, 总大小: %ld 字节...\n", fileName, (long)totalFileSize);
    PrintProgress(0, totalFileSize);

    int64_t sendFileSize = 0;

    while(IsFileEnd(pf) == false)
    {
        int size = 65536; 

        memset(m->Content, 0, sizeof(m->Content));
        
        ReadFromFile(pf, m->Content + 24, &size);

        if (size <= 0 && IsFileEnd(pf)) {
            break;
        }

        memcpy(m->Content, &size, sizeof(int));    
        strncpy(m->Content + 4, fileName, 19);      

        m->flag = currentFlag;
        TcpClientSend(c, m, sizeof(MSG));
        
        sendFileSize += size;
        PrintProgress(sendFileSize, totalFileSize);
        
        usleep(1000); 
    }

    usleep(30000); 

    int endSize = -1;
    memset(m->Content, 0, sizeof(m->Content));
    m->flag = currentFlag; 
    memcpy(m->Content, &endSize, sizeof(int));
    strncpy(m->Content + 4, fileName, 19); 
    
    TcpClientSend(c, m, sizeof(MSG));
    
    PrintProgress(totalFileSize, totalFileSize);
    printf("\n传输指令已送达，等待服务器确认...\n");

    free(fileName);
    ClearPacketFile(pf);
}



int main()
{
    TcpC* c = TcpClientInit("192.168.191.129",8080);
    if (c == NULL) 
    {
        perror("TcpClientInit 链接服务器失败");
        return -1;
    }
    LoginSignUp(c);    

    ThreadInit(ThreadHandle, c);

    while(1)
    {
        int choice = Interface();
        MSG m;

        switch(choice)
        {
        case CHAT:
            m = ChatToClient();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break;
        
        case BROADCAST:
            m = ChatBoradCast();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break; 

        case ONLINELIST:
            m = GetServerOnlineList();
            strcpy(m.FromName,MyName);
            TcpClientSend(c,&m,sizeof(m));
            break; 

        case SENDFILE:
            m = SendFile();
            strcpy(m.FromName,MyName);
            SendFileToServer(&m,c);
            break;
            
        case MYCLOUD:
        {
            bool inCloud = true;
            while(inCloud)
            {
                int cloudchoice = CloudInterface();
                switch(cloudchoice)
                {
                case FILELIST:
                {    
                    MSG m;
                    strcpy(m.FromName,MyName);
                    m.flag = FILELIST;
                    TcpClientSend(c,&m,sizeof(m));
                    break;
                }
                case UPLOAD:
                {
                    MSG m = UpLoadFile();
                    strcpy(m.FromName,MyName);
                    SendFileToServer(&m,c);
                    break;
                }
                case DOWNLOAD:
                {
                    MSG m = DownLoadFile();
                    //用户输入文件名备份全局变量
                    strncpy(currentDownloadFileName, m.Content, NameSize - 1); 

                    memset(m.FromName,0,sizeof(m.FromName));
                    strcpy(m.FromName,MyName);

                    isDownloadFinished = false;
                    TcpClientSend(c,&m,sizeof(m));

                    printf("\n=============正在下载文件==============\n");
                    while(!isDownloadFinished)
                    {
                        usleep(10000);
                    }
                    break;
                }
                case EXIT:
                {
                    inCloud = false;
                    break;
                }
                default:
                    break;
                }
            }
            printf("已退出网盘,返回聊天室主界面\n");
            sleep(1);
            break;
        }
        default:
            break;
        } 
    }
    return 0;
}
