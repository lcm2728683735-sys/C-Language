#include "LinkList.h"
#include <iostream>

LinkList::LinkList() : size(0)
{
    head = new Node(0); // 头节点
}

LinkList::LinkList(const LinkList &list)
{
    size = list.size;
    head = new Node(0);
    Node *travelPoint = list.head->next;
    while (travelPoint != nullptr)
    {
        InsertTail(travelPoint->value);
        travelPoint = travelPoint->next;
    }
}

LinkList::~LinkList()
{
    while (head != nullptr)
    {
        Node *nextNode = head->next;
        delete head;
        head = nextNode;
    }
}
// 尾插法     时间复杂度  O(n)
void LinkList::InsertTail(const ElementType &element)
{
    Node *travelPoint = head;
    // 找尾巴
    while (travelPoint->next != nullptr)
    {
        travelPoint = travelPoint->next;
    }
    travelPoint->next = new Node(element);
    size++;
}
void LinkList::InsertHead(const ElementType &element)
{
    Node *newNode = new Node(element); // O(1)
    newNode->next = head->next;
    head->next = newNode;
    size++;
}
void LinkList::InsertByIndex(int index, const ElementType &element)
{
    if (index < 0 || index > size)
        return;
    Node *travelPoint = head;
    for (int i = 0; i < index; i++)
    {
        travelPoint = travelPoint->next;
    }
    Node *newNode = new Node(element);
    newNode->next = travelPoint->next;
    travelPoint->next = newNode;
    size++;
}
void LinkList::RemoveByIndex(int index)
{
    if (index < 0 || index >= size)
        return;
    Node *travelPoint = head;
    for (int i = 0; i < index; i++)
    {
        travelPoint = travelPoint->next;
    }
    Node *freeNode = travelPoint->next;
    travelPoint->next = freeNode->next;
    delete freeNode;
}
void LinkList::RemoveByElement(const ElementType &element)
{
    Node *travelPoint = head;
    while (travelPoint->next != nullptr)
    {
        if (travelPoint->next->value == element)
        {
            Node *freeNode = travelPoint->next;
            travelPoint->next = freeNode->next;
            delete freeNode;
            size--;
        }
        else
            travelPoint = travelPoint->next;
    }
}
void LinkList::UndateByIndex(int index, const ElementType &element)
{
    if (index < 0 || index >= size)
        return;
    Node *travelPoint = head;
    for (int i = 0; i < index; i++)
    {
        travelPoint = travelPoint->next;
    }
    travelPoint->value = element;
}

void LinkList::UpdateByElement(const ElementType &oldValue, const ElementType &newValue)
{
    Node *travelPoint = head->next;
    while (travelPoint != nullptr)
    {
        if (travelPoint->value == oldValue)
            travelPoint->value = newValue;
        travelPoint = travelPoint->next;
    }
}

void LinkList::BubbleSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        Node *travelPoint = head;
        for (int j = 0; j < size - 1 - i; j++)
        {
            Node *prevNode = travelPoint->next;
            Node *nextNode = prevNode->next;
            if (travelPoint->next->value > travelPoint->next->next->value)
            {

                travelPoint->next = nextNode;
                prevNode->next = nextNode->next;
                nextNode->next = prevNode;
            }
            travelPoint = travelPoint->next;
        }
    }
}

void LinkList::Sort()
{
    FastSort(head->next,nullptr);
}

void LinkList::Reserve()
{
    Node *prev = nullptr;
    Node *cur = head->next; 
    Node *Next = cur->next;
    while(Next != nullptr)
    {
        cur->next = prev;
        prev = cur;
        cur = Next;
        Next = cur->next; 
    }
    cur->next = prev;
    head->next = cur;
}

void LinkList::Reserve2()
{
    head->next = Reserve2(head->next);
}

LinkList LinkList::Merge(const LinkList &list)
{
    LinkList result;
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

void LinkList::FastSort(Node *start, Node *end)
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

LinkList::Node* LinkList::Reserve2(Node *node)
{
    if(node->next == nullptr)
        return node;
    else
    {
        Node *newHeader = Reserve2(node->next);
        node->next->next= node;//逆序
        node->next = nullptr;
        return newHeader;
    }
}

void LinkList::show()
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
