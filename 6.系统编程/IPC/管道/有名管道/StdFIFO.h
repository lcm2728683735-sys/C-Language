#ifndef __STDFIFO_H__
#define __STDFIFO_H__

#include <string>

class StdFIFO
{
public:
    enum class mode
    {
        ReadOnly,
        WriteOnly,
    };
    StdFIFO(const std::string & filepath,mode m);
    ~StdFIFO();
    std::string Read(size_t size);
    void Write(const std::string &str);

private:
    int fd;
    mode m;
    std::string filePath;
};


#endif