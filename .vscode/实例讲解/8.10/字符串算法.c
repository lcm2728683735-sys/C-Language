#include <stdio.h>
#include <strings.h>
//把整个字符串逆序
void Reserve(char *s,int len)
{
    for(int i = 0;i < len / 2;i++)
    {
        char temp = s[i];
        s[i] = s[len -1 -i];
        s[len - 1 - i] = temp;
    }
}

void Reserve2(char *s,int len)
{
    //记字符串长度
    int count = 0;
    for(int i = 0; i <= len ; i++)
    {
        //结束了一个单词
        if(s[1] == ' ' || s[i] == '\0')  
        {
            //一个单词逆序
            Reserve(s+i-count,count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
} 

int main()
{
    char s[] = "i am from nanjing";
    Reserve(s,strlen(s));
    Reserve2(s,strlen(s));
    printf("%s\n",s);
    return 0;
}