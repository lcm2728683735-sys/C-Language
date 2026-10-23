#include "List.h"
#include <stdlib.h>
#include "List.h"

// 创建链表
List* List_Create(void) {
    List *list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// 销毁链表（注意：这里只释放链表节点和管理结构，若 data 是动态申请的需在外部提前释放）
void List_Destroy(List *list) {
    if (list == NULL) {
        return;
    }
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// 尾部插入
bool List_PushBack(List *list, void *data) {
    if (list == NULL) {
        return false;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail == NULL) {
        // 链表为空时，head 和 tail 都指向新节点
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    list->size++;
    return true;
}

// 头部插入
bool List_PushFront(List *list, void *data) {
    if (list == NULL) {
        return false;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head == NULL) {
        list->tail = newNode;
    } else {
        list->head->prev = newNode;
    }
    list->head = newNode;
    list->size++;
    return true;
}

// 尾部弹出
void* List_PopBack(List *list) {
    if (list == NULL || list->tail == NULL) {
        return NULL;
    }

    Node *oldTail = list->tail;
    void *data = oldTail->data;

    list->tail = oldTail->prev;
    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    free(oldTail);
    list->size--;
    return data;
}

// 头部弹出
void* List_PopFront(List *list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }

    Node *oldHead = list->head;
    void *data = oldHead->data;

    list->head = oldHead->next;
    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }

    free(oldHead);
    list->size--;
    return data;
}

// 获取当前长度
size_t List_GetSize(const List *list) {
    return list ? list->size : 0;
}

// 判断是否为空
bool List_IsEmpty(const List *list) {
    return list ? (list->size == 0) : true;
}


void List_Travel(List *list, ListActionFunc action) {
    if (list == NULL || action == NULL) 
    {
        return;
    }
    
    Node *current = list->head;
    while (current != NULL) {
        action(current->data); // 对当前节点的数据执行回调操作
        current = current->next;
    }
}

// 实现查找函数
List List_FindElement(List *list, void *target, ListMatchFunc matchFunc) 
{
    List result = {0};

    if(list == NULL || matchFunc ==NULL)
    {
        return result;
    }

    Node *current = list->head;

    while (current != NULL) 
    {
        // 调用回调函数判断当前节点是否匹配目标
        if (matchFunc(current->data, target)) 
        {
            if(!List_PushBack(&result,current->data))
            {
                Node * node = result.head;

                while(node != NULL)
                {
                    Node * next = node ->next;
                    free(node);
                    node =next;
                }
                result.head = NULL;
                result.tail = NULL;
                result.size = 0;
                break;
            }   
        }
        current = current->next;
    }

    return result; // 遍历完都没找到，
}

void List_Clear(List *list)
{
    if (list == NULL)
        return;

    Node *cur = list->head;

    while (cur != NULL)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}



void List_RemoveByIndex(List *list, int index, void (*freePtr)(void *))
{
    if (list == NULL || index < 0 || index >= list->size)
    {
        if (list != NULL)
            printf("删除的位置非法:%d len:%d\n", index, list->size);
        return;
    }

    // 找到指定索引的节点
    Node *current = list->head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    // 连接前驱节点
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        list->head = current->next;

    // 连接后继节点
    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        list->tail = current->prev;

    // 释放节点保存的数据
    if (freePtr != NULL)
        freePtr(current->data);

    // 释放节点本身
    free(current);

    list->size--;
}




void List_RemoveByElement1(List *list,void *target,ListMatchFunc matchFunc,void (*freePtr)(void *))
{
    if (list == NULL || matchFunc == NULL)
        return;

    int index = 0;
    Node *travelPoint = list->head;

    while (travelPoint != NULL)
    {
        if (matchFunc(travelPoint->data, target))
        {
            // 先保存下一个节点，防止当前节点被释放后无法继续遍历
            Node *next = travelPoint->next;

            List_RemoveByIndex(list, index, freePtr);

            travelPoint = next;
            // 删除后，后续节点的索引前移，因此 index 不增加
        }
        else
        {
            index++;
            travelPoint = travelPoint->next;
        }
    }
}
