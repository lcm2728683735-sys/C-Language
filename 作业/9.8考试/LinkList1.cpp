#include "LinkList1.h"
#include <iostream>

LinkList1::LinkList1() : size(0)
{
    head = new Node(0); // 头节点
}

LinkList1::LinkList1(const LinkList1 &list)
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

LinkList1::~LinkList1()
{
    while (head != nullptr)
    {
        Node *nextNode = head->next;
        delete head;
        head = nextNode;
    }
}
// 尾插法     时间复杂度  O(n)
void LinkList1::InsertTail(const ElementType &element)
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
void LinkList1::InsertHead(const ElementType &element)
{
    Node *newNode = new Node(element); // O(1)
    newNode->next = head->next;
    head->next = newNode;
    size++;
}
void LinkList1::InsertByIndex(int index, const ElementType &element)
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
void LinkList1::RemoveByIndex(int index)
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
void LinkList1::RemoveByElement(const ElementType &element)
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
void LinkList1::UndateByIndex(int index, const ElementType &element)
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

void LinkList1::UpdateByElement(const ElementType &oldValue, const ElementType &newValue)
{
    Node *travelPoint = head->next;
    while (travelPoint != nullptr)
    {
        if (travelPoint->value == oldValue)
            travelPoint->value = newValue;
        travelPoint = travelPoint->next;
    }
}

void LinkList1::BubbleSort()
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

void LinkList1::Sort()
{
    FastSort(head->next,nullptr);
}

void LinkList1::Reserve()
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





LinkList1 LinkList1::Merge(const LinkList1 &list)
{
    LinkList1 result;
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

void LinkList1::FastSort(Node *start, Node *end)
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

LinkList1::Node* LinkList1::Reserve2(Node *node)
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

void LinkList1::Reserve2()
{
    head->next = Reserve2(head->next);
}

LinkList1:: Node *LinkList1::Reserve3(Node * node)
{
    Node* travelPoint = node;
    Node * newhead = nullptr;
    Node * temp = nullptr;
    while(travelPoint != nullptr)
    {
        temp = travelPoint->next;   //保存遍历指针的下一个值
        travelPoint->next = newhead; //让遍历指针指向尾部
        newhead = travelPoint;      //保存遍历指针现在的值，等待返回
        travelPoint = temp;         //遍历指针向后遍历
    }
    return newhead;
}

int LinkList1::GetLinkSize(Node *head)
{
    Node * travelPoint = head;
    int count =0;
    while(travelPoint != nullptr)
    {
        count++;
        travelPoint= travelPoint->next;
    }
    return count;
}

void LinkList1::Reserve3()
{
    if (head == nullptr || head->next == nullptr) return;
    head->next = Reserve3(head->next);   // 只反转 head 后面的部分
}



void LinkList1::show()
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

bool LinkList1::FindSq()
{
    Node * Slow = head;
    Node * Quick = head;

    while (Quick != nullptr && Quick->next != nullptr)
    {
        Slow = Slow->next;
        Quick = Quick->next->next;
        if(Slow == Quick)
            return true;
    }
    return false;
}

int LinkList1::GetLinkSize()
{
    return GetLinkSize(head);
}

LinkList1 LinkList1::StrTransLink(int * s,int n)
{
    LinkList1 res;
    if (res.head == nullptr)
        res.head = new Node(0);
    res.head->next = nullptr;
    for(int i = n - 1;i >= 0;i--)
    {
        Node * newNode = new Node(s[i]);
        newNode->next = res.head->next;
        res.head->next = newNode;
    }
    return res;
}
