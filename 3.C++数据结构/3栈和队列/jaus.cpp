#include <iostream>
#include "LinkQueue.h"

const int size = 31;
int main()
{
    LinkQueue q;
    for(int i = 0;i< size; i++)
    {
        q.Push(i+1);
    }

    int count=0;

    while(q.Size() > 1)
    {
        int num = q.GetFront();
        count++;
        q.Pop();
        if(count == 3)
        {
            std::cout<<num<<"被杀死\n";
            count = 0;
        }
        else
            q.Push(num);
    }
    std::cout<<q.GetFront()<<"活了下来!"<<std::endl;
    return 0;
}