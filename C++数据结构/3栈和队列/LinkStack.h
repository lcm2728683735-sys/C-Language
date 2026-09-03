#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_

#include "DoubleLinkList.h"
class LinkStack
{
public:
    LinkStack();
    ~LinkStack();

    void Push(const ElementType& element);
    void Pop();
    ElementType & GetTop();
    bool IsEmpty();
    
private:
    DoubleLinkList list;
};

#endif