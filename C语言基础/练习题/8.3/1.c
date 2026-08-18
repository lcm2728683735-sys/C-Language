#include <stdio.h>

int main()
{
    int num;
    printf("请输入一个整数:");
    scanf("%d", &num);
    if (num > 0)
    {
        printf("这个数字是正数\n");
    }
    else if (num == 0)
    {
        printf("这个数字是零\n");
    }
    else if (num < 0)
    {
        printf("这个数字是负数\n");
    }
    else
    {
        printf("这不是整数\n");
    }

    for (int a = 1; a <= 100; a++)
    {
        int b = a / 7;
    }
    return 0;
}
