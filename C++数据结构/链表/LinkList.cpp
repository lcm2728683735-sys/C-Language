#include "LinkList.h"
#include <iostream>

LinkList::LinkList():size(0)
{
    head = new Node(0);//头节点
}

LinkList::~LinkList()
{
    while(head != nullptr)
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
    //找尾巴
    while(travelPoint->next != nullptr)
    {
        travelPoint = travelPoint->next;
    }
    travelPoint->next = new Node(element);
    size++;
}
void LinkList::InsertHead(const ElementType &element)
{
    Node *newNode = new Node(element);//O(1) 
    newNode->next = head->next;
    head->next = newNode;
    size++;

}
void LinkList::InsertByIndex(int index,const ElementType &element)
{
    
}
void LinkList::show()
{
    Node*travelPoint = head->next;
    while(travelPoint !=nullptr)
    {
        std::cout<<travelPoint->value<<" ";
        travelPoint = travelPoint->next;
    }
    std::cout<<std::endl;
}
