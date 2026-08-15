#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
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

// 插入排序
void InsertSort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = a[i];
        for (int j = i; j >= 0; j--) // 倒序插入
        {
            if (a[j - 1] > temp)
            {
                a[j] = a[j - 1]; // 比插入大的数往后挪
            }
            else
            {
                break;
                a[j] = temp;
            }
        }
    }
}

// 选择排序
void ChooseSort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        Swap(&a[i], &a[min]);
    }
}

// 双指针算法
void ChooseSort2(int *a, int size)
{
    for (int left = 0, right = size - 1; left < right; left++, right--)
    {
        int min = left, max = right;
        for (int i = left; i <= right; i++)
        {
            if (a[min] > a[i])
            {
                min = i;
            }
            if (a[max] < a[i])
            {
                max = i;
            }
        }
        Swap(&a[left], &a[min]);
        //极值都在两边
        if(max == left)
        {
            max = min;
        }
        Swap(&a[right], &a[max]);
    }
}

//快速排序
void FastSort(int *a,int start,int end)
{

    if(start >= end)
        return;
    int left = start;
    int right = end;
    int temp = a[left];

    while(left < right)
    {
        while (a[right] > temp && left < right)
            right--;
        if(left < right)
            a[left++]= a[right];
        while(a[left] < temp && left < right)
            left++;
        if(left < right)
            a[right--] = a[left];
    }
    a[left] = temp;
    FastSort(a,start,left-1);
    FastSort(a,right + 1,end);
}
int main()
{
    int a[5];
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        a[i] = rand() % 100;
    }
    print(a, sizeof(a) / sizeof(a[0]));
    FastSort(a, 0 , 4);
    print(a, sizeof(a) / sizeof(a[0]));
    return 0;
}