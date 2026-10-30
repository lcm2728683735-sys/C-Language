#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include <stdbool.h>
#include <stddef.h>

struct FileSystem;
typedef struct FileSystem FileSys;
FileSys* FileSystemInit(const char * DirPath);
//在根目录下创建新的文件夹
bool CreateNewDirInfs(FileSys * fs,const char * DirName);
//在根目录下删除文件夹
bool DeleteDirInFs(FileSys * fs,const char *DirName);
//在根目录下是否存在一个 DirName文件夹
bool isDirExist(FileSys *fs,const char * DirName);
//在根目录下的文件夹内写入文件数据
void WriteFileTofs(FileSys *fs, const char *DirName, const char *fileName, void *p, size_t size);
//查看文件夹下的文件列表
char * GetFileList(FileSys *fs,const char * DirName);

#endif