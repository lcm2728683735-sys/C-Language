#include <iostream>
#include "2.h"

int main()
{
    int a[10000] = { 5,6,1,3,9};
    HeapSort(a,10);
    for(int i = 0;i < 5;i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout <<std::endl; 
    return 0;
}