#include <iostream>

 #define NodeSize 8
class MemoryPool
{

private:
    //
    union FreeNode
    {
        char data[NodeSize];
        FreeNode *next;
    };
};  