#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool BackStr(const char *a)
{
    int length = strlen(a);
    for (int i = 0; i < length / 2; i++)
    {
        if (a[i] != a[length - i - 1])
        {
            printf("这不是回文！");
            return false;
        }
    }
    printf("这是回文！");
    return true;
}

int main()
{
    int temp = 12321;
    
    char a[] = {1,2,3,4,5};
    char b[] = {1,2,3,2,1};
    BackStr(a);
    BackStr(b);
    return 0;
}