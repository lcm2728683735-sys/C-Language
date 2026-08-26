#include <iostream>

class Sort
{
public:
    virtual void sort(int *a,int size)= 0;
};

class BubbleSort:public Sort
{
public:
    void sort(int *a,int size)
    {
        for(int i = 0;i <size-1;i++)
        {
            for(int j =0;j<size-1-i;j++)
            {
                if(a[j]>a[j+1])
                std::swap(a[j],a[j+1]);
            }
        }
    }
};
class FastSort:public Sort
{
public:
    void Fsort(int *a,int start,int end)
    {
        if(start >= end)
            return;
        int left = start;
        int right = end;
        int temp = a[left];
        while(left <right)
        {
            while(a[right] > temp && left < right)
                right--;
            if(left > right)
                a[left++] = a[right];
            while(a[left] < temp && left < right)
                left++;
            if(left < right)
                a[left++] = a[right];
        }
    }
};


int main ()
{
    BubbleSort *s = new BubbleSort;
    return 0;
}