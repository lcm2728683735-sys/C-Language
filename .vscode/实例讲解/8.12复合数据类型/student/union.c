#include <stdio.h>
#include <stdlib.h>
//联合体：多个成员变量 共用同一份内存
//语法规则和结构体类似
union Temp
{
    int a;
    char b;
};

typedef union Temp Temp;

int main()
{
    Temp temp;
    temp.a;
    Temp * temp1 = (Temp *)malloc(sizeof(Temp));
    temp1->b;

    //如何分辨大小端
    temp.a = 257;
    temp.b = 0;
    printf("%d\n",temp.a);

    return 0;
}