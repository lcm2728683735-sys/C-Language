#include <iostream>
#include "StdFile.h"

int main()
{
    //std::cout << StdFileTools::IsExist("11.txt") << std::endl;
    // StdFileTools::CopyFile("test.png","stop.png");
    std::cout << StdFileTools:: ReadAll("笔记.md")<< std::endl;
    auto arr = StdFileTools::ReadLines("1.txt");

    for(auto &line : arr)
    {
        std::cout <<line <<std::endl;
    }
    return 0;
}