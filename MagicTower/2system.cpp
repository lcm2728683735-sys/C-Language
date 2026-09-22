#include <iostream>

int main()
{
    std::string cmd = std::string("mkdir ") + "text";
    system(cmd.c_str());
    return 0; 
}