#include <stdio.h>
#include <string.h>

int MyStrlen(const char *a)
{
    int count = 0;
    while (*a != '\0')
    {
        a++;
        count++;
    }
    return count;
}

int MyStrcmp(const char *a, const char *b)
{
    while (*a != '\0' && *b != '\0' && *a == *b)
    {
        a++;
        b++;
    }
    return *a - *b;
}
int MyStrncmp(const char *a, const char *b, int n)
{
    while (n > 0 && *a != '\0' && *b != '\0' && *a == *b)
    {
        a++;
        b++;
        n--;
    }
    if (n == 0)
        return 0;
    return *a - *b;
}

void MyStrcpy(char *a, const char *b)
{
    while (*b != '\0')
    {
        printf("%d %d\n", *a, *b);
        printf("%p %p\n", a, b);
        *a++ = *b++;
        printf("%d %d\n", *a, *b);
        printf("%p %p\n", a, b);
    }
    *a = '\0';
}

void MyStrncpy(char *a, const char *b, int n)
{
    while (*b != '\0' && n != 0)
    {
        *a = *b;
        a++;
        b++;
        n--;
    }
    *a = '\0';
}

char *MyStrcat(char *a, const char *b)
{
    MyStrcpy(a + MyStrlen(a), b);
    return a;
}

char *MyStrncat(char *a, const char *b, int n)
{
    MyStrncpy(a + MyStrlen(a), b, n);
    return a;
}

char* MyStrstr(char *a, const char *b)
{
    int c = MyStrlen(a);
    int d = MyStrlen(b);

    for (int i = 0; i <= c - d; i++)
    {
        if (MyStrncmp(a + i, b, d) == 0)
        {
            return a + i;
        }
    }
    return NULL;
}


//功能：根据b字符串里面的字符，分割a字符串，返回被切割下来的字符串的首地址
//1、如何分割字符串？把b集合中出现的所有字符变成'\0'
//2、规定函数每次调用只切割一次字符串
//3、用static变量去保存没有切割完的位置
//4、当a传入NULL的时候，代表接着切割存储的字符串
//5、当存储的字符串被切割完毕后，返回NULL


//实现代码的逻辑：
//0、入参检查，如果是NULL，就使用我们存储的东西
//1、找到第一个有效字符
//2、开始切割——找到下一个分隔符，把他换成'\0'
//3、先将无效字符往后移一位并保存——保存我们需要接着切割的字符串的地址
//4、返回我们的被切割下来的字符串——第一个有效字符的地址

//a为要分割的字符串，b为分割符集合
char *MyStrtok(char *a, char *b)
{
    //上一次切割后的下一个字符串首地址
    static char *nextStr = NULL;
    //想切割上一次的字符串
    if (a == NULL)
        a == nextStr;
    if (a == NULL)
        return NULL;
    if (*a == '\0')
    {
        return NULL;
    }
    // 跳过分隔符
    while (*a != '\0')
    {
        char temp[] = {*a, '\0'};
        if (MyStrstr(b, temp) != NULL)
        {
            a++;
        }
        else
        { 
        break;
        }
    }
    if (*a == '\0')
    {
        return NULL;
    }
    // a 有效字符串的首地址
    char *end = a;
    while (*end != '\0')
    {
        char temp[]= {*end, '\0'};
        // 当前字符是分隔符
        if (MyStrstr(b, temp) != NULL)
        {
            break;
        }
        // 有效字符
        else
        {
            end++;
        }
    }
    //到字符串结尾
    if (*end == '\0')
    {
        //下一个要切割的字符串不存在了
        nextStr = NULL;
    }
    else
    {
        *end = '\0';
        //下一个字符串的地址
        nextStr = end + 1;
    }
    
    return nextStr;
}

int main()
{
    // char a[20] = "12345abc";
    // char b[] = "345";
    // int c = 10;
    // int d = 20;
    // float e = 11.0;
    // printf("%p\n",a);
    // printf("%p\n",b);
    // printf("%p\n",&c);
    // printf("%p\n",&d);
    // printf("%p\n",&e);
    // MyStrncpy(a,b,sizeof(a) - 1);
    // printf("%s\n",a);
    char s[] = ",,,!andy.jue,yes";
    char *dest = MyStrtok(s, ",!.");
    while (dest != NULL)
    {
        printf("%s\n", dest);
        dest = MyStrtok(NULL, ",!.");
    }
    return 0;
} 