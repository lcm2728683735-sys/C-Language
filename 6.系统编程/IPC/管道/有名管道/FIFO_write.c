#include <SysHeader.h>


int main ()
{
    //创建一个新管道文件，可读可写
    //linux 0: 成功 -1失败
    // if(mkfifo("myfifo",S_IRUSR | S_IWUSR) < 0)
    // {
    //     perror("mkfifo:");
    //     return -1;
    // }
    int fd = open("myfifo",O_WRONLY);
    if(fd < 0)
    {
        perror("open:");
        return -1;
    }
    while(1)
    {
        char str [1024] = {0};
        printf("请输入要写的数据:");
        scanf("%s",str);
        write(fd,str,1024);
    }
    return 0;
}