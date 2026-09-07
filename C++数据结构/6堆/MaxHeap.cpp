#include <iostream>

const int capacity = 10;

class MaxHeap
{
public:
    MaxHeap():size(0){}
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
        while(i>0 && array[i]>array[GetParent(i)])
        {
            std::swap(array[i],array[GetParent(i)]);
            i = GetParent(i);
        }
    }
    void SiftDown(int i)
    {
        int leftChild = GetLeftChild(i);
        int rightChild = GetRightChild(i);

        int Max = i;
        if(leftChild < size && array[leftChild]>array[i])
        {
            Max = leftChild;
        }

        if(rightChild < size && array[rightChild] > array[Max])
        {
            Max = rightChild;
        }

        if(Max != i)
        {
            std::swap(array[i],array[Max]);
            SiftDown(Max); 
        }
    }
    int array[capacity];
    int size;
};


int main()
{
    MaxHeap h;
    for(int i= 0; i< 10; i++)
    {
        h.Insert(i+1);
    }
    h.show();
    h.RemoveRoot();
    h.show();    
    return 0;
}