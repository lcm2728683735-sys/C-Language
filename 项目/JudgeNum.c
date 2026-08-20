#include <stdio.h>
#include <stdlib.h>
#include "JudgeNum.h"

// 判断是否为数字
int JudgeNum(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        printf("输入为空\n");
        return 0;
    }
    //判断负数
    if(str[0] == '-' && str[1] == '\0')
    {
        printf("单个字符 '-'是非法输入！\n");
        return 0;
    }

    int Start_Index = 0;
    if (str[0] == '-')
    {
        Start_Index = 1;
    }

    int JudgeResult = 1;

    for (int i = Start_Index; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("字符 '%c' 是非法字符，请重新输入！\n", str[i]);
            JudgeResult = 0;
        }
    }
    return JudgeResult;
}

//判断数组里每个元素
int ValidStruct(InputArray arr)
{
    if(arr.size < 5 || arr.size>25)
    {
        printf("数组元素个数不在合法范围内，请重新输入！");
        return 0;
    }
    //引入状态变量
    int All_Right = 1;

    for (int i = 0; i < arr.size;i++)
    {

        if(!JudgeNum(arr.array[i]))
        {
            All_Right = 0;
        }
    }
    return All_Right;
}

int main()
{

    // 用例 2：数量符合要求（5个），但包含非法字符 "314a" 和 "528gs"
    char *test2[] = {"-121", "314", "105", "528", "999"};
    InputArray input2 = { test2, sizeof(test2) / sizeof(test2[0]) };

    printf("============ 测试带负号===========\n");
    if (ValidStruct(input2)) {
        printf(">>> 结果：校验通过\n\n");
    } else {
        printf(">>> 结果：校验失败\n\n");
    }
    return 0;
}