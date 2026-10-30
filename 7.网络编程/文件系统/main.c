#include <stdio.h>
#include "FileSystem.h"

int main()
{
    FileSys * fs =FileSystemInit("./test");
    //文件夹不存在创建
    if(isDirExist(fs,"zhangsan") == false)
        CreateNewDirInfs(fs,"zhangsan");
    //文件夹存在删除
    if(isDirExist(fs,"zhangsan") == true)
        DeleteDirInFs(fs,"zhangsan");
    return 0;
}