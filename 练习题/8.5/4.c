#include <stdio.h>
int main()
{
    long a[50] = {0};
    a[0]= 1;
    a[1] =1;
    for(int i = 3;i<=50;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    printf("%ld \n",a[50]);
    return 0;  
}