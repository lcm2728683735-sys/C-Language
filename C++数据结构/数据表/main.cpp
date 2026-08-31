#include "DynamicArray.h"
#include <iostream>
#include <cmath>
#include <stddef.h>
int main()
{
    // DynamicArray a;
    // for(int i = 0;i <20;i++)
    // {
    //     a.InsertTail(i+1);
    // }
    // for(int i = 0;i <20;i++)
    // {
    //     a.InsertHead(i+1);
    // }
 
    // a.show();

    // DynamicArray result = a.FindByElement(8);

    // result.show();
    // // a.InsertByIndex(1,99);
    // // a.RemoveByElement(1);
    // // a.InsertSort(0,a.Size() - 1);
    // // a.Sort;
    // a.show();
    // // a.UpdataByElement(1,99);
    // a.Sort();
    // a.show();
    // a.Duplicate();
    // a.show();

    // DynamicArray a1;
    // for(int i =1 ;i <= 10;i+=2)
    // {
    //     a1.InsertTail(i);
    // }
    // DynamicArray a2;
    // for(int i =2 ;i <= 10;i+=2)
    // {
    //     a2.InsertTail(i);
    // }
    // a1.show();
    // a2.show();
    // a1.Merge(a2).show();
    // ElementType* p = a.FindByIndex(1);
    // if(p)
    //     std::cout<<*p<<std::endl; 
    DynamicArray a1;
    DynamicArray a2;

    // a1.InsertTail(1);
    // a1.InsertTail(2);
    // a1.InsertTail(3);
    // a1.InsertTail(4);

    // a2.InsertTail(1);
    // a2.InsertTail(2);
    // a2.InsertTail(99);    


    a1.show();
    a2.show();
    a1.FindUnionSet(a2).show();
    a1.FindDifference(a2).show();
    // size_t n =a2.BinarySearch(1);
    // if(n== ULONG_MAX)
    //     std::cout<<"没找到";
    // else
    //     std::cout<<n<<"\n";

    // std::cout<<a1.IsChild(a2)<<std::endl;

    a1.subsequence(1,2).show();
    return 0;
}