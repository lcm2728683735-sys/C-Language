#include <iostream>
#include "DoubleLinkList.h"
#include "LinkStack.h"

LinkStack::LinkStack()
{
}

LinkStack::~LinkStack()
{
}

void LinkStack::Push(const ElementType &element)
{
    list.InsertTail(element);
}

void LinkStack::Pop()
{
    list.RemoveByIndex(list.Size()-1); 
}

ElementType & LinkStack::GetTop()
{
    return list[list.Size()-1];
}

bool LinkStack::IsEmpty()
{
    return list.Size() == 0;
}
