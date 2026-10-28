#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

// 双向链表节点结构体
typedef struct Node {
    void *data;          // 通用数据指针
    struct Node *prev;   // 指向前一个节点
    struct Node *next;   // 指向后一个节点
} Node;

// 双向链表管理结构体
typedef struct List {
    Node *head;          // 链表头部
    Node *tail;          // 链表尾部
    size_t size;         // 当前节点数量
} List;

// 定义回调函数指针类型（接收 void*，无返回值）
typedef void (*ListActionFunc)(void *data);
// 定义带目标参数的匹配函数指针类型（返回 bool 表示是否匹配成功）
typedef bool (*ListMatchFunc)(void *data, void *target);


void List_Init(List *list);
// 查找函数声明（返回找到的数据指针 void*）
List* List_Create(void);
void List_Destroy(List *list);

// 2. 增删操作
bool List_PushBack(List *list, void *data);
bool List_PushFront(List *list, void *data);
void List_InsertTail(List *list, void *data);
void* List_PopBack(List *list);
void* List_PopFront(List *list);

// 3. 状态查询
size_t List_GetSize(const List *list);
bool List_IsEmpty(const List *list);

void List_Travel(List *list,ListActionFunc action);

List List_FindElement(List *list, void *target, ListMatchFunc matchFunc);
void* List_FindByIndex(List * list,int index);
void List_RemoveByIndex(List *list, int index, void (*freePtr)(void *));
void List_RemoveByElement(List *list,void *target,ListMatchFunc matchFunc,void (*freePtr)(void *));

void List_Clear(List *list);


#endif