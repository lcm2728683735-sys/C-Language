#ifndef __DYNAMICARRAT_H_
#define __DYNAMICARRAT_H_
#define ElementType void*
#include <stdbool.h>
//定义动态数组结构体
struct DynamicArray;

typedef struct DynamicArray DArray;

DArray * InitDArray(int capacity);

bool InsertTail(DArray *ptr, ElementType element);


void PrintArray(DArray *a,void (*printPrt)(ElementType));

void FreeDArray(DArray *a);
#endif  