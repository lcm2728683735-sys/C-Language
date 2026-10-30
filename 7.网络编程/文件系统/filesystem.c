#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

#define DIR_PATH "/home/lvguanzhong/code/项目/ChatRoom"

int DirNums = 0;
int FileNums = 0;


void ExploreDIR(const char *dirPath,int deepth)
{
    DIR *dir = opendir(dirPath);
    if(dir == NULL)
    {
        printf("文件夹路径不存在!\n");
        return;
    }
    struct dirent * entry = NULL;
    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0)
            continue;
        for(int i = 0;i < deepth;i++)
            printf("————");//根据深度打印
        printf("%s\n",entry->d_name);
        if(entry->d_type == DT_DIR)
        {
            if(entry->d_name[0] == '.')
                continue;
            DirNums++;
            char path[1024] = {0};
            sprintf(path,"%s/%s",dirPath,entry->d_name);
            ExploreDIR(path,deepth+1);
        }
        else
        {
            FileNums++;
        }
    }
    closedir(dir);
}

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        printf("命令行参数数量不为2\n");
        return -1;
    }
    ExploreDIR(argv[1],0);
    printf("%d 文件夹 %d 文件\n",DirNums,FileNums);
    return 0;
}