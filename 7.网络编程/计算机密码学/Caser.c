#include <stdio.h>
#include <string.h>

void CaserEncrypt(char *s,int shift)
{
    for(int i = 0;i < strlen(s);i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + (s[i] - 'A' + shift)%26;
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + (s[i] - 'a' + shift)%26;
    }
}

void CaserDecrypt(char * s,int shift)
{
    CaserEncrypt(s,52 - shift);
}

int main()
{
    printf("0 : %d A: %d a : %d\n",'0','A','a');
    char Msg[100] = {0};
    printf("请输入要加密的数据：");
    scanf("%s",Msg);

    int shift = 0;
    printf("请输入偏移的位数:");
    scanf("%d",&shift);

    printf("原文:%s\n",Msg);

    CaserEncrypt(Msg,shift);
    printf("密文:%s\n",Msg);

    CaserDecrypt(Msg,shift);
    printf("明文:%s\n",Msg);


    return 0;
}