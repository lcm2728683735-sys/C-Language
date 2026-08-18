#include <stdio.h>
#include <string.h>

void RemoveString(char * s,const char*s2)
{
    char*dest = strstr(s,s2);
    if(dest == NULL)
    return; 
    char*next = dest+strlen(s2);
    while(*next != '\0')
    {
        *dest++ = *next++;
    }
    *dest = '\0';
}
int main()
{
    char b[] = "helloworld";
    RemoveString(b,"world");
    printf("%s\n",b);
    return 0;
} 