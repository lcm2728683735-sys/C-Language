#include <stdio.h>

int main()
{
    int num;
    int sum = 0;
    while (1)
    {
        printf("请输入一个整数:");
        scanf("%d", &num);
        if(num == -1)
            break;
        sum += num;
    }
    printf("sum:%d\n",sum);
    return 0;
}