#include "LinkQueue.h"

void LinkQueue::Push(const ElementType & element)
{
    list.InsertTail(element);
}

void LinkQueue::Pop()
{
    list.RemoveByIndex(0);
}
size_t LinkQueue::Size()
{
    return list.Size();
}
ElementType &LinkQueue::GetFront()
{
    return list[0];
}

bool LinkQueue::IsEmpty()
{
    return list.Size() == 0;
}
