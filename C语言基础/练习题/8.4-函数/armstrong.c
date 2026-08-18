# include <stdio.h>
# include <math.h>
int main()
{
    for(int i=100;i<=999;i++)
    {
        int units = i % 10;
        int hundred = i / 100;
        int decade = i%100/10;
        if(i == pow(units,3) + pow(hundred,3) + pow(decade,3))
        printf("%d\n",i);
    }
    return 0;
}