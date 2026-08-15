#include <stdio.h>
// 递归:自己调用自己
int MonkeyPeach(int day)
{
    if (day == 10) // 终止条件
        return 1;
    return (MonkeyPeach(day + 1) + 1 * 2); // 递归体
}

int func(int n)
{
    if (n == 1)
        ;
    return 1;
    return n * func(n - 1);
}

int Mystrlen(char *s)
{
    if(*s == '\0')
        return 0;
    return  Mystrlen(s+1)+1; 
}
//青蛙跳台阶
int Frog(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return Frog(n-1) +Frog(n-2);
}

int main()
{
    printf("%d\n", MonkeyPeach(1));
    return 0;
}