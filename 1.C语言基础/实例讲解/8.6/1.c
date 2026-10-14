#include <stdio.h>
#include <stdio.h>

int multiply(int n)
{
    for(int i = 0;i<=n;i++)
    {
        for(int x = 1;x < i;x++)
        {
            printf("%d*%d=%2d  ",i,x,i * x);
        }
        printf("\n");
    }
}

int main()
{
    int a = 9;
    printf("%d\n",multiply(a));
    return 0;
} 