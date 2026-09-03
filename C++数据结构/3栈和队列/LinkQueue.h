#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include "DoubleLinkList.h"

class LinkQueue
{
public:
    LinkQueue(){}
    ~LinkQueue(){}
    void Push(const ElementType & element);
    void Pop();
    size_t Size();
    ElementType & GetFront();
    bool IsEmpty();
private:
    DoubleLinkList list;

};
#endif