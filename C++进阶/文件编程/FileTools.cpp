#include "FileTools.h"
#include <iostream>
#include <fstream>


std::string FileTools::ReadAll(const std::string &filePath)
{
    std::ifstream f(filePath);
    if(!f.is_open())
    {
        std::cout << filePath << "文件打开失败!\n";
        return {}; 
    }
    f.seekg(0,std::ios::end);
    long size = f.tellg();
    f.seekg(0,std::ios::beg);

    char *p = new char [size+1];
    f.read(p,size);
    std::string data = p;
    delete[]p;

    f.close();
    return data;
}

std::vector<std::string> FileTools::ReadLine(const std::string& filePath)
{
    std::ifstream f(filePath);
    if(!f.is_open())
    {
        std::cout << filePath << "文件打开失败!\n";
        return {}; 
    }
    std::vector<std::string> vec;
    std::string lineData;
    while(std::getline(f,lineData))
    {
        std::string LineData;
        std::getline(f,LineData);
        if(LineData != "")
            vec.push_back(std::move(LineData));
    }
    f.close();
    return vec;
}

bool FileTools::WriteToFile(const std::string &filePath, const std::string &data)
{
    std::ofstream f(filePath);
    if(!f.is_open())
    {
        std::cout << filePath << "打开失败!\n";
        return false;
    }
    f.write(data.c_str(),data.size());
    f.close();
    return true;
}

bool FileTools::AppendToFile(const std::string &filePath, const std::string &data)
{
    std::ofstream f(filePath,std::ios::app);
    if(!f.is_open())
    {
        std::cout << filePath << "打开失败!\n";
        return false;
    }
    f.write(data.c_str(),data.size());
    f.close();
    return true;
}

bool FileTools::WriteLine(const std::string &filePath, std::vector<std::string> &strVec)
{
    std::ofstream f(filePath);
    if(!f.is_open())
    {
        std::cout << filePath << "打开失败!\n";
        return false;
    }
    for(auto & str :strVec)
    {
        f.write(str.c_str(),str.size());
        f << "\n";
    }
    f.close();
    return true;
}

bool FileTools::AppendLine(const std::string &filePath, std::vector<std::string> &strVec)
{
    std::ofstream f(filePath,std::ios::app);
    if(!f.is_open())
    {
        std::cout << filePath << "打开失败!\n";
        return false;
    }
    for(auto & str :strVec)
    {
        f.write(str.c_str(),str.size());
        f << "\n";
    }
    f.close();
    return true;
}
