
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "List.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct LinkQueue
{
    List *list;
} LinkQueue;

// 初始化队列
bool LinkQueue_Init(LinkQueue *queue);

// 销毁队列
void LinkQueue_Destroy(LinkQueue *queue);

// 入队
bool LinkQueue_Push(LinkQueue *queue, void *data);

// 出队，返回队头数据
void *LinkQueue_Pop(LinkQueue *queue);

// 获取队列长度
size_t LinkQueue_Size(const LinkQueue *queue);

// 获取队头数据，不删除节点
void *LinkQueue_GetFront(const LinkQueue *queue);

// 判断队列是否为空
bool LinkQueue_IsEmpty(const LinkQueue *queue);

#endif
