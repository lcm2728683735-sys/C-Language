// 标准输入输出库
#include <stdio.h>

//gcc helloworld.c -o 1 生成名叫1的可执行程序
//gcc helloworld.c 生成默认可执行程序(a.out)


// 条件语句

int main()
{
    int a = 0;
    if (a < 10)
    {
        printf("a<10\n");
    }
    else if (a >= 10 && a < 20)
    {
        printf("10 < a < 20\n");
    }
    else
    {
        printf("a > 20");
    }

    a = 2;
    switch (a)
    {
    case 1:
    {
        printf("a = 1\n");
        break;
    }
    case 2:
    {
        printf("a = 2\n");
        break;
    }
    case 3:
    {
        printf("a = 3\n");
        break;
    }
    default:
        break;
    }


    //循环语句
    //for()
    //定义循环条件 循环条件 修改循环条件
    for(int i = 0; i < 10 ; ++i)
    {
        printf("%d ",i);
    }
    printf("\n");

    int k = 0;
    while(k < 10)
    {
        printf("%d ",k++);
    }
    printf("\n");

    //while()
    //do while()
    int j = 0;
    do
    {
        printf("%d ",++j);
    } while (j < 10);
    

    printf("hello world!\n");

    return 0;
}