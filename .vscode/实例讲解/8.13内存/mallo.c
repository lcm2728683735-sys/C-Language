#include <stdio.h>
#include <stdlib.h>
int main()
{
    // int*a  = (int*)malloc(sizeof(int));
    // if(a ==NULL)
    // {
    //     printf("malloc error!\n");
    //     return -1;
    // }
    // *a = 10;
    // printf("%d\n",*a);
    // return 0;

    // int *a = (int*)malloc(10 * sizeof(int));
    // if (a ==NULL)
    // {
    //     printf("malloc error!\n");
    //     return -1;
    // }

    // for(int i = 0;i< 10;i++)
    // {
    //     a[i] = i + 1;
    //     printf("%d ",a[i]);
    // }
    // printf("\n");
    // free(a);

    int **a = (int **)malloc(2 * sizeof(int *));
    if (a == NULL)
    {
        printf("malloc error!\n");
        return -1;
    }

    for (int i = 0; i < 2; i++)
    {
        a[i] = (int *)malloc(3 * sizeof(int));
        if (a[i] == NULL)
        {
            printf("column malloc error!\n");
            return -1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            a[i][j] = i * 3 + j +1;
        }
        printf("\n");
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    free(a);
    return 0;
}