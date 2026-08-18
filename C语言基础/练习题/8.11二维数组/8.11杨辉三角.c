#include <stdio.h>
#define Size 5

int main()
{
    int a[Size][Size] = {0};
    for (int i = 0; i < Size; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i < Size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (int i = 0; i < Size; i++)
    {
        for (int k = 0; k < Size - i - 1; k++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}