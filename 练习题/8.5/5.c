#include <stdio.h>
int main()
{
    int a[100] = {0};
    a[0] = 1;
    for (int i = 0; i < 100; i++)
    {
        for(int j = 0;j < 100; j++)
        {
            a[j] *=2;
        }
        for (int j = 0; j < 99; j++)
        {
            if (a[j] >= 10)
            {
                a[j + 1]++;
                a[j] -= 10;
            }
        }
    }
    for (int i = 99; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    int flag = 0;
    for(int i = 99;i>= 0;i--)
    {
        if(a[i] != 0)
        {
            flag = 1;
        }
        if(flag == 1)
        printf("%d",a[i]);
    }
    return 0;
}