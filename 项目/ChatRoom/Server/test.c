// #include <stdio.h>
// #include <unistd.h>
// #include "StdThreadPool.h"

// void * func(void * arg)
// {
//     printf("我打印%ld\n",(long)arg);
// }

// int main()
// {
//     ThreadP *p = ThreadPoolInit(5,2,10,3);
//     for(long i = 0;i < 20;i++)
//     {
//         ThreadPoolAddTask(p,func,(void*)i+1);
//     }
//     sleep(3);
//     ClearThreadPool(p);
//     return 0;
// }