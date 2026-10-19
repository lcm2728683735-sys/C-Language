#include "StdShrdMem.h"
#include <SysHeader.h>
#include <cstring>

StdShrdMem::StdShrdMem(const std::string &filepath, int proID, int shmSize)
{
    key_t key = ftok(filepath.c_str(),proID);
    if(key < 0)
    {
        perror("ftok");
        exit(-1);
    }

    shmid = shmget(key,shmSize,IPC_CREAT | 0666);
    if(shmid < 0)
    {
        perror("msgget");
        exit(-1);
    }
    m_shmsize = shmSize;
}

bool StdShrdMem::Write(void *data, size_t size)
{
    void *ptr = shmat(shmid,nullptr,0);
    if((long)ptr == -1)
    {
        return false;
    }
    memcpy(ptr,data,std::min(static_cast<size_t>(m_shmsize), size));

    shmdt(ptr);
    return true;
}

bool StdShrdMem::Read(void *data, size_t size)
{
    void *ptr = shmat(shmid,nullptr,0);
    if((long)ptr == -1)
    {
        return false;
    }
    memcpy(data,ptr, std::min(static_cast<size_t>(m_shmsize),size));
    shmdt(ptr);
    return true;
}

bool StdShrdMem::Remove()
{
    return shmctl(shmid,IPC_RMID,nullptr)>= 0;
}
