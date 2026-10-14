#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOKSTR " "

char *MyStrtok(char *a, char *b)
{
    static char * str;

    if(a == NULL)
    {
        a = str;
    }

    if(a == NULL)
    {
        return NULL;
    }

    //找到第一个有效字符
    while(*a != '\0')
    {
        char temp[2] = {*a,'\0'};
        //当前字符是要被删除的字符
        if(strstr(b,temp) != NULL)
        {
            a++;
        }
        else
        {
            break;
        }
    }

    char * res = a;

    while(*a != '\0')
    {
        char temp[2] = {*a,'\0'};
        if(strstr(b,temp) == NULL)
        {
            a++;
        }
        else
        {
            *a = '\0';
            a++;
            break;
        }
    }

    if(*a != '\0')
    {
        str = a;
    }
    else
    {
        str = NULL;
    }

    return res;
}

int main()
{
    char temp2[] = "hello world!eee";
    char *temp = MyStrtok(temp2,TOKSTR);

    while(temp != NULL)
    {
        printf("%s\n",temp);
        temp = MyStrtok(NULL,TOKSTR);
    }



    return 0;
}