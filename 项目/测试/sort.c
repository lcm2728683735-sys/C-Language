#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序
void BubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                Swap(&arr[j], &arr[j + 1]);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
