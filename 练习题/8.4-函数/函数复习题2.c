#include <stdio.h>

int CtoF(int a)
{ 
    return a*1.8 + 32;
}

int main()
{
    int C = 100;
    printf("华氏度是：%d",CtoF(C));
    return 0;
}