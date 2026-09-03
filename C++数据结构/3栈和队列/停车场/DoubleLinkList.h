#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_

#include <stddef.h>
using ElementType = void*;
class DoubleLinkList
{
public: 
    DoubleLinkList();
    void InsertTail(const ElementType& element);
    void InsertHead(const ElementType& element); 
    void RemoveByIndex(int index);
    void RemoveByElement(const ElementType& element);

    void UpDateByElement(const ElementType &oldValue, const ElementType &newValue);
    ElementType& operator[](int index);
    size_t FindByElement(const ElementType& element);
    void Sort();
    DoubleLinkList Merge(const DoubleLinkList &list);


    size_t Size();
    void show();
    void ReserveShow();


private:
    struct Node
    {
        Node(const ElementType& element):value(element),next(nullptr),prev(nullptr){}
        ElementType value;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    size_t size;
    void FastSort(Node *start, Node *end);
};

#endif