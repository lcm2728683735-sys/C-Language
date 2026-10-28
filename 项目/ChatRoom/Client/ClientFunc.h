#ifndef __CLIENTFUNC_H__
#define __CLIENTFUNC_H__

#include "../GlobalMessage.h"
#include <stdbool.h>
int LoginFace();
//注册
MSG SignUp(char * MyName);
//是否注册成功
bool IsSignUpSuccess(MSG * m);
//登录
MSG Login(char * MyName);
//是否登录成功
bool IsLoginSuccess(MSG *m);
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
//文件发送
MSG SendFile();
//获取文件路径
char * GetFileNameFromPath(const char * filePath);
//写数据到本地文件
void WriteToLocal(MSG *m);

struct PacketFile;
typedef struct PacketFile PackFile;

PackFile * PacketFileInit(const char *filePath);
void ReadFromFile(PackFile * f,void * p ,int * size);

bool IsFileEnd(PackFile *f);
void ClearPacketFile(PackFile *f);
#endif