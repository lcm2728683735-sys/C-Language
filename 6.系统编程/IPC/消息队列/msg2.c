#include <SysHeader.h>
#include <string.h>
struct Message
{
    long type;       //消息类型
    char text[1024]; //消息正文
};

int main()
{
    //IPC键值:标识系统中的唯一一个消息队列
    key_t key = ftok("./",1);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    //获得一个消息队列
    //msgget 打开或者创建一个消息队列
    int msgid = msgget(key,IPC_CREAT | 0666);
    if(msgid < 0)
    {
        perror("msgget");
        return -1;
    }

    struct Message m;

    //msgflg:0:阻塞直到写入消息
    //IPC_NOWAIT:不阻塞
    // MSG_NOERROR:有错误不通知 

    //msgsz : 传的是消息内容的大小
    //msgrcv接收消息队列中一条消息
    msgrcv(msgid,&m,sizeof(m.text),1,0);
    printf("%s\n",m.text);

    //消息队列的控制
    //msqid_ds:消息队列的备份
    // #define IPC_RMID	0		/* Remove identifier.  */
    // #define IPC_SET  1		/* Set `ipc_perm' options.  */
    // #define IPC_STAT	2		/* Get `ipc_perm' options.  */
    //msgctl控制消息队列 IPC_RMID为删除
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}