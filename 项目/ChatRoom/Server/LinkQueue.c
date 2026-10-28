
#include "LinkQueue.h"
#include <stdlib.h>

// 初始化队列
bool LinkQueue_Init(LinkQueue *queue)
{
    if (queue == NULL)
    {
        return false;
    }

    queue->list = List_Create();

    return queue->list != NULL;
}

// 销毁队列
void LinkQueue_Destroy(LinkQueue *queue)
{
    if (queue == NULL || queue->list == NULL)
    {
        return;
    }

    // 释放链表节点及链表结构，不释放 data 指向的内容
    List_Destroy(queue->list);
    queue->list = NULL;
}

// 入队：从链表尾部插入
bool LinkQueue_Push(LinkQueue *queue, void *data)
{
    if (queue == NULL || queue->list == NULL)
    {
        return false;
    }

    return List_PushBack(queue->list, data);
}

// 出队：从链表头部移除并返回数据
void *LinkQueue_Pop(LinkQueue *queue)
{
    if (queue == NULL || queue->list == NULL)
    {
        return NULL;
    }

    return List_PopFront(queue->list);
}

// 获取队列长度
size_t LinkQueue_Size(const LinkQueue *queue)
{
    if (queue == NULL || queue->list == NULL)
    {
        return 0;
    }

    return List_GetSize(queue->list);
}

// 获取队头数据，不删除节点
void *LinkQueue_GetFront(const LinkQueue *queue)
{
    return List_FindByIndex(queue->list,0);
}

// 判断队列是否为空
bool LinkQueue_IsEmpty(const LinkQueue *queue)
{
    if (queue == NULL || queue->list == NULL)
    {
        return true;
    }

    return List_IsEmpty(queue->list);
}
