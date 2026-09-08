#include "LinkList1.h"
#include <iostream>
int main()
{
    LinkList1 l;
    for(int i = 0;i < 10;i++)
    {
        l.InsertTail(i+1);
    }
    
    std::cout << l.FindSq()<<std::endl;
    return 0;

}