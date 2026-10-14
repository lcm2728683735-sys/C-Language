#include <stdio.h>
int main ()
{
    int *a =(int *)calloc(3,sizeof(int));
    if(a== NULL)
    {
        printf("callo");
        return -1;
    }
    for(int i =0;i <3;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}