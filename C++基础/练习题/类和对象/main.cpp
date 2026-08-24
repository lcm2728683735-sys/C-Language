#include "DynamicArray.h"


int main()
{
    DynamicArray a;
    for(int i = 0;i<20;i++)
    {
        a.InsertTail(i+1);
    }
    a.show();
    DynamicArray b ;
    b = a;
    b.show();
    return 0;
}

