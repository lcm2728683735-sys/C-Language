#include <stdio.h>

int main()
{
    FILE *f = fopen("./new.txt","w");
    if(f == NULL)
    {
        printf("文件打开失败!\n");
        return -1;
    }
    char name[20] = "zhangsan";
    char tele[20] = "123";
    fprintf(f,"name = %s tele = %s\n",name,tele);


    // while(1)
    // {
         //返回值代表读取的字节数，-1代表读取结束
    //     if(fscanf(f,"%s %s\n",name,tele)<0)
    //     {
    //         break;  
    //     }
    //     fprintf("name:%s tele:%s\n",name,tele);
    // }
    fclose(f);
    return 0;
}