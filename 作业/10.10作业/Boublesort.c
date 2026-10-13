#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = 1;
                Swap(&a[j], &a[j + 1]);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}


int main()
{
    int a[] = {9, 1, 7, 3, 6, 5, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}