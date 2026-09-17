#include "FileTools.h"
#include <iostream>


int main ()
{
    // std::cout<<FileTools::ReadAll("./文件编程")<<std::endl;

    // auto vec = FileTools::ReadLine("./文件编程");
    // for(auto & value:vec)
    // {
    //     std::cout<< value <<std::endl; 
    // }

    // FileTools::WriteToFile("./new.txt",FileTools::ReadAll("./文件编程"));
    // FileTools::AppendToFile("./new.txt",FileTools::ReadAll("./文件编程"));
    std::vector<std::string> v = { "zhangsan","lisi","wangwu"};
    FileTools::AppendLine("./new.txt",v);
    return 0;
}