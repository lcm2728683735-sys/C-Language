#include <stdio.h>

#define Color_Yellow "\033[33m"
#define Color_Red "\033[31m"
#define Color_Green "\033[32m"
#define Color_Reset "\033[0m"

int main() {
    // 循环打印 5 次
    for (int i = 0; i < 5; i++) 
    {
        printf(Color_Green);
        printf("█");
    }
    printf("\n");

    return 0;
}