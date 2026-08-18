#include <stdio.h>
int main()
{
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", j);
    //     }
    //     printf("\n");
    // }


    // for (int i = 1; i <= 3; i++)
    // {
    //     for(int k = 0;k<3-i;k++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < 2 * i - 1; j++)
    //     { 
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    
    // for (int i = 1; i <= 3; i++)
    // {
    //     for(int k = 0 ;k<3-i;k++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < 2 * (3 - i) - 1; j++)
    //     { 
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    int row;
    printf("输入菱形边长数：");
    scanf("%d ", &row);
    for (int i = 1; i <= row/2 + 1 ; i++)
    {
        for(int k = 0 ;k<row/2 + 1 - i;k++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++)
        { 
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= row/2 ; i++)
    {
        for(int k = 0 ;k < i;k++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * (row / 2 + 1 - i) - 1 ; j++)
        { 
            printf("*");
        }
        printf("\n");
    }
    return 0;
}