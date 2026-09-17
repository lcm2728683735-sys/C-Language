#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "book.h"
#include "book.h"

// #define NameSize 24
// #define PhoneNumberSize 12
// #define BookSize 512

// // 单个联系人信息结构体
// struct PhoneNumberBookInfo {
//     char Name[NameSize];
//     char Number[PhoneNumberSize];
// };

// // 通讯录主结构体
// struct PhoneNumberBook {
//     BookInfo s[BookSize];
//     int Size; // 当前联系人数量
// };

// typedef struct PhoneNumberBook Book;
// typedef struct PhoneNumberBookInfo BookInfo;

// 插入新的联系人
void InsertBook(Book *a, const char *name, const char *number)
{
    if (a == NULL || name == NULL || number == NULL)
    {
        printf("插入失败：参数为空指针！\n");
        return;
    }
    if (a->Size >= BookSize)
    {
        printf("插入失败：通讯录已满！\n");
        return;
    }

    // 复制姓名和电话到当前索引位置
    strncpy(a->s[a->Size].Name, name, NameSize - 1);
    a->s[a->Size].Name[NameSize - 1] = '\0'; // 确保以 \0 结尾

    strncpy(a->s[a->Size].Number, number, PhoneNumberSize - 1);
    a->s[a->Size].Number[PhoneNumberSize - 1] = '\0';

    a->Size++;
    printf("成功添加联系人: %s\n", name);
}

// 显示所有信息
void show(const Book *a)
{
    if (a == NULL || a->Size == 0)
    {
        printf("通讯录为空！\n");
        return;
    }

    printf("\n==== 通讯录列表 (共 %d 人) ====\n", a->Size);
    for (int i = 0; i < a->Size; i++)
    {
        printf("序号:[%d] \t姓名: %-12s \t号码: %s\n", i + 1, a->s[i].Name, a->s[i].Number);
    }
    printf("=================================\n\n");
}

// 按名字删除联系人
bool DeleteByName(Book *a, const char *name)
{
    if (a == NULL || name == NULL)
        return false;

    for (int i = 0; i < a->Size; i++)
    {
        if (strcmp(a->s[i].Name, name) == 0)
        {
            // 将后面的元素依次向前覆盖
            for (int j = i; j < a->Size - 1; j++)
            {
                a->s[j] = a->s[j + 1];
            }
            a->Size--;
            printf("已成功删除联系人: %s\n", name);
            return true;
        }
    }
    printf("删除失败：未找到姓名为 %s 的联系人！\n", name);
    return false;
}

// 按电话删除联系人
bool DeleteByNumber(Book *a, const char *number)
{
    if (a == NULL || number == NULL)
        return false;

    for (int i = 0; i < a->Size; i++)
    {
        if (strcmp(a->s[i].Number, number) == 0)
        {
            for (int j = i; j < a->Size - 1; j++)
            {
                a->s[j] = a->s[j + 1];
            }
            a->Size--;
            printf("已成功删除号码为 %s 的联系人！\n", number);
            return true;
        }
    }
    printf("删除失败：未找到号码为 %s 的联系人！\n", number);
    return false;
}

// 模糊查询（只要姓名或电话包含关键字即匹配）
void SearchFuzzy(const Book *a, const char *keyword)
{
    if (a == NULL || keyword == NULL)
        return;

    int count = 0;
    printf("\n---- 模糊查询结果 [关键字: %s] ----\n", keyword);
    for (int i = 0; i < a->Size; i++)
    {
        // strstr 用于检查子串是否存在
        if (strstr(a->s[i].Name, keyword) != NULL || strstr(a->s[i].Number, keyword) != NULL)
        {
            printf("姓名: %-12s \t号码: %s\n", a->s[i].Name, a->s[i].Number);
            count++;
        }
    }
    if (count == 0)
    {
        printf("未找到匹配的结果。\n");
    }
    printf("-------------------------------\n\n");
}
// 按电话查找联系人
void SearchNameByNumber(const Book *a, char *number)
{
    for (int i = 0; i < a->Size; i++)
        if (strstr(a->s[i].Number, number))
            printf("这个电话的联系人是：%s\n", a->s[i].Name);
}
// 按名字查找电话
void SearchNumberByName(const Book *a, char *name)
{
    for (int i = 0; i < a->Size; i++)
        if (strstr(a->s[i].Name, name))
            printf("这个联系人的电话是：%s\n", a->s[i].Number);
}
// 修改联系人名字和电话
bool ChangeBook(Book *a, char *name, char *number)
{
    printf("请输入要修改的联系人姓名:%s,号码:%s\n", name, number);
    for (int i = 0; i < a->Size; i++)
    {
        if (strstr(a->s[i].Name, name) || strstr(a->s[i].Number, number))
        {
            printf("请输入想修改的内容：\n");
            char NewName[20];
            char NewNumber[20];
            scanf("%s %s", NewName, NewNumber);
            strcpy(a->s[i].Name, NewName);
            strcpy(a->s[i].Number, NewNumber);
            return true;
        }
    }
    return false;
   
}

