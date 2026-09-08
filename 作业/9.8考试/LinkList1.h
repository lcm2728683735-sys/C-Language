#ifndef __LINKLIST1_H_
#define __LINKLIST1_H_

#include <stddef.h>
using ElementType = int;
class LinkList1
{
public:
    LinkList1();
    LinkList1(const LinkList1 & list);
    ~LinkList1();
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
    void Reserve3();
    bool FindSq();

    LinkList1 Merge(const LinkList1 & list);
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
    Node * Reserve3(Node *node);
    Node * head; //头指针
    size_t size; //节点个数
};

#endif