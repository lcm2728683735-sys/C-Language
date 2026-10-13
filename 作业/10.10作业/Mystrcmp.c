#include <stdio.h>
#include <string.h>

int MyStrcmp(const char * find,const char * str)
{
    while(*find != '\0' && *str != '\0' && *find == *str)
    {
        find++;
        str++;
    }
    return *find - *str;
}

int main()
{
    char a[] = "helloworld";
    char b[] = "hello";
    int c = MyStrcmp(a,b);
    printf("%d\n",c);
    return 0;
}