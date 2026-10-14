#include <stdio.h>

void PrintArray(int (*a)[3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int n = 0; n < 3; n++)
        {
            printf("%d", a[i][n]);
        }
        printf("\n");
    }
}

int main()
{

    int a[2][3] =
        {
            {1, 2, 3},
            {4, 5, 6}};
    PrintArray(a, 2);
    // int (*p)[3];
    // int a[3] = {1,2,3};
    // p = &a;
    // printf("%d\n",*(*p));
    return 0;
}