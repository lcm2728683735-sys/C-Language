#include <stdio.h>

int main()
{
    long double result = 1;
    for(int i =1; i<= 26; i++)
    {
        result *= i;
    }
    printf("%lf\n",result);

    int count = 0;
    while(1 *  result / 2 != 0)
    {
        count++;
    }
    printf("count : %d result \n",count);
    return 0;
}