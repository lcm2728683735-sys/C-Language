#include <iostream>
const int size = 10;

class Queen
{
public:
    Queen():front(0),rear(0){}
    void Push(int element)
    {
        array[rear++] = element;
        rear %= size;
    }
    void Pop()
    {
        front++;
        front %= size;
    }

    int& GetFront()
    {
        return array[front];
    }
    bool IsEmpty()
    {
        return front == rear;
    }
    bool IsFull()
    {
        return (rear+1)%size ==front;
    }

private:
    int array[size];
    int front;
    int rear;
};

int main()
{
    Queen q;
    for(int i =0;i<3;i++)
    {
        if(q.IsFull() == true)
        {
            std::cout<<"当前队列满："<<i+1<<std::endl;
            return -1;
        }
        q.Push(i+1);
    }
    while(q.IsEmpty()== false)
    {
        std::cout<<q.GetFront()<<" ";
        q.Pop();
    }
    std::cout<<std::endl;
    return 0;
}