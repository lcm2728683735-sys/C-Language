#include "StdFile.h"
#include <fstream>


bool StdFileTools::IsExist(const std::string &path)
{
    std::ifstream f(path,std::ios::in);
    if(!f.is_open())
        return false;
    f.close();
    return true;
}

long StdFileTools::FileSize(const std::string &path)
{
    std::ifstream f(path,std::ios::ate);
    if(!f.is_open())
        return false;
    f.close();
    std::streamsize size = f.tellg();
    return static_cast<long>(size);
}

bool StdFileTools::CreateFile(const std::string &path)
{
    std::ofstream f(path,std::ios::out);
    if(!f.is_open())
        return false;
    f.close();
    return true;
}

void StdFileTools::CopyFile(const std::string &destPath, const std::string &srcPath)
{
    std::ifstream in (srcPath,std::ios::in);
    if(!in.is_open())
        return;
    std::ofstream out(destPath,std::ios::out);
    if(!out.is_open())
    {
        in.close();
        return;
    }
    while(!in.eof())
    {
        char str[1024] ={0};
        in.read(str,1024);
        out.write(str,1024);
    }
    in.close();
    out.close();
}

std::string StdFileTools::ReadAll(const std::string &path)
{
    std::string result;
    std::ifstream f(path,std::ios::in);
    if(!f.is_open())
        return {};
    while(!f.eof())
    {
        char str[1024] = {0};
        f.read(str,1024);
        result += str;
    }
    f.close();
    return result;
}

strArr StdFileTools::ReadLines(const std::string &path)
{
    strArr result;
    std::ifstream f(path,std::ios::in);
    if(!f.is_open())
        return {};  //默认的返回构造
    while(!f.eof())
    {
        std::string line;
        std::getline(f,line);
        if(line =="")
            continue;
        result.push_back(std::move(line));
    }
    f.close();
    return result;
}
