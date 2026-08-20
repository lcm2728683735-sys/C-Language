#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define Max_Length 50

#define Color_Yellow "\033[33m"
#define Color_Red "\033[31m"
#define Color_Green "\033[32m"
#define Color_Reset "\033[0m"

int CountSize(const int *arr)
{
    int Size = sizeof(arr) / sizeof(arr[0]);
    return Size;
}

int GetMaxAbs(const int *arr, int size)
{
    int max_abs = abs(arr[0]);
    for (int i = 1; i < size; i++)
    {
        if (abs(arr[i]) > max_abs)
        {
            max_abs = abs(arr[i]);
        }
    }
    return max_abs;
}

void PrintBar(const int *arr, int size)
{
    int Max_Value = GetMaxAbs(arr, size);
    printf("===================================================柱状图===============================================\n");
    for (int i = 0; i < size; i++)
    {
        int Bar_Length = (int)(((float)abs(arr[i]) / Max_Value) * Max_Length);
        printf(Color_Green);
        printf("元素 %d (%4d):", i, arr[i]);
        // 上色
        if (arr[i] < 0)
        {
            if (Bar_Length > 0)
            {
                printf("%s█%s", Color_Red, Color_Reset);
            }
            printf(Color_Green);
            for (int j = 1; j < Bar_Length; j++)
            {
                printf("█");
            }
            printf("%s\n",Color_Reset);
        }
        else
        {
            printf(Color_Green);
            for (int j = 1; j < Bar_Length; j++)
            {
                printf("█");
            }
            
            printf("\n");
        }
    }
    printf(Color_Reset);
    printf("========================================================================================================\n");
}

// int main()
// {
//     int num[] = {-124, 563, 624, -745, 234};
//     int size = sizeof(num) / sizeof(num[0]);
//     PrintBar(num, size);
//     return 0;
// }
