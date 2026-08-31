#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#include <stddef.h>
using ElementType = int;
class LinkList
{
public:
    LinkList();
    ~LinkList();
    void show();
    //尾插法
    void InsertTail(const ElementType & element);
    void InsertHead(const ElementType & element);
    void InsertByIndex(int index,const ElementType & element);

private:
    //节点
    struct Node
    {
        Node(const ElementType& value):value(value),next(nullptr){}
        ElementType value;//数据域
        Node * next;
    };
    Node * head; //头指针
    size_t size; //节点个数
};

#endif