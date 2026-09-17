#include <iostream>
#include <fstream> //文件流

int main()
{
    // std::ofstream f("./telephone.txt");
    // if(!f.is_open())
    // {
    //     std::cout << "打开文件失败！\n";
    //     return -1;
    // }
    // std::cout << "打开文件成功！" << std::endl;
    // f << "hello"<< "\n" << "world" ;
    // f.close();

    // std::ifstream input("./telephone.txt");
    // if(!input.is_open())
    // {
    //     std::cout << "打开文件失败！\n";
    //     return -1;
    // }
    // while(input.eof() == false)
    // {
    //     std::string str;
    //     input >> str;
    //     std::cout << "读到字符串：" << str <<std::endl;
    // }


    // std::ifstream input("./telephone.txt");
    // input.seekg(5);
    // input.seekg(0,std::ios::end);
    // auto size = input.tellg();
    // std::cout << size << std::endl;
    // input.close();

    // std::fstream f("./ telephone.txt",std::ios::app);
    // std::cout << f.tellp() << std::endl;
    return 0;
}