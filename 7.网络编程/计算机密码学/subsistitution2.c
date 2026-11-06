#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LetterFrequenence
{
    char letter;
    int frequence;
};

typedef struct LetterFrequenence LF;

int Compare(const void * p1,void * p2)
{
    return ((LF*)p1)->frequence - ((LF*)p2)->frequence;
}




int main()
{
    char msg[10240] = {0};
    FILE *f = fopen("./1.txt","r");
    int pos = 0;
    while(feof(f) == 0)
    {
        int size = 0;
        size = fread(msg + pos,1024,1,f);
        pos += size;
    }
    fclose(f);

    char letters[] = "etaoinshrdlcumwfgypbvkjxqz";

    LF lf[27];
    for(int i =0; i < 26;i++)
    {
        lf[i].letter = letters[i];
        lf[i].frequence = 0;
    }
    int i =0;
    while(msg[i] != '\0')
    {
        lf[msg[i] - 'a'].frequence++;
        i++;
    }

    qsort(lf,26,sizeof(LF),Compare);
    for(int i =0; i < 26;i++)
    {
        printf("%c : %c\n",'a' + i,lf[i].letter);
    }

    for(int i = 0 ; i < strlen(msg); i++)
    {
        if(msg[i] <= 'z' && msg[i] >= 'a')
        {
            for(int j = 0;j < 26;j++)
            {
                if(msg[i] == lf[i].letter)
                {
                    msg[i] = 'a' + j; 
                    break;
                }
            }
        }
    }
    printf("解密:%s\n",msg);
    return 0;
}