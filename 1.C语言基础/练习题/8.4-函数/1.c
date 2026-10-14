#include <stdio.h>
int IsPrime(int num)
{
    if(num == 2)
    return 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int num = 7856756;
    for (int a = 1; a < num; a++)
    {
        if ( IsPrime(a)&& IsPrime(num-a))
        {
            printf("有这两个质数组成: %d 和 %d\n", a, num -a);
            break;
        }
    }
    return 0;
}
