#include <stdio.h>

void PrintArray(int (*a)[3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", *(*(a + i) + j));
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

    int b[3] = {5, 6, 7};
    PrintArray(a, 2);

    printf("%p %p %p\n", a, &a, &a[0][0]);
    printf("%p %p %p\n", a + 1, &a + 1, &a[0][0] + 1);
    // a:数组指针
    //&a: 二维数组指针
    //&a[0][0]+1：int 元素指针

    // int *p = a+1;
    // printf("%d\n",*p);

    int (*p)[3] = a;
    printf("%d\n", *(*(p + 1)));
    printf("%d\n", *(p[0] + 1));
    printf("%d\n", *(*(p + 1) + 1));
    printf("%d\n", **(&p[0] + 1));

    // for(int i = 0;i<2;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         printf("%d",a[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("%d\n",a[0][0]);
    return 0;
}