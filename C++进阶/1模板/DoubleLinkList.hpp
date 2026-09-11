#ifndef __DOUBLELINKLIST_H__
#define __DOUBLELINKLIST_H__
#include <iostream>

template <typename T>
class DoubleLinkList
{
public:
    DoubleLinkList();
    void InsertTail(const T &element);

    void RemoveByIndex(int index);
    T & GetHead()
    {
        if(size == 0)
            throw std::out_of_range("链表为空，无法取出头部元素");
        return head->next->data;
    }
    int Size(){return size;}
    template <typename U>
    friend std::ostream & operator<<(std::ostream & os,const DoubleLinkList<U>& list);
private :
    struct Node
    {
        Node(const T& element)
        {
            next = prev = nullptr;
            data = element; 
        }
        T data;
        Node* next;
        Node* prev;
    };
    Node* head; 
    Node* tail;
    int size; 
};

template <typename T>
DoubleLinkList<T>::DoubleLinkList():size(0)
{
    T();
    head = tail = new Node(T());
}

template <typename T>
void DoubleLinkList<T>::InsertTail(const T &element)
{
    Node *newNode = new Node(element);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    size++;
}

#endif

template <typename T>
inline std::ostream & operator<<(std::ostream &os, const DoubleLinkList<T> &list)
{
    //typename声明后面跟随的模板为一个类型
    typename DoubleLinkList<T>::Node* travelPoint =list.head->next;
    while (travelPoint != nullptr)
    {
        std::cout << travelPoint->data << " ";
        travelPoint = travelPoint->next;
    }
    std::cout << std::endl;
    return os;
}

template <typename T>
void DoubleLinkList<T>::RemoveByIndex(int index)
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