#include <stdio.h>

int main()
{
    int num = 7856743;
    for (int a = 2; a < num; a++)
    {
        if(num % a == 0)
        {
            printf("这不是质数: %d %d\n",a,num);  
            return -1;  
        }
    }
    printf("这是质数\n");
    return 0;
}