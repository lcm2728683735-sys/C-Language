#include <stdio.h>
#include <string.h>

int MyStrlen(const char * str)
{
    int count =0;
    while(*str++ != '\0' )
    {
        count++;
    }
    return count;
}

int main ()
{
    char *a = {"abcd"};
    int b = MyStrlen(a);
    printf("%d\n",b);
    return 0;
}
