#include "StdFIFO.h"
#include <SysHeader.h>
StdFIFO::StdFIFO(const std::string &filepath, mode m)
{
    if(mkfifo(filepath.c_str(),S_IRUSR | S_IWUSR) < 0 && errno != EEXIST)
    {
        perror("create fifo error:");
        return;
    }
    fd = open(filepath.c_str(), static_cast<int>(m));
    if(fd < 0)
    {
        perror("Open fifo error:");
        return;
    }
    this->m = m;
}

StdFIFO::~StdFIFO()
{
    close(fd);
    std::string cmd = "rm -f" + filePath;
    system(cmd.c_str());
}

std::string StdFIFO::Read(size_t size)
{
    if(m == mode::WriteOnly)
    {
        printf("当前权限是写入,不能读取\n");
        return {};
    }
    char *s = new char[size];
    read(fd,s,size);
    std::string result(s);
    delete s;
    return result;
}

void StdFIFO::Write(const std::string &str)
{
    if(m == mode::ReadOnly)
    {
        printf("当前权限是读取，不能写入");
        return;
    }
    write(fd,str.c_str(),str.size());
}
