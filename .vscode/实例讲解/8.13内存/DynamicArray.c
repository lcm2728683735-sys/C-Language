#include <stdio.h>
#include "DynamicArray.h"
#include <stdlib.h>
#include <stdbool.h>

struct DynamicArray
{
    ElementType *a; // 指向堆上空间的指针
    int capacity;   // 定义数组的容量
    int size;//当前存放数据的数量
};
// 函数初始化
DArray *InitDArray(int capacity)
{
    DArray *ptr = (DArray *)malloc(sizeof(DArray)); // 堆上申请一个结构体变量
    if (ptr == NULL)
    {
        printf("申请DARRT失败!\n");
        return NULL;
    }
    // 定义结构体变量
    ptr->capacity = capacity;
    ptr->size = 0;
    ptr->a = (ElementType *)malloc(sizeof(ElementType) * capacity);
    if (ptr->a == NULL)
    {
        printf("申请堆上数组失败!\n");
        free(ptr);
        return NULL;
    }
    return ptr; // 返回结构体的指针
}

bool InsertTail(DArray *ptr, ElementType element)
{
    // 数组已满，扩容
    if (ptr->size >= ptr->capacity)
    {
        // 申请一个更大的空间，把之前的数据拷贝过来
        ElementType *newPtr = (ElementType *)malloc(sizeof(ElementType) * ptr->capacity * 2);

        if (newPtr == NULL)
        {
            printf("申请扩容失败");
            return false;
        }
        for (int i = 0; i < ptr->size; i++)
        {
            newPtr[i] = ptr->a[i];
        }
        free(ptr->a);
        ptr->a = newPtr;
        ptr->capacity *=2;
    }
    ptr->a[ptr->size++] = element;
}

void PrintArray(DArray *a,void (*printPrt)(ElementType))
{
    printf("DArray size : %d capacity : %d\n",a->size,a->capacity);
    for(int i = 0;i<a->size;i++)
    {
        printPrt(a->a[i]);
    }
    printf("\n");
}

void FreeDArray(DArray *a)
{
    free(a->a);
    free(a);
}

