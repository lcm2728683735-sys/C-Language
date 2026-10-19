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

    //获取信号量
    int semid = semget(key,1,IPC_CREAT | 0666);
    if(semid < 0)
    {
        perror("semget");
        return -1;
    }
    //semnum : 信号量的下标
    semctl(semid,0,SETVAL,0); //给下标为0的信号量置为1

    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1; //P
    buf.sem_op = 1; //V
    buf.sem_flg = SEM_UNDO;
    // struct sembuf *结构体数组指针 可以同时修改多个信号量
    semop(semid,&buf ,1);
    return 0;
}