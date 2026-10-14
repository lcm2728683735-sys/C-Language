#include <iostream>

int main()
{
    //堆上内存的管理
    //1、自行计算所需内存大小
    //2、返回指针不需要强制转换
    //3、不需要判断返回指针为空，如果申请失败会抛出异常
    //默认终止程序

    // int *a = new int; 
    // int *a1 = (int*)malloc(sizeof(int));
    // *a = 10;
    // std::cout<<*a<<std::endl;
    // delete a;

    //一维数组
    // int *a = new int[10];
    // for(int i = 0;i < 10;i++)
    // {
    //     a[i] = i+1;
    //     std::cout<<a[i]<<std::endl;
    // }
    // delete []a;
    // return 0;

    //二维数组
    int **a = new int*[2];
    for(int i = 0;i< 2; i++)
    {
            a[i] = new int[3];
    }
    for(int i =0;i<2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            a[i][j] = i * 3 + j;
        }
    }

    for (int i = 0 ;i<2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


    for(int i =0;i<2;i++)
    {
        delete[]  a[i];
    }
    return 0;

}