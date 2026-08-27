#include <iostream>
//策略模式
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
    void sort(int *a,int size)
    {
        std::cout<<"快速排序"<<std::endl;
        FSort(a,0,size - 1);
    }
private:
    void FSort(int *a,int start,int end)
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
        FSort(a,start,left-1);
        FSort(a,right+1,end);
    }
};

void S(Sort *s)
{
    int a[] = {3,1,2};
    s->sort(a,3);
    for(int i = 0;i<3;i++)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}

int main ()
{
    Sort *s1 = new BubbleSort;
    Sort *s2 = new FastSort;
    // Sort *s3 = new InsertSort;
    BubbleSort *s = new BubbleSort;
    return 0;
}