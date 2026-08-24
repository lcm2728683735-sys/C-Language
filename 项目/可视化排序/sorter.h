#include <stdio.h>
#include <stdlib.h>
#ifndef __SORTER_H_
#define __SORTER_H_

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

typedef void(* PrintFunc)(int idx1,int idx2 ,UI Sort);

void PrintUI(UI ui);

void print(int *arr, int size);

void Swap(int *a, int *b);

void RefreshUI(const int *arr, int size, UI Sort);

void BubbleSort(int *arr, int size);


#endif