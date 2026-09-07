#include "LinkList.h"
#include <iostream>
int main()
{
    LinkList l;
    for(int i = 0;i < 10;i++)
    {
        l.InsertTail(i+1);
    }
    LinkList l2;
    for(int i = 10;i < 20;i++)
    {
        l2.InsertTail(i+1);
    }

    l.show();
    l.Reserve4();
    l.show();
    return 0;

}