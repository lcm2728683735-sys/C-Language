#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include <stdbool.h>

struct FileSystem;
typedef struct FileSystem FileSys;
FileSys* FileSystemInit(const char * DirPath);
//在根目录下创建新的文件夹
bool CreateNewDirInfs(FileSys * fs,const char * DirName);
//在根目录下删除文件夹
bool DeleteDirInFs(FileSys * fs,const char *DirName);
//在根目录下是否存在一个 DirName文件夹
bool isDirExist(FileSys *fs,const char * DirName);

#endif