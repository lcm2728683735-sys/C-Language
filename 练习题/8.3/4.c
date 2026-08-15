#include <stdio.h>
#include <math.h>
int main()
{
    int a = 1;
    int n = 3;
    int sum = 0;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        value = 10 * value + a;
        sum += value;
    }
    printf("sum = %d\n", sum);
    for (int i = 100; i <= 999; i++)
    {
        int units = i % 10;
        int hundred = i / 100;
        int decade = i % 100 / 10;
        if (i == pow(units, 3) + pow(hundred, 3) + pow(decade, 3))
        {
            printf("%d\n", 1);
        }
    }

    return 0;
}