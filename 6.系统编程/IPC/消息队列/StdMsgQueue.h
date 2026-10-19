#ifndef __STDMSGQUEUE_H__
#define __STDMSGQUEUE_H__

#include <string>

const int TextSize = 1024;

class StdMsgQueue
{
public:
    StdMsgQueue(const std::string& filepath,int proID);
    ~StdMsgQueue() =default;
    bool Write(const long& type,const std::string &data);
    std::string Read(const long& type);
    bool Remove();
private: 
    int msgid;
};

#endif