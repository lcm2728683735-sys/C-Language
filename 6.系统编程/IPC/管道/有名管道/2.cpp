#include <StdFIFO.h>
#include <iostream>
int main ()
{
    StdFIFO fw("myfifo",StdFIFO::mode::WriteOnly);
    std::string s;
    std::cin >> s;
    fw.Write(s);
    return 0;
}