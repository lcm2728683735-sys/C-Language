#include <StdFIFO.h>
#include <iostream>
int main ()
{
    StdFIFO fr("myfifo",StdFIFO::mode::ReadOnly);
    std::cout <<fr.Read(1024) << std::endl;

    return 0;
}