#include <stdio.h>
#include <stdlib.h>
#ifndef __INPUT_H_
#define __INPUT_H_


struct InputArray
{
    char **array;
    int size;
};
typedef struct InputArray InputArray;

int CountSize(const int *arr);

int GetMax(const int *arr,int size);

void PrintBar(const int *arr,int size);

#endif