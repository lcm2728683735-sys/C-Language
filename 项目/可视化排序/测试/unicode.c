#include <stdio.h>

int main() {
    // 直接把 █ 放在双引号里
    printf("█"); 
    
    // 循环打印 5 次
    for (int i = 0; i < 5; i++) {
        printf("█");
    }
    printf("\n");

    return 0;
}