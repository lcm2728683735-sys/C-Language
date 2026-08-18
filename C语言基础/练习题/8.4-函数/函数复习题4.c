#include <stdio.h>

int plus(int num)
{
    int sum = 0;
    for (int a = 1; a <= num; a++)
    {
        sum = sum + a;
    }
    return sum;
}
int main()
{
    int b = 11;
    printf("累加和为： %d\n", plus(b));
    return 0;
}