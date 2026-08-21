#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "JudgeNum.h"
#include "input.h"
#include "sorter.h"

int main()
{
    char *test_data[] = {126, -753, -146, 528, -121, 314, -624, 105, 999, -520, 234, 546, 236, -786, -623, 124, 534, 856, 153, 157, -853, -236};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    JudgeNum(test_data);
    ValidStruct(test_data, size);
    int data[25];
    for (int i = 0; i < size; i++)
    {
        data[i] = atoi(test_data[i]);
    }
    BubbleSort(data, size);
}