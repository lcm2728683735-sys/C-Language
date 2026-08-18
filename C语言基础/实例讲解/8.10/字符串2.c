#include <stdio.h>
#include <string.h>

int atoi(const char *a)
{
    int result = 0;
    int sign = 1;
    {
        if (*a == '-')
        {
            sign = -1;
        }
        if (*a >= '0' && *a <= '9')
        {
            for (int i = 0; i < strlen(a); i++)
            {
                result = result * 10 + (a[i] - '0');
            }
        }
        return result * sign;
    }
}

int main()
{
    const char *str = "-123123";
    int a = atoi(str);
    printf("%d\n",a);
    return 0;
}