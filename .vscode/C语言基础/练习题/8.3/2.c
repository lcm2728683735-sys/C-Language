#include <stdio.h>

int main()
{

    for (int a = 1; a <= 100; a++)
    {
        if(a % 7 == 0)
        printf("%d ", a);                                                             
    }
    printf("\n");
    return 0;
}