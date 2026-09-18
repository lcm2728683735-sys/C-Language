#include <stdio.h>
#include <stdbool.h>


bool CopyFileBuffered(const char* scrPath, const char* destPath)
{
    FILE *src = fopen(scrPath,"rb");

    if(src == NULL)
        return false;
    
    FILE* dest = fopen(destPath,"wb");

    if(dest == NULL)
    {
        fclose(src);
        return false;
    }

    char buffer[1024];

    size_t bytesRead;

    while((bytesRead = fread(buffer,1,sizeof(buffer),src)) > 0)
    {
        size_t bytesWritten = fwrite(buffer, 1, bytesRead,dest);

        if(bytesWritten != bytesRead)//写入不完整
        {
            fclose(src);
            fclose(dest);
            return false;
        }
    }
    if(ferror(src))  //过程中读取错误
    {
        fclose(src);
        fclose(dest);
        return false;
    }
    fclose(src);
    fclose(dest);
    return true;
}

void PrintCopyResult(const char* scrPath, const char* destPath)
{
    if(CopyFileBuffered(scrPath, destPath))
        printf("复制成功！\n");
    else
        printf("复制失败！\n");
}



int main ()
{
    PrintCopyResult("test.txt","copy.txt");
    return 0;
}