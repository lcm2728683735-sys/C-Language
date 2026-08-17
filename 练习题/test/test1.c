#include <stdio.h>
#include <string.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int DoubleRankSort(int *c,int size)
{
    for (int left = 0, right = size - 1; left < right; left++, right--)
    {
        int min = left, max = right;
        for (int i = left; i <= right; i++)
        {
            if (c[min] > c[i])
            {
                min = i;
            }
            if (c[max] < c[i])
            {
                max = i;
            }
        }
        Swap(&c[left], &c[min]);
        if(max == left)
        {
            max = min;
        }
        Swap(&c[right], &c[max]);
    }
}

int main()
{
    int d[] = {1,2,3,4,5};
    printf("%ls\n",d);
    DoubleRankSort(d,5);
    printf("%ls\n",d);
    return 0;
}