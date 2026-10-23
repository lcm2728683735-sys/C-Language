#ifndef __CLIENTFUNC_H__
#define __CLIENTFUNC_H__

#include "../GlobalMessage.h"

//功能选择界面
int Interface();
//私聊
MSG CharToClient();
//广播
MSG ChatBoradCast();

MSG GetServerOnlineList();

#endif