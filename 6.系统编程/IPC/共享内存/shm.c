#include <SysHeader.h>
#include <string.h>
int main ()
{
    //获取键值
    key_t key = ftok("./",1);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }

    //获取共享内存
    int shmid = shmget(key,4096,IPC_CREAT | 0666);
    if(shmid < 0)
    {
        perror("shmget");
        return -1;
    }
    return 0;

    //attach:映射
    //将共享内存的地址映射到进程中
    //shmaddr : NULL由系统自动分配映射地址
    //shmfly : 0可读可写的权限
    //SHM_RDONLY:只读权限
    char * ptr = shmat(shmid,NULL,0);

    printf("%s\n",ptr);

    //detach : 接触映射
    shmdt(ptr);
    //SHM_LOCK: 不允许进行内存交换：不允许把共享内存交换到虚拟机中
    //SHM_UNLOCK
    //shmctl(shmid,IPC_RMID)
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}