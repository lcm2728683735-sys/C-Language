#include <stdio.h>
#define min(a,b) (a < b) ? a : b
int gcd(int a, int b) 
{
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            printf("这两个数的最大公约数为：%d\n", i);
            return i;
        }
    }
    return 1;
}
int main()
{
    int x=46457232;
    int y=52234222;
    printf("%d",gcd(x,y));
    return 0;
}