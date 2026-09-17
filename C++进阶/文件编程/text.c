#include <stdio.h>
#include <stdlib.h>
void OpenFileByRead(const char* destFile)
{    
    FILE *f = fopen(destFile,"r");
    if(f == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    printf("文件打开成功！\n");
}

void CloseFileByRead(const char* destFile)
{
    FILE *f = fopen(destFile,"r");
    fclose(f);
}
    
void CopyFile(const char* destFile, const char * srcFile,int CountSize)
{
    FILE *fr = fopen(srcFile,"r");
    if(fr == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    FILE *fw = fopen(destFile,"w");
    if(fw == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    fseek(fr,0,SEEK_END); 
    long fileSize = ftell(fr);
    fseek(fr,0,SEEK_SET); 

    //分步读
    int readSize = 0;
    char *s = (char*)malloc(fileSize);
    while(readSize < fileSize)
    {
        fread(s,fileSize,1,fr); 
        fwrite(s,fileSize,1,fw);
        readSize +=40;
    }
    free(s);
    fclose(fr);
    fclose(fw);
}



int main()
{
    // 绝对路径：根目录开始的路径
    // 相对路径：相对于执行程序的路径
    // w:只写文件不存在就创建新文件，存在就清空文件 
    // r:只读文件不存在就报错
    // a:如果文件不存在就创建，否则追加写
    // FILE *f = fopen("./text.c","r");
    // if(f == NULL)
    // {
    //     printf("文件打开失败！\n");
    //     return -1;
    // }
    // printf("文件打开成功！\n");

    // char c = 0;
    // while((c= fgetc(f))!= EOF)
    // {
    //     printf("%c",c);
    // }
    // printf("\n");
    // fclose(f);
    // CopyFile("./text.txt","./text1.txt");
    // FILE *f = fopen("./text1.txt","r");
    // char c = 0;
    // while((c= fgetc(f))!= EOF)
    // {
    //     printf("%c",c);
    // }
    //  printf("\n");

    // FILE *f = fopen("./text.txt","w");
    // if(f == NULL)
    // {
    //     printf("文件打开失败！\n");
    //     return -1;
    // }
    // char s[256] = {0};
    // fputs(s,f); //读一行
    // printf("%s\n",s);

    // ptr:文件内容读取到内存中的地址 
    // size:读取的大小
    // n:读取的次数

    //光标移动到末尾
    // fseek(f,0,SEEK_END); 
    // 返回光标到初始位置的偏移量
    // long fileSize = ftell(f);
    // fseek(f,0,SEEK_SET); 

    // char *s = (char*)malloc(fileSize);
    // fread(s,fileSize,1,f); 
    // FILE *fw = fopen("./new.txt","w");
    // fwrite(s,fileSize,1,fw);
    // fclose(f);  
    CopyFile("./text.txt","./text1.txt",40960);
    // rewind(); // = fseek(f,0,SEEK_SET)
    return 0;
}