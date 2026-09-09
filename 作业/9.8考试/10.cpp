#include <iostream>
#include "LinkList1.h"



int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);   
    LinkList1 list2;
    LinkList1 list1  = LinkList1::StrTransLink(a, n);
    for(int i = 0;i<10;i+=2)
    {
        list2.InsertTail(i);
    }
    list2.show();
    list1.show();
    list1.Merge(list2).show();
    return 0;
}