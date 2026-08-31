#include "LinkList.h"

int main()
{
    LinkList l;
    for(int i = 0;i < 10;i++)
    {
        l.InsertTail(i+1);
    }
    for(int i = 0;i < 10;i++)
    {
        l.InsertHead(i+1);
    }
    l.show();
    return 0;

}