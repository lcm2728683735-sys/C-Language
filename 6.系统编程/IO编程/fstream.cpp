#include <fstream>
#include <iostream>
int main ()
{
    std::fstream f("1.txt",std::ios::in);
    if(f.is_open())
    {
        std::cout <<"文件已打开" << std::endl;
    }
    else
    {
        std::cout << "文件未打开！" << std::endl;
    }

    std::string str;
    while(!f.eof())
    {
        char str[100];
        f.read(str,100);
        std::cout <<str <<std::endl;
    }
    f.seekg(std::ios::beg);
    f.close();

    std::ofstream f_out("1.txt",std::ios::app);
    if(!f.is_open())
        return -1;
    
    f<<"hellowrold\n" <<"nihao";
    std::string s = "hello,jack";
    f.write(s.c_str(),s.size());

    f.close();

    return 0;
}