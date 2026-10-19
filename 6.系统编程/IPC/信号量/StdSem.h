#ifndef __STDSEM_H__
#define __STDSEM_H__

#include <string>
class StdSem
{
public:
    StdSem(const std::string& filepath,int proID,int shmSize = 4096);
    ~StdSem() =default;
    bool Remove();
    void P();
    void V();
private: 
    int semid;
};
#endif 