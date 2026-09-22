#include "FileTools.h"

int main ()
{
    std::string name = "zhangsan";
    FileTools::MakeDir("./存档/" + name);
    FileTools::MakeDir("./存档/" + name +"/存档1");
    FileTools::MakeDir("./存档/" + name +"/存档2");
    FileTools::MakeDir("./存档/" + name +"/存档3 ");
    return 0;
}