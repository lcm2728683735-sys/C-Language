#include <stdio.h>

int main()
{
    // for(int i = 0;i < 300;i++)
    // {
    //     printf("%4d",i);
    // }
    // while(1);

    char a,b;
    scanf("%c", &a);
    while(getchar()!='\n');
    scanf(" %c", &b);
    printf("a = %c:%d b = %c:%d\n",a,a,b,b);
    return 0;
}