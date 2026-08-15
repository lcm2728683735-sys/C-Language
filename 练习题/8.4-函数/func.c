#include <stdio.h>

int add(int a, int b)
{
    int c = a + b;
    return c;
}

void swap(int a1, int b1);

int main()
{
    int a = 10;
    int b = 20;
    swap(a, b);
    printf("%d %d\n", a, b);

    return 0;
}

void swap(int a1, int b1)
{
    int temp = a1;
    a1 = b1;
    b1 = temp;
    return;
}