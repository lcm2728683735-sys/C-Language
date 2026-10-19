#include "StdSem.h"
#include <SysHeader.h>

StdSem::StdSem(const std::string &filepath, int proID, int shmSize)
{
    key_t key = ftok("./",1);
    if(key < 0)
    {
        perror("ftok");
        exit(-1);
    }

    //获取信号量
    semid = semget(key,1,IPC_CREAT | 0666);
    if(semid < 0)
    {
        perror("semget");
        exit(-1);
    }
    //semnum : 信号量的下标
    semctl(semid,0,SETVAL,1); //给下标为0的信号量置为1

}

bool StdSem::Remove()
{
    return semctl(semid,0,IPC_RMID) >=0;
}

void StdSem::P()
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1; //P
    buf.sem_flg = SEM_UNDO;
    semop(semid,&buf ,1);
}
void StdSem::V()
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = 1; //V
    buf.sem_flg = SEM_UNDO;
    semop(semid,&buf ,1);
}
