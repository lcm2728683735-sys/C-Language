#include "DynamicArray.h"
#include <iostream>

int main()
{
    DynamicArray a;
    for(int i = 0;i <20;i++)
    {
        a.InsertTail(i+1);
    }
    for(int i = 0;i <20;i++)
    {
        a.InsertHead(i+1);
    }
 
    a.show();

    DynamicArray result = a.FindByElement(8);

    result.show();
    a.UpdataByElement(9,999);
    a.show();
    // ElementType* p = a.FindByIndex(1);
    // if(p)
    //     std::cout<<*p<<std::endl; 
    return 0;
}