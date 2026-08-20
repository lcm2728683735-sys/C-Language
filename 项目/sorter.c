#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "input.h"

struct UI
{
    const char *Sort;
    int pass;
    int step;
    int compare_count;
    int swap_count;
    const char *status;
};
typedef struct UI UI;





void PrintUI(UI ui)
{
    printf("=====================================\n");
    printf("算法：%s\n", ui.Sort);
    printf("第 %d 趟 | 第 %d 步\n", ui.pass, ui.step);
    printf("比较次数 : %d 交换次数 : %d\n", ui.compare_count, ui.swap_count);
    printf("当前操作 : %s\n", ui.status);
    printf("=====================================\n");
}


void RefreshUI(const int *arr, int size, UI Sort)
{
    printf("\033[H\033[J");
    PrintUI(Sort);
    PrintBar(arr, size);
}

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
    UI Bubble =
        {
            "冒泡排序",
            0,
            0,
            0,
            0,
            "准备开始排序。。。"};

    for (int i = 0; i < size - 1; i++)
    {
        Bubble.pass = i + 1;
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            char status[64];
            Bubble.step++;
            Bubble.compare_count++;
            snprintf(status, sizeof(status), "正在比较 %d 和 %d", arr[j], arr[j + 1]);
            Bubble.status = status;
            RefreshUI(arr, size, Bubble);
            usleep(100000);
            if (arr[j] > arr[j + 1])
            {

                flag = 1;
                snprintf(status, sizeof(status), "正在交换 %d 和 %d", arr[j], arr[j + 1]);
                Swap(&arr[j], &arr[j + 1]);
                Bubble.swap_count++;
                Bubble.status = status;
            }
            RefreshUI(arr, size, Bubble);
            usleep(200000);
        }
        if (flag == 0)
        {
            break;
        }
    }
    Bubble.status = "排序完成";
    RefreshUI(arr, size, Bubble);
}

int main()
{
    int test_data[] = {528, -121, 314, -624, 105, 999, -50, 234};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    BubbleSort(test_data,size);
}