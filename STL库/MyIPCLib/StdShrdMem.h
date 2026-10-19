#ifndef __STDSHRDMEM_H__
#define __STDSHRDMEM_H__

#include <string>
class StdShrdMem
{
public:
    StdShrdMem(const std::string& filepath,int proID,int shmSize = 4096);
    ~StdShrdMem() =default;
    bool Write(void * data,size_t size);
    bool Read(void * data,size_t size);
    bool Remove();
private: 
    int shmid;
    int m_shmsize;
};
#endif 