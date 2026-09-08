#include <iostream>
  
void MaxHeap(int * a,int n,int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int Max = i;
    if(left < n && a[left] > a[Max])
        Max = left;
    if(right < n && a[right] > a[Max])
        Max = right; 
    if(Max!= i)
    {
        std::swap(a[i],a[Max]);
        MaxHeap(a,n,Max);
    }
}

void HeapSort(int *a,int n)
{
    for(int i = n - 1;i>= 0;i--)
    {
        MaxHeap(a,n,i); 
    }
    for(int i =n - 1;i >= 0;i--)
    {
        std::swap(a[0],a[i]);
        MaxHeap(a,i,0);
    }
}
