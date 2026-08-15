#include <stdio.h>
#define Max(a,b) ((a)>(b))?(a):(b)
int main()
{
    int x =7;
    int y =8;
    int z =9;
    printf("最大值是 %d\n",Max(Max(x,y),z));
    return 0;
}