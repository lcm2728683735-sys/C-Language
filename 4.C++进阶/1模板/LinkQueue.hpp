#ifndef LINKQUEUE_H__
#define LINKQUEUE_H__

#include "DoubleLinkList.hpp"

template <typename T>
class LinkQueue:public DoubleLinkList<T>

{
public:
    LinkQueue():DoubleLinkList<T>(){}
    ~LinkQueue(){};

    void Push(const T&element){DoubleLinkList<T>:: InsertTail(element);}
    void Pop(){DoubleLinkList<T>::RemoveByIndex(0);}

    T & GetFront(){return DoubleLinkList<T>:: GetHead();}
    bool IsEmpty() {return DoubleLinkList<T>::Size() == 0;}

private:
};

#endif