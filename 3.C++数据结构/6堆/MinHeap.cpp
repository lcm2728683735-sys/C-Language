#include <iostream>
#include <time.h>
const int capacity = 10;

class MinHeap
{
public:
    MinHeap():size(0){}
    void Insert(int value)
    {
        array[size] = value;
        SiftUp(size);
        size++;
    }
    //删除根
    void RemoveRoot()
    {
        if(size == 0)
            return;
        array[0] = array [--size];
        SiftDown(0);
    }

    int& GetRoot()
    {
        return array[0];
    }

    void show()
    {
        for(int i = 0;i<size; i++)
        {
            std::cout<< array[i]<<" ";
        }
        std::cout << std::endl;
    }
private:
    int GetParent(int i){return (i-1)/2;}
    int GetLeftChild(int i){return 2*i+1;}
    int GetRightChild(int i){return 2*i+2;}
    void SiftUp(int i)
    {
        while(i>0 && array[i]<array[GetParent(i)])
        {
            std::swap(array[i],array[GetParent(i)]);
            i = GetParent(i);
        }
    }
    void SiftDown(int i)
    {
        int leftChild = GetLeftChild(i);
        int rightChild = GetRightChild(i);

        int Min = i;
        if(leftChild < size && array[leftChild] < array[i])
        {
            Min = leftChild;
        }

        if(rightChild < size && array[rightChild] < array[Min])
        {
            Min = rightChild;
        }

        if(Min != i)
        {
            std::swap(array[i],array[Min]);
            SiftDown(Min); 
        }
    }
    int array[capacity];
    int size;
};


int main()
{
    srand(time(nullptr));
    int a[20];
    for(int i = 0;i<20;i++)
    {
        a[i]=rand()% 100 + 1;
    }
    for(int i = 0; i < 20;i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout<<std::endl;
    MinHeap h;
    for(int i = 0; i<20;i++)
    {
        if(i<5)
        {
            h.Insert(a[i]);
        }
        else
        {
            if(a[i] > h.GetRoot())
            {
                h.RemoveRoot();
                h.Insert(a[i]);
            }
        }
    } 
    h.show();
    return 0;
}