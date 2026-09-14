#include <stdio.h>
#include <math.h>

int reverse_number(int n)
{
    int reversed = 0;

    while (n > 0)
    {
        int digit = n % 10;               // 1. 取出 n 的末位数字
        reversed = reversed * 10 + digit; // 2. 拼接到结果的末尾
        n = n / 10;                       // 3. 砍掉 n 的末位数字
    }
    return reversed; // 返回最终翻转好的数字
}
int main()
{
    int a =678;
    printf("%d \n", reverse_number(a));
    return 0;
}