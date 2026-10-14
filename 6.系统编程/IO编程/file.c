#include <stdio.h>

void CopyFile(const char * destFile,const char *srcFile)
{
    FILE * fdest = fopen(destFile,"w");
    if(fdest == NULL)
        return;
    FILE * fsrc = fopen (srcFile,"r");
    if(fsrc == NULL)
        return;

    char c = 0;
    while((c = fgetc(fsrc)) != EOF)
        fputc(c,fdest);
    fclose(fdest);
    fclose(fsrc);
}

struct Student
{
    int id;
    char name[16];
};


int main ()
{
    //FILE 文件指针
    //最小的权限打开
    //r 只写，文件不存在 打开失败
    //w 只读，文件不存在就创建
    //a 追加写，文件不存在就创建
    // FILE* f = fopen("./1.txt","a");
    // if(f == NULL)
    // {
    //     printf("文件打开失败!\n");
    //     return -1;
    // }
    // printf("文件打开成功！");
    //读一个文件
    //文件的终止符 EOF
    // char c = 0;
    // while((c = fgetc(f)) != EOF)
    //     printf("%c",c);
    // printf("\n");
     //关闭文件指针（归还文件描述符）
    // fclose(f);

    // FILE* f = fopen("./1.txt","w");
    // if(f == NULL)
    // {
    //     printf("文件打开失败!\n");
    //     return -1;
    // }
    // printf("文件打开成功！\n");
    
    // fputc('h',f);
    // fputc('e',f);
    // fputc('l',f);
    // fputc('l',f);
    // fputc('o',f);
    // fclose(f);

    // CopyFile("1.txt","笔记.md");


    // FILE* f = fopen("1.txt","r");
    // if(f == NULL)
    // {
    //     printf("文件打开失败!\n");
    //     return -1;
    // }
    // printf("文件打开成功！\n");

    //读取完后默认在结尾添加\0，能读的是n-1
    // char s[100] = {0};
    // fgets(s,100,f);
    // printf("%s\n",s);
    // fclose(f);
    // return 0;

    // FILE* f = fopen("1.txt","w");
    // if(f == NULL)
    // {
    //     printf("文件打开失败!\n");
    //     return -1;
    // }
    // printf("文件打开成功！\n");
    // fputs("helloworld\n",f);
    // fputs("hellofile",f);
    // fclose(f);

    // FILE* f = fopen("1.txt","w");
    // if(f == NULL)
    // {
    //     printf("文件打开失败!\n");
    //     return -1;
    // }

    // struct Student s;
    // fread(&s,sizeof(s),1,f);
    // printf("%d %s\n",s.id,s.name);
    // fclose(f);


    // char s[1024] = {0};
    // fread(s,1024,1,f);//读取一块数据(内存块)
    // printf("%s\n",s);
    // fclose(f);

    //格式化读写
    // FILE *f = fopen("1.txt","w");
    // struct Student s = {1,"zhangsan"};
    // fprintf(f,"id=%d name=%s",s.id,s.name);
    // fclose(f);

    // FILE *f = fopen("1.txt","r");
    // struct Student s;
    // fscanf(f,"id=%d name=%s", &s.id, s.name);
    // printf("%d %s\n",s.id,s.name);
    // fclose(f);

    // FILE *f = fopen("1.txt","a");
    // struct Student s = {2,"zhangsan"};
    // fprintf(f,"\nid=%d name=%s",s.id,s.name);
    // fclose(f);

    // FILE *f = fopen("1.txt","r");
    // char str[100] ={0};

    // fseek(f,0,SEEK_END);
    // printf("%ld\n",ftell(f));
    // //将光标移动到开头
    // rewind(f);
    // fread(str,100,1,f);
    // printf("%s\n",str);
    // fclose(f);

    FILE *f = fopen("1.txt", "a");
    while(1)
    {
        char str[100] = {0};
        scanf("%s",str);
        fprintf(f,"%s\n",str);
    }
    fclose(f);
    
    return 0;
}