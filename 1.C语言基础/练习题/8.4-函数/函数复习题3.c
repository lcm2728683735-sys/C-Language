#include <stdio.h>
void print_double(int a)
{
    int count = 0;
    for (int i = 2; i <= a; i += 2)
    {
        printf("%d ", i);
            count++;
        if (count % 10 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{ 
    {
        int x = 100;
        printf("1到%d所有偶数,每行10个数字如下:\n", x);
        print_double(x);
        return 0;
    }
}