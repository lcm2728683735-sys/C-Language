#include <iostream>
#include "DoubleLinkList.h"
#include "LinkStack.h"
bool IsOper(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '=':
        return true;
    default:
        return false;
    }
}

bool IsNum(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int Operation(int prev, int next, char symbol)
{
    switch (symbol)
    {
    case '+':
        return prev + next;
        break;
    case '-':
        return prev - next;
        break;
    case '*':
        return prev * next;
        break;
    case '/':
        if (next == 0)
        {
            printf("除以零");
            exit(-1);
        }
        return prev / next;
        break;
    default:
        exit(-1);
    }
}

char Precede(char ch1, char ch2)
{
    int row = 0, column = 0;
    switch (ch1)
    {
    case '+':
        row = 0;
        break;
    case '-':
        row = 1;
        break;
    case '*':
        row = 2;
        break;
    case '/':
        row = 3;
        break;
    case '(':
        row = 4;
        break;
    case ')':
        row = 5;
        break;
    case '=':
        row = 6;
        break;
    default:
        break;
    }
    switch (ch2)
    {
    case '+':
        column = 0;
        break;
    case '-':
        column = 1;
        break;
    case '*':
        column = 2;
        break;
    case '/':
        column = 3;
        break;
    case '(':
        column = 4;
        break;
    case ')':
        column = 5;
        break;
    case '=':
        column = 6;
        break;
    default:
        break;
    }
    char pre[7][7] =
        {
            {'>', '>', '<', '<', '<', '>', '>'},
            {'>', '>', '<', '<', '<', '>', '>'},
            {'>', '>', '>', '>', '<', '>', '>'},
            {'>', '>', '>', '>', '<', '>', '>'},
            {'<', '<', '<', '<', '<', '=', '0'},
            {'>', '>', '>', '>', '0', '>', '>'},
            {'<', '<', '<', '<', '<', '0', '='}};
    return pre[row][column];
}

int main()
{
    LinkStack NumS;
    LinkStack OperS;
    OperS.Push('=');
    char str[64] = {0};
    scanf("%[^\n]", str);

int i = 0;
while (str[i] != '\0' && (str[i] != '=' || OperS.GetTop() != '='))
{
    if (str[i] == ' ')
    {
        i++;
        continue;
    }

    if (IsNum(str[i]))
    {
        int num = 0;
        while (IsNum(str[i]))
        {
            num = 10 * num + (str[i] - '0');
            i++;
        }
        std::cout << "num:" << num << std::endl;
        NumS.Push(num);
    }
    else if (IsOper(str[i]))
    {
        bool done = false;
        while (!done)
        {
            char pre = Precede(OperS.GetTop(), str[i]);

            switch (pre)
            {
            case '>':
            {
                int next = NumS.GetTop(); NumS.Pop();
                int prev = NumS.GetTop(); NumS.Pop();
                char op  = OperS.GetTop(); OperS.Pop();
                int result = Operation(prev, next, op);
                std::cout << "计算: " << prev << op << next << " = " << result << std::endl;
                NumS.Push(result);
                break;          // 继续 while 比较
            }
            case '<':
            {
                OperS.Push(str[i]);
                i++;
                done = true;
                break;
            }
            case '=':
            {
                OperS.Pop();    // 脱括号或结束
                i++;
                done = true;
                break;
            }
            default:
                std::cout << "表达式有误\n";
                return -1;
            }
        }
    }
    else
    {
        std::cout << "非法字符\n";
        return -1;
    }
}

std::cout << "答案是： " << NumS.GetTop() << std::endl;
    return 0;
}