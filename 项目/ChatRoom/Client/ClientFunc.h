#ifndef __CLIENTFUNC_H__
#define __CLIENTFUNC_H__

#include "../GlobalMessage.h"

//功能选择界面
int Interface();
//私聊
MSG CharToClient();
//广播
MSG ChatBoradCast();
//查看在线用户
MSG GetServerOnlineList();
//解析列表字符串
void ShowOnlineList(MSG *m);

void SendFile(const char * FilePath);

struct PacketFile;
typedef struct PacketFile PackFile;

PackFile * PacketFileInit(const char *filePath);
void ReadFromFile(PackFile * f,void * p ,int * size);

bool IsFileEnd(PackFile *f);
#endif