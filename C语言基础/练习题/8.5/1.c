#include <stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;

    printf("a = %d\nb = %d \n",*a,*b);
}

int main()
{
    int c = 1;
    int d = 2;
    swap(&c,&d);
    printf("c = %d\nd = %d \n",c,d);

    return 0;
}