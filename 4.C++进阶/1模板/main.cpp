// #include "DoubleLinkList.hpp"

// int main ()
// {
//     DoubleLinkList<int> list;
//     for(int i =0; i < 10;i++)
//     {
//         list.InsertTail(i + 1);
//     }

//     std::cout << list;
//     list.RemoveByIndex(0);
//     std::cout <<list;
//     return 0;
// }

#include "LinkQueue.hpp"

int main()
{
    // LinkQueue<int> q;
    // for(int i =0;i < 10; i++)
    // {
    //     q. Push(i+1);
    // }
    // return 0;

    // while(q.IsEmpty() == false)
    // {
    //     std::cout << q.GetFront() << " ";
    //     q.Pop();
    // }
    // return 0;

    DoubleLinkList<int> l;
    int a = l.GetHead();
    return 0;
}