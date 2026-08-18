#include <stdio.h>

int main()
{
    int a[4] = {2016, 2017, 2018 ,2019};
    int *ptr1 = (int *)(&a + 1);
    int *ptr2 = (int *)((unsigned long)a + 1);
    printf("%x, %x\n", ptr1[-1], *ptr2);
    return 0;
} 