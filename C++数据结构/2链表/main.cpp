#include "DoubleLinkList.h"
#include <iostream>
int main()
{
    DoubleLinkList l;
    for(int i = 0;i < 10;i++)
    {
        l.InsertTail(i+1);
    }
    DoubleLinkList l2;
    for(int i = 10;i < 20;i++)
    {
        l2.InsertTail(i+1);
    }
    // l.RemoveByIndex(0);
    // l.RemoveByIndex(l.Size()- 1);
    // l.show();
    // l.ReserveShow();


    // l.RemoveByElement(3);
    // l.UpDateByElement(1,100);
    // l.show();
    // std::cout<<l[1]<<std::endl;
    // std::cout<<l.FindByElement(5)<<std::endl;
    // l.Sort();
    // l.show();

    // l.show();
    // l2.show();
    // DoubleLinkList l3;
    // l3 = l.Merge(l2);
    // l3.show();

    // for(int i = 0;i < 10;i++)
    // {
    //     l.InsertHead(i+1);
    // }
    // l.InsertByIndex(1,99);
    // l.RemoveByIndex(0);
    // l.UndateByIndex(2,999);
    // l.UpdateByElement(3,100);
    // l.show();
    // l.Reserve();
    // l.show();
    // LinkList l2 =l;
    // l.BubbleSort();
    // l.show();
    // LinkList l3 = l.Merge(l2);
    // l3.show();

    l.show();
    l.show();
    return 0;

}