#include <stdio.h>
#include <string.h>

size_t MyStrlen(const char *s)
{
    size_t count = 0;
    while (*s != '\0')
    {
        s++;
        count++;
    }
    return count;
}

int MyStrcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int MyStrncmp(const char *s1, const char *s2, int n)
{
    while (n>0 && *s1 == *s2 && *s1 != '\0' && *s2 != '\0' )
    {
        s1++;
        s2++;
        n--;
    }
    if (n)
    return *s1 - *s2;
}

// int main()
// {
//     char s1[] = "hella";
//     char s2[] = "hell";
//     printf("%d\n",MyStrcmp(s1,s2));
//     return 0;
// }

void MyStrcpy(char *dest, const char *src)
{
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
}

void MyStrncpy(char *dest, const char *src, int n)
{
    while (n-- != 0)
        *dest++ = *src++;
    *dest = '\0';
}

void MyStrcat(char *dest, const char *src)
{
    MyStrcpy(dest + MyStrlen(dest), src);
}

char *MyStrstr(char *dest, const char *src)
{
    size_t dlen = MyStrlen(dest);
    size_t slen = MyStrlen(src);

    for (int i = 0; i <= dlen - slen; i++)
    {
        if (MyStrncmp(dest + i, src, slen) == 0)
        {
            return dest + i;
        }
    }
    return NULL;
}

int main()
{
    return 0;
}