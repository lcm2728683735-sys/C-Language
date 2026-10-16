#ifndef __STDFILE_H__
#define __STDFILE_H__
#include <string>
#include <vector>

using strArr = std::vector<std::string>;
class StdFileTools
{
public:
    static bool IsExist(const std::string &path);
    static long FileSize(const std::string & path);
    static bool CreateFile(const std::string & path);
    static void CopyFile(const std::string &destPath,const std::string& srcPath);
    static std::string ReadAll(const std::string &path);
    static strArr ReadLines(const std::string & path);
};


#endif