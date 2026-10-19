#include <iostream>
#include <StdMsgQueue.h>

int main()
{
    StdMsgQueue q("./",1);

    q.Read(255);

    q.Remove();
    return 0;
}