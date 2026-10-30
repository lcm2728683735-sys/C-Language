#include "FileSystem.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "FileSystem.h"

struct FileSystem
{
    char * dirPath;
};

FileSys *FileSystemInit(const char *DirPath)
{
    FileSys * fs = (FileSys*)malloc(sizeof(DirPath));
    if(fs == NULL)
    {
        printf("FileSystemInit malloc error!\n");
    }

    DIR *dir;
    if((dir = opendir(DirPath))==NULL)
    {
        if(mkdir(DirPath,0777)!= 0)
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
    char DirPath [1024] = {0};
    sprintf(DirPath,"%s/%s",fs->dirPath,DirName);
    if(mkdir(DirPath,0777) != 0)
    {
        perror("mkdir");
        return false;
    }
    return true;
}

bool DeleteDirInFs(FileSys *fs, const char *DirName)
{
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
    DIR *dir = opendir(fs->dirPath);
    if(dir == NULL)
    {
        perror("isDirExist opendir");
        return false;
    }
    struct dirent * entry;
    while((entry = readdir(dir))!= NULL)
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
        perror("fopen failed");
        return;
    }
    fwrite(p,size,1,f);
    fclose(f);
}

