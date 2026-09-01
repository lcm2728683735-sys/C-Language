#include "DoubleLinkList.h"
#include <iostream>
DoubleLinkList::DoubleLinkList():size(0)
{
    head = new Node(0);
    tail = head;
}

void DoubleLinkList::InsertTail(const ElementType& element)
{
    Node *newNode = new Node(element);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    size++;
}

void DoubleLinkList::InsertHead(const ElementType &element)
{
    Node *newNode = new Node(element);
    newNode->next = head->next;
    newNode->prev = head;
    head->next = newNode;

    if(size != 0)
        newNode->next->prev = newNode;
    else
        tail = newNode;
    size++;
}

void DoubleLinkList::RemoveByIndex(int index)
{
    if(index < 0|| index >=size)
        return;
    
    Node *travelPoint =head;
    for(int i = 0; i < index;i++)
    {
        travelPoint = travelPoint->next;
    }
    Node *freeNode = travelPoint->next;
    travelPoint->next = freeNode->next;
    if(freeNode == tail)
        tail = tail->prev;
    else
        freeNode->next->prev = travelPoint;
    delete freeNode;
    size--;
}

void DoubleLinkList::RemoveByElement(const ElementType &element)
{
    Node *travelPoint = head;
    while(travelPoint->next != nullptr)
    {
        if(travelPoint->next->value ==element)
        {
            Node *freeNode = travelPoint->next;
            travelPoint->next = freeNode->next;
            travelPoint = freeNode->prev;
            delete freeNode;
            size--;
        }
        else    
            travelPoint = travelPoint->next;
    }
}

void DoubleLinkList::UpDateByElement(const ElementType &oldValue, const ElementType &newValue)
{
    Node *travelPoint = head->next;
    while (travelPoint != nullptr)
    {
        if (travelPoint->value == oldValue)
            travelPoint->value = newValue;
        travelPoint = travelPoint->next;
    }
}

ElementType &DoubleLinkList::operator[](int index)
{
    // if(index < 0|| index >=size)
    //     return ;
    Node *travelPoint = head->next;
    for(int i = 0;i<index;i++)
    {
        travelPoint = travelPoint->next;
    }    
    return travelPoint->value;
}

size_t DoubleLinkList::FindByElement(const ElementType &element)
{
    Node *travelPoint = head->next;
    size_t count = 0;
    while (travelPoint != nullptr)
    {
        if (travelPoint->value == element)
        break;
        travelPoint = travelPoint->next;
        count++;
    }
    return count;
}

void DoubleLinkList::Sort()
{
    FastSort(head->next,nullptr);
}

//管线

DoubleLinkList DoubleLinkList::Merge(const DoubleLinkList &list)
{
    DoubleLinkList result;
    Node *p1 = head->next;
    Node *p2 = list.head->next;
    while (p1 && p2)
    {
        if (p1->value < p2->value)
        {
            result.InsertTail(p1->value);
            p1 = p1->next;
        }
        else
        {
            result.InsertTail(p2->value);
            p2 = p2->next;
        }
    }
    while (p1)
    {
        result.InsertTail(p1->value);
        p1 = p1->next;
    }
    while (p2)
    {
        result.InsertTail(p2->value);
        p2 = p2->next;
    }
    return result;
}

void DoubleLinkList::FastSort(Node *start, Node *end)
{
    if(start == end)
        return;
    Node *temp = start;
    Node *slow = start;
    Node *fast = start->next;
    while(fast != end)
    {
        //快指针所指的数据比基准值小
        if(fast->value < temp->value)
        {
            slow = slow->next;
            std::swap(fast->value,slow->value);
        }
        fast = fast->next;
    }
    std::swap(temp->value,slow->value);
    FastSort(start,slow);
    FastSort(slow->next,end);
}

size_t DoubleLinkList::Size()
{
    return size;
}

void DoubleLinkList::show()
{
    std::cout << "size : " << size << std::endl;
    Node *travelPoint = head->next;
    while (travelPoint != nullptr)
    {
        std::cout << travelPoint->value << " ";
        travelPoint = travelPoint->next;
    }
    std::cout << std::endl;
}

void DoubleLinkList::ReserveShow()
{
    Node *travelPoint = tail;
    while (travelPoint != head)
    {
        std::cout << travelPoint->value << " ";
        travelPoint = travelPoint->prev;
    }
    std::cout << std::endl;
}
