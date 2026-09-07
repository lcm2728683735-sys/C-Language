#include <iostream>

//构建一个堆    
void MaxHeap(int * a,int n,int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int Max = i;
    //找左孩子
    if(left < n && a[left] > a[Max])
        Max = left;
    //找右孩子
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
        std::swap(a[0],a[i]);//交换根和最后一位
        MaxHeap(a,i,0);
    }
}
int main()
{
    int a[5] = { 5,6,1,3,9};
    HeapSort(a,5);
    for(int i = 0;i < 5;i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout <<std::endl; 
    return 0;
}