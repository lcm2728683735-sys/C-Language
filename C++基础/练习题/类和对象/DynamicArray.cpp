#include "DynamicArray.h"
#include <iostream>
DynamicArray::DynamicArray(int capacity):size(0),capacity(capacity)
{
    array = new ElementType[capacity];
}

DynamicArray::DynamicArray(const DynamicArray & a)
{
    size = a.size;
    capacity = a.capacity;
    array = new ElementType[capacity];
    for(int i =0; i<size ;i++)
    {
        array[i] = a.array[i];
    }
}

void DynamicArray::operator=(const DynamicArray &a)
{
    delete []array;
    size = a.size;
    capacity = a.capacity;
    array = new ElementType[capacity];
    for(int i = 0;i<size;i++)
    {
        array[i] = a.array[i];
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
    {
        capacity *= 2;
        ElementType *newP = new ElementType[capacity];
        for(int i = 0;i <size;i++)
        {
             newP[i]= array[i];
        }
        delete []array;
        array = newP;
    }
    array[size++] = element;
}

void DynamicArray::show() 
{
    for(int i = 0;i < size;i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}


