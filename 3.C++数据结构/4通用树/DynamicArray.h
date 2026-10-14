#ifndef __DYNAMICARRAY_H_
#define __DYNAMICARRAY_H_
#include <stddef.h>
#include <limits.h>

namespace DARRAY
{
    

using ElementType = void*;
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
    ElementType& operator[](int index);
    DynamicArray FindByElement(const ElementType & element);
    void UpdateByIndex(int index,const ElementType& element);
    void UpdataByElement(const ElementType& oldValue,const ElementType & newValue);
    //排序  
    void Sort();
    void InsertSort(size_t start,size_t end); 
    void Duplicate();//去重
    DynamicArray Merge(const DynamicArray& a);//合并有序数列
    //找交集
    DynamicArray FdInterSctn(const DynamicArray & a);
    //并集
    DynamicArray FindUnionSet(const DynamicArray & a);
    //补集
    DynamicArray FindDifference(const DynamicArray & a);

    bool operator==(const DynamicArray & a);
    //二分查找
    size_t BinarySearch(const ElementType &element);
    //查找子数列
    bool IsChild(const DynamicArray & a);
    //查找连续子数列
    bool IsCntnsChild(const DynamicArray & a);
    //获取子序列
    DynamicArray subsequence(int index,size_t size);

    void SetFreePtr();
    void show();
private:
    void FastSort(size_t start,size_t end,size_t deepth,size_t MaxDepth);

    size_t Partition(size_t start,size_t end);
    ElementType *array; 
    size_t size;
    size_t capacity;
 
};
}

#endif