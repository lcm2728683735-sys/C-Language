#ifndef __DYNAMICARRAY_H_
#define __DYNAMICARRAY_H_
#include <stddef.h>
using ElementType = int;
class DynamicArray
{
public: 
    DynamicArray(size_t capacity = 10);   
    DynamicArray(const DynamicArray & a);
    DynamicArray& operator = (const DynamicArray& a);
    ~DynamicArray();
    size_t Size();
    void ReSize(size_t capacity);
    void InsertTail(const ElementType& element);
    void InsertHead(const ElementType& element);
    void InsertByIndex(int Index,const ElementType& element);
    void RemoveByIndex(int index);
    void RemoveByElement(const ElementType & element);
    ElementType* FindByIndex(int index);
    DynamicArray FindByElement(const ElementType & element);
    void UpdateByIndex(int index,const ElementType& element);
    void UpdataByElement(const ElementType& oldValue,const ElementType & newValue);
    void DynamicArray::FastSort(size_t start,size_t end);
    void DynamicArray::InsertSort();
    void show();
private:
    void FastSort(size_t start,size_t end);
    ElementType *array;
    int size;
    int capacity;
};

#endif