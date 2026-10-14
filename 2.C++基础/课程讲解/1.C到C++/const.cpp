#include <iostream>

int main()
{
    const int a = 10;
    int *p = (int *)&a;
    *p = 20;
    printf("a:%d *p : %d\n",a,*p);
    printf("a:%p *p : %d\n",&a,*p);

}