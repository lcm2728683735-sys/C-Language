#include "StdMsgQueue.h"
#include <SysHeader.h>
#include <cstring>

struct Message
{
    long type;       //消息类型
    char text[TextSize]; //消息正文
};

StdMsgQueue::StdMsgQueue(const std::string &filepath, int proID)
{
    key_t key = ftok(filepath.c_str(),proID);
    if(key < 0)
    {
        perror("ftok");
        exit(-1);
    }

    msgid = msgget(key,IPC_CREAT | 0666);
    if(msgid < 0)
    {
        perror("msgget");
        exit(-1);
    }
}

bool StdMsgQueue::Write(const long &type, const std::string &data)
{
    Message m;
    m.type = type;
    strncpy(m.text,data.c_str(),1024);

    if(msgsnd(msgid,&m,TextSize,0) < 0)
    {
        perror("msgsnd");
        return false;
    }
    return false;
}

std::string StdMsgQueue::Read(const long &type)
{
    Message m;
    if(msgrcv(msgid,&m,TextSize,type,0)<0)
    {
        return {};
    }
    return std::string(m.text);
}

bool StdMsgQueue::Remove()
{
    return msgctl(msgid,IPC_RMID,nullptr) >=0;
}
