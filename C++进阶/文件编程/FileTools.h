#ifndef __FILETOOLS_H__
#define __FILETOOLS_H__

#include <iostream>
#include <string>
#include <vector>
class FileTools
{
public:
    //读取文件中的所有内容
    static std::string ReadAll(const std::string& filePath);
    //按行读取文件
    static std::vector<std::string> ReadLine(const std::string& filePath);
    //覆盖写
    static bool WriteToFile(const std::string &filePath,const std::string &data);
    //追加写
    static bool AppendToFile(const std::string &filePath,const std::string &data);
    //按行写
    static bool WriteLine(const std::string& filePath,std::vector<std::string> & strVec);
    template <typename T>
    static bool WriteLine(const std::string & filePath, T&Container)
    {
        std::vector<std::string> v;
        for(auto & value : Container)
        {
            v.push_back(value); 
        }
        return WriteLine(filePath,v);
    }

    
    static bool AppendLine(const std::string& filePath,std::vector<std::string> & strVec);
    template <typename T>
    static bool AppendLine(const std::string & filePath, T&Container)
    {
        std::vector<std::string> v;
        for(auto & value : Container)
        {
            v.push_back(value); 
        }
        return AppendLine(filePath,v);
    }
};
    


#endif


