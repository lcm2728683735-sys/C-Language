#include <stdio.h>
int leap(int a)
{
    if (a % 4 == 0 && a % 100 != 0)
    {
        return 1;
    }
    else if (a % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int i = 2023;

    if (leap(i) == 1)
    {
    printf("这是闰年\n");
    }
    else
    {
    printf("这不是闰年\n");
    }
    return 0;
}