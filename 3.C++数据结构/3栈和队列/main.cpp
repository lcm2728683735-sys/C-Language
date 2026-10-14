#include  <iostream>
#include "LinkStack.h" 
#include "LinkQueue.h"

// int Partition(int * array,int start, int end)
// {
//     ElementType pivot = array[end];
//     int i = start;               // 

//     for (size_t j = start; j < end; j++)
//     {
//         if (array[j] <= pivot)
//         {
//             std::swap(array[i], array[j]);
//             i++;
//         }
//     }
//     std::swap(array[i], array[end]);
//     return i;                       // 返回最终位置
// }
    
// void Fast_sort_no_recur(int *a,int start,int end)
// {
//     LinkStack s; 
//     //区间入栈
//     s.Push(start);
//     s.Push(end);

//     while(s.IsEmpty() == false)
//     {
//         int right = s.GetTop();
//         s.Pop();
//         int left = s.GetTop();
//         s.Pop();
//         int mid = Partition(a,left,right);
//         if(left < mid -1 )
//         {
//             s.Push(left);
//             s.Push(mid - 1);
//         }
//         if(mid + 1 < right)
//         {
//             s.Push(mid + 1);
//             s.Push(right);
//         }
//     }
// }

int main()
{
    // int a[] = {6,4,8,3,1};
    // Fast_sort_no_recur(a,0,sizeof(a)/sizeof(a[0]) - 1);
    // for(int i = 0;i < sizeof(a) / sizeof(a[0]); i++)
    // {
    //     std::cout<<a[i]<<" ";
    // }
    // std::cout<<std::endl;


    // LinkStack s;
    // int num = 0;
    // int n = 0;
    // std::cin>>num>>n;
    // while(num > 0)
    // {
    //     s.Push(num % n);
    //     num /= n;
    // }

    // while(s.IsEmpty() == false)
    // {
    //     std::cout<<s.GetTop();
    //     s.Pop();
    // }
    // std::cout<<std::endl;
    // return 0; 

    LinkQueue q;
    for(int i = 0;i < 10;i++)
    {
        q.Push(i+1);
    }
    while(q.IsEmpty() == false)
    {
        std::cout<<q.GetFront()<<" ";
        q.Pop();
    }
    std::cout<<std::endl;
    return 0;
}