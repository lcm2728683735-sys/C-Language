#include "BinaryTree.h"
#include <iostream>


int main()
{
    int a[7] = {1,2,3,4,5,6,7};
    BinaryTree tree;
    for(int i =0; i< 7;i++)
    {
        tree.Insert(a[i]);
    }
    

    tree.show();
    tree.show();


    
}