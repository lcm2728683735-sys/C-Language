#include <stdio.h>
#define Size 3
#if 1
void PrintArray(int *a)
{
    printf("size %ld\n",sizeof(a));
    for(int i = 0;i<Size;i++)
    {
        printf("%d\n",a[i]);
    }
}
#endif
int main()
{
#if 1
    int a[Size] = {1,2,3};
    int *p = a;
    printf("%d",*p);
    for(int i = 0;i<Size;i++)
    {
        printf("%d\n",*(p+i));
    }
    PrintArray(a);
    printf("%p %p\n",a,&a[0]);
#endif
    return 0;
}
