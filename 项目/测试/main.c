#include <stdio.h>

int main() {
    int a[2] = {'a', 'b'};

    for (int i = 0; i < 2; i++) {
        // 条件：小于 '0' 或者 大于 '9'（即不是数字）
        if (a[i] < '0' || a[i] > '9') {
            printf("字符 '%c' 是非法字符（非数字）\n", a[i]);
        }
    }
    return 0;
}