#include <iostream>
#include <fstream>

template <typename T>
void WriteLog(const std::string & filePath,const T& logMsg)
{   
    std::ofstream f(filePath,std::ios::app);
    if(!f.is_open())
    {
        std::cout << "文件打开失败"<< std:: endl;
        return;
    }
    f  << logMsg << "\n";
}

int main ()
{
    WriteLog("app.log","写入文本日志");
    WriteLog("app.log","2026.9.18");
    return 0;
}