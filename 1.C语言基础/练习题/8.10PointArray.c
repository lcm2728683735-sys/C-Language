#include <stdio.h>

int main()
{
    char* s[2][3] = 
    {
        {"hello","world","jack"},
        {"你好","世界","杰克"},
    };
    printf("%c\n",s[0][0][0]);
    return 0;
}