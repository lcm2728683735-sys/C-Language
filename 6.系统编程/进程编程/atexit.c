#include <sys/types.h>//系统调用
#include <sys/wait.h>//wait pid
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

FILE *f;

void clear()
{
    fclose(f);
    printf("关闭文件描述符\n");
}

int main ()
{
    //注册清理函数
    atexit(clear);

    f = fopen("1.txt","w");
    int b = 1;

    if(b != 0)
        exit(-1);//退出进程
    
    fclose(f);
    return 0;
}