#include "DynamicArray.h"
#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray(size_t capacity):size(0),capacity(capacity)
{
    array = new ElementType[capacity];
}

DynamicArray::DynamicArray(const DynamicArray & a)
{
    size = a.size;
    capacity = a.capacity;
    array = new ElementType[capacity];
    for(size_t i =0; i<size ;i++)
    {
        array[i] = a.array[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray &a)
{
    delete []array;
    size = a.size;
    capacity = a.capacity;
    array = new ElementType[capacity];
    for(size_t i = 0;i<size;i++)
    {
        array[i] = a.array[i];
    }
    return *this;
}

size_t DynamicArray::Size()
{
    return size;
}

void DynamicArray::ReSize(size_t capacity)
{
    this->capacity = capacity;
    this->size = (size > capacity)?capacity : size;

    ElementType *newP = new ElementType[capacity];
    for(size_t i = 0;i<size;i++)
    {
        newP[i] = array[i];
    }
    delete []array;
    array = newP;
}

void DynamicArray::InsertHead(const ElementType &element)
{
    if(size >= capacity)
        ReSize(2 * capacity);
    for(size_t i =size ; i > 0; i--)//O(n)
    {
        array[i] = array[i-1];
    }
    array[0] = element;
    size++;
}

void DynamicArray::InsertByIndex(int Index, const ElementType &element)
{
    if(Index < 0 ||Index > size)
        return;
    if(size >= capacity)
        ReSize(2 * capacity);
    for(size_t i =size ; i > Index; i--)//O(n)
    {
        array[i] = array[i-1];
    }
    array[Index] = element;
    size++;
}

void DynamicArray::RemoveByIndex(int index) 
{
    if(index < 0 || index >= size)
        return;
    for(size_t i = index;i<size-1;i++)
    {
        array[i] = array[i+1];
    }
    size--;
}

void DynamicArray::RemoveByElement(const ElementType &element)
{
    for(int i= 0;i<size;i++)
    {
        if(array[i] == element)
        {
            RemoveByIndex(i);
            i--;
        }
    }
}

ElementType *DynamicArray::FindByIndex(int index)
{
    if(index< 0 ||index >= size)
        return nullptr;
    return &array[index];
}  //O(1)

DynamicArray DynamicArray::FindByElement(const ElementType &element)
{
    DynamicArray result;
    for(int i = 0; i< size ;i++)
    {
        if(array[i] == element)
        {
            result.InsertTail(i);
        }
    }
    return result;
}

void DynamicArray::UpdateByIndex(int index, const ElementType &element)
{
    if(index < 0|| index >= size)
        return;
    array[index] = element;//O(1)
}

void DynamicArray::UpdataByElement(const ElementType &oldValue, const ElementType& newValue)
{
    for(int i = 0 ;i <size;i++)
    {
        if(array[i] == oldValue)
        {
            array[i] = newValue;
        }
    }
}

void DynamicArray::FastSort(size_t start,size_t end)
{
    if(start >= end)
        return;
}

void DynamicArray::InsertSort()
{
    for(size_t i = 0;i < size ;i++)
    {
        size_t j = i;
        ElementType temp = array[i];
        for(;j>0;j--)
        {
            if(array[j-1]>temp)
            {
                array[j] = array[j-1];
            }
        }
        array[j] = temp;
    }
}

DynamicArray::~DynamicArray()
{
    delete []array ;
}

void DynamicArray::InsertTail(const ElementType &element)
{
    //扩容
    if(size>= capacity)
        ReSize(2 * capacity);
    array[size++] = element;
}

void DynamicArray::show() 
{
    for(int  i = 0;i < size;i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}