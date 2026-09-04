// #include "DynamicArray.h"
// #include <iostream>
// #include <cmath>
// #include <limits.h>
// namespace DARRAY
// {
// DynamicArray::DynamicArray(size_t capacity):size(0),capacity(capacity)
// {
//     array = new ElementType[capacity];
// }

// DynamicArray::DynamicArray(const DynamicArray & a)
// {
//     size = a.size;
//     capacity = a.capacity;
//     array = new ElementType[capacity];
//     for(size_t i =0; i<size ;i++)
//     {
//         array[i] = a.array[i];
//     }
// }

// DynamicArray& DynamicArray::operator=(const DynamicArray &a)
// {
//     delete []array;
//     size = a.size;
//     capacity = a.capacity;
//     array = new ElementType[capacity];
//     for(size_t i = 0;i<size;i++)
//     {
//         array[i] = a.array[i];
//     }
//     return *this;
// }

// size_t DynamicArray::Size()
// {
//     return size;
// }

// void DynamicArray::ReSize(size_t capacity)
// {
//     this->capacity = capacity;
//     this->size = (size > capacity)?capacity : size;

//     ElementType *newP = new ElementType[capacity];
//     for(size_t i = 0;i<size;i++)
//     {
//         newP[i] = array[i];
//     }
//     delete []array;
//     array = newP;
// }

// void DynamicArray::InsertHead(const ElementType &element)
// {
//     if(size >= capacity)
//         ReSize(2 * capacity);
//     for(size_t i =size ; i > 0; i--)//O(n)
//     {
//         array[i] = array[i-1];
//     }
//     array[0] = element;
//     size++;
// }

// void DynamicArray::InsertByIndex(int Index, const ElementType &element)
// {
//     if(Index < 0 ||Index > size)
//         return;
//     if(size >= capacity)
//         ReSize(2 * capacity);
//     for(size_t i =size ; i > Index; i--)//O(n)
//     {
//         array[i] = array[i-1];
//     }
//     array[Index] = element;
//     size++;
// }

// void DynamicArray::RemoveByIndex(int index) 
// {
//     if(index < 0 || index >= size)
//         return;
//     for(size_t i = index;i<size-1;i++)
//     {
//         array[i] = array[i+1];
//     }
//     size--;
// }

// void DynamicArray::RemoveByElement(const ElementType &element)
// {
//     for(int i= 0;i<size;i++)
//     {
//         if(array[i] == element)
//         {
//             RemoveByIndex(i);
//             i--;
//         }
//     }
// }

// ElementType *DynamicArray::FindByIndex(int index)
// {
//     if(index< 0 ||index >= size)
//         return nullptr;
//     return &array[index];
// }  //O(1)

// ElementType &DynamicArray::operator[](int index)
// {
//     return array[index];
// }

// DynamicArray DynamicArray::FindByElement(const ElementType &element)
// {
//     DynamicArray result;
//     for(int i = 0; i< size ;i++)
//     {
//         if(array[i] == element)
//         {
//             result.InsertTail(new int(i));
//         }
//     }
//     return result;
// }

// void DynamicArray::UpdateByIndex(int index, const ElementType &element)
// {
//     if(index < 0|| index >= size)
//         return;
//     array[index] = element;//O(1)
// }

// void DynamicArray::UpdataByElement(const ElementType &oldValue, const ElementType& newValue)
// {
//     for(int i = 0 ;i <size;i++)
//     {
//         if(array[i] == oldValue)
//         {
//             array[i] = newValue;
//         }
//     }
// }

// void DynamicArray::FastSort(size_t start,size_t end,size_t deepth,size_t MaxDepth)
// {
//     if(start >= end)
//         return;
//     if(deepth > MaxDepth)
//     {
//         InsertSort(start ,end);
//     }
//     else
//     {
//         size_t par = Partition(start,end);
//         if(par != 0)
//             FastSort(start,par,deepth + 1,MaxDepth);
//         FastSort(par+1,end,deepth+1,MaxDepth);
//     }
// }

// void DynamicArray::InsertSort(size_t start,size_t end)
// {  
//     for(size_t i = start+1;i <= end ;i++)
//     {
//         size_t j = i;
//         ElementType temp = array[i];
//         for(;j>start;j--)
//         {
//             if(array[j-1]>temp)
//             {
//                 array[j] = array[j-1];
//             }
//             else
//                 break;
//         }
//         array[j] = temp;
//     }
// }

// size_t DynamicArray::Partition(size_t start, size_t end)
// {
//     ElementType pivot = array[end];
//     size_t i = start;               // 

//     for (size_t j = start; j < end; j++)
//     {
//         if (array[j] <= pivot)
//         {
//             std::swap(array[i], array[j]);
//             i++;
//         }
//     }
//     std::swap(array[i], array[end]);
//     return i;                       // 返回最终位置
// }

// void DynamicArray::Sort()
// {
//     FastSort(0,size - 1,0,2 * log2(size));
// }

// void DynamicArray::Duplicate()
// {
//     for(int i = 1; i < size;i++)
//     {
//         if(array[i] == array[i-1])
//         {
//             RemoveByIndex(i);
//             i--;
//         }
//     }
// }

// DynamicArray DynamicArray::Merge(const DynamicArray &a)
// {
//     int first = 0; //当前数组
//     int second = 0;//传进来的数组 
//     DynamicArray result;
//     //遍历两个数组都没到达结尾
//     while(first < this->size && second <a.size)
//     {
//         if(this->array[first] <= a.array[second])
//             result.InsertTail(array[first++]);
//         else
//             result.InsertTail(a.array[second++]);
//     }

//     while(first <this->size)
//         result.InsertTail(array[first++]);
//     while(second < a.size)
//         result.InsertTail(a.array[second++]);
//     return result;
// }

// DynamicArray DynamicArray::FdInterSctn(const DynamicArray &a)
// {
//     DynamicArray result;
//     int first =0;
//     int second = 0;
//     while(first<size && second <a.size)
//     {
//         if(array[first] == a.array[second])
//             result.InsertTail(array[first++]);
//         else if(array[first] > a.array[second])
//             second++;
//         else
//             first++ ;
//     }
//     return result;
// }

// DynamicArray DynamicArray::FindUnionSet(const DynamicArray & a)
// {
//     DynamicArray result;
//     int first =0;
//     int second = 0;
//     while(first<size && second <a.size)
//     {
//         if(array[first] == a.array[second])
//         {
//             result.InsertTail(array[first++]);
//             second++;
//         }   
//         else if(array[first] > a.array[second])
//         {
//             result.InsertTail(a.array[second++]);
//         }
//         else
//         {
//             result.InsertTail(array[first++]);        
//         }
//     }
//     while(first <this->size)
//         result.InsertTail(array[first++]);
//     while(second < a.size)
//         result.InsertTail(a.array[second++]);
//     return result;
// }

// DynamicArray DynamicArray::FindDifference(const DynamicArray &a)
// {
//     DynamicArray result;
//     int first =0;
//     int second = 0;
//     while(first<size && second <a.size)
//     {
//         if(array[first] == a.array[second])
//         {
//             first++;
//             second++;
//         }   
//         else if(array[first] > a.array[second])
//         {
//             result.InsertTail(a.array[second++]);
//         }
//         else
//         {
//             result.InsertTail(array[first++]);        
//         }
//     }
//     while(first <this->size)
//         result.InsertTail(array[first++]);
//     while(second < a.size)
//         result.InsertTail(a.array[second++]);
//     return result;
//     return result;
// }

// bool DynamicArray::operator==(const DynamicArray &a)
// {
//     if(size != a.size)
//         return false;
//     int first = 0;
//     int second = 0;
//     while(first < size && second < a.size)
//     {
//         if(array[first++]!= a.array[second++])
//             return false;
//     }
//     return true;
// }

// size_t DynamicArray::BinarySearch(const ElementType &element)
// {
//     int left = 0;
//     int right = size - 1;
//     while(left<=right)
//     {
//         size_t mid = left+ (right - left) / 2;
//         if(array[mid] == element)
//             return mid;
//         if(mid == 0)
//             return ULONG_MAX;
//         array[mid]> element ?  right = mid - 1 : left = mid + 1;
//     }
//     return ULONG_MAX;
// }

// bool DynamicArray::IsChild(const DynamicArray &a)
// {
//     //无序
//     // for(int i = 0;i < a.size ;i++)
//     // {
//     //     if(FindByElement(a.array[i]).size == 0)
//     //     {
//     //         return false;
//     //     }
//     // }
//     // return true;
//     int j= 0;
//     for(int i = 0; i< size;i++)
//     {
//         if(array[i] == a.array[j])
//         {
//             j++;
//         }
//     }
//     return j == a.size;
// }

// bool DynamicArray::IsCntnsChild(const DynamicArray &a)
// { 
//     for(int i = 0; i <= size - a.size; i++)
//     {
//         if(subsequence(i,a.size) == a)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// DynamicArray DynamicArray::subsequence(int index, size_t size)
// {
//     if(index < 0 ||index + size> this->size)
//         return DynamicArray();
//     DynamicArray result;
//     for(int i = index;i<index +size;i++)
//     {
//         result.InsertTail(array[i]);
//     }
//     return result;
// }

// DynamicArray::~DynamicArray()
// {
//     delete []array ;
// }

// void DynamicArray::InsertTail(const ElementType &element)
// {
//     //扩容
//     if(size>= capacity)
//         ReSize(2 * capacity);
//     array[size++] = element;
// }

// void DynamicArray::show() 
// {
//     for(int  i = 0;i < size;i++)
//     {
//         std::cout<<array[i]<<" ";
//     }
//     std::cout<<std::endl;
// }
// }