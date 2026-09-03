#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#include <stddef.h>
using ElementType = int;
class LinkList
{
public:
    LinkList();
    LinkList(const LinkList & list);
    ~LinkList();
    void show();
    //尾插法
    void InsertTail(const ElementType & element);
    void InsertHead(const ElementType & element);
    void InsertByIndex(int index,const ElementType & element);
    void RemoveByIndex(int index);
    void RemoveByElement(const ElementType & element);
    void UndateByIndex(int index,const ElementType &element);
    void UpdateByElement(const ElementType &oldValue,const ElementType &newValue);
    void BubbleSort();
    void Sort();
    void Reserve();
    void Reserve2();
    LinkList Merge(const LinkList & list);
private:

    //节点
    struct Node
    {
        Node(const ElementType& value):value(value),next(nullptr){}
        ElementType value;//数据域
        Node * next;
    };
    void FastSort(Node *start,Node *end);
    Node * Reserve2(Node *node);
    Node * head; //头指针
    size_t size; //节点个数
};

#endif