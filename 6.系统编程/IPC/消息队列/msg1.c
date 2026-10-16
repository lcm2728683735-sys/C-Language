#include<SysHeader.h>
#include <string.h>
struct Message
{
    long type;
    //消息类型
    char text[1024]; // 消息正文
};

int main()
{
    //IPC键值:标识系统中的唯一一个消息队列
    key_t key = ftok("./", 1);
    if (key < 0)

    {
    perror("ftok");
    return -1;
    }
    //获得一个消息队列
    //msgflag : 
    int msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid < 0)

    {
        perror("msgget");
        return -1;
    }

    struct Message m;
    m.type = 1;
    strcpy(m.text, "helloworld");

    //msgflg:0:阻塞直到写入消息
    //IPC_NOWAIT:不阻塞
    msgsnd(msgid, &m, sizeof(m), 0);
    return 0;
}