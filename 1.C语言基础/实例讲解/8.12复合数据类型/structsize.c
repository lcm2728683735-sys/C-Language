#include <stdio.h>
#include <string.h>

struct Test
{
    char c[9];
    int a;
    double b; 
};
typedef struct Test test;
 
int main()
{
    test t;
    printf("%ld\n",sizeof(test));
    printf("%p %p %p %p\n",&t,&t.a,&t.b,&t.c);
    return 0;
}