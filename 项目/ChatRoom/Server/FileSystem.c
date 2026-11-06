#include "FileSystem.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct FileSystem
{
    char * dirPath;
};

FileSys *FileSystemInit(const char *DirPath)
{
    // 分配整个结构体的大小
    FileSys * fs = (FileSys*)malloc(sizeof(struct FileSystem));
    if(fs == NULL)
    {
        printf("FileSystemInit malloc error!\n");
        return NULL;
    }

    DIR *dir;
    if((dir = opendir(DirPath)) == NULL)
    {
        if(mkdir(DirPath, 0777) != 0)
        {
            perror("mkdir");
            free(fs);
            return NULL;
        }
        fs->dirPath = strdup(DirPath);
        return fs;
    }
    else
    {
        closedir(dir);
        fs->dirPath = strdup(DirPath);
        return fs;
    }
}

bool CreateNewDirInfs(FileSys *fs, const char *DirName)
{
    if (fs == NULL || fs->dirPath == NULL) return false;
    char DirPath [1024] = {0};
    sprintf(DirPath,"%s/%s",fs->dirPath,DirName);
    
    // 如果目录已经存在，直接返回 true，防止重复注册时报错
    DIR *d = opendir(DirPath);
    if (d != NULL) {
        closedir(d);
        return true;
    }

    if(mkdir(DirPath,0777) != 0)
    {
        perror("mkdir");
        return false;
    }
    return true;
}

bool DeleteDirInFs(FileSys *fs, const char *DirName)
{
    if (fs == NULL || fs->dirPath == NULL) return false;
    char DirPath [1024] = {0};
    sprintf(DirPath,"%s/%s",fs->dirPath,DirName);
    if(rmdir(DirPath) != 0)
    {
        perror("rmdir");
        return false;
    }
    return true;
}

bool isDirExist(FileSys *fs, const char *DirName)
{
    if (fs == NULL || fs->dirPath == NULL) return false;
    DIR *dir = opendir(fs->dirPath);
    if(dir == NULL)
    {
        perror("isDirExist opendir");
        return false;
    }
    struct dirent * entry;
    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name,DirName) == 0)
        {
            closedir(dir);
            return true;
        }
    }
    closedir(dir);
    return false;
}

void WriteFileTofs(FileSys *fs, const char *DirName, const char *fileName, void *p, size_t size)
{
    if (fs == NULL || fs->dirPath == NULL || DirName == NULL || fileName == NULL || p == NULL) 
    {
        fprintf(stderr, "Error: WriteFileTofs received NULL pointer parameters!\n");
        return;
    }
    if (size == 0) 
    {
        return; 
    }

    char filePath[1024] = {0};
    sprintf(filePath,"%s/%s/%s",fs->dirPath,DirName,fileName);
    FILE *f = fopen(filePath,"a");
    if (f == NULL) 
    {
        fprintf(stderr, "*服务端错误* 无法写入文件: %s, 原因: ", filePath);
        perror("");
        return;
    }
    fwrite(p,size,1,f);
    fclose(f);
}

char *GetFileSize(const char * DirPath,const char * fileName)
{
    char filePath[1024] = {0};
    sprintf(filePath,"%s/%s",DirPath,fileName);

    struct stat st;
    if(stat(filePath,&st) != 0) {
        return strdup("0");
    }

    char size[20] = {0};
    sprintf(size,"%ld",st.st_size);
    return strdup(size);
}

char *GetFileList(FileSys *fs, const char *DirName)
{
    if (fs == NULL || fs->dirPath == NULL) return NULL;
    char list[1024] = {0};
    char DirPath[1024] = {0};
    sprintf(DirPath,"%s/%s",fs->dirPath,DirName);
    DIR *dir = opendir(DirPath);
    if(dir == NULL)
    {
        return NULL;
    }
    struct dirent*  entry;
    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0)
            continue;
        
        char * size = GetFileSize(DirPath,entry->d_name);
        strcat(list,entry->d_name);
        strcat(list,";");
        strcat(list,size);
        strcat(list,",");
        free(size);
    }
    if(strlen(list) == 0)
    {
        closedir(dir);
        return NULL;
    }
    
    if (strlen(list) > 0 && list[strlen(list) - 1] == ',') {
        list[strlen(list) - 1] = '\0';
    }
    
    closedir(dir);
    return strdup(list);
}
