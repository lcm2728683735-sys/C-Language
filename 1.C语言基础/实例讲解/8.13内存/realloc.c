#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = (int *)malloc(sizeof(int)*2);
    if(a == NULL)
    {
    printf("malloc error!\n");
    return -1;
    }
    a[0] = 10;
    a[1] =20;

    for(int i = 0;i < 2;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("a address : %p\n",a);

    int *b = (int *)realloc(a,sizeof(int)*10240);
    if(b == NULL)
    {
        printf("realloc error!\n");
        return -1;
    }
    a[2]=30;
    a[3]=40;
    for(int i = 0;i<4;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("b address : %p\n",b);
    return 0;
}