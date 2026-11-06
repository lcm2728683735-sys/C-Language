
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void Swap(char *s, int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// 生成随机密钥
void generateKey(char *key)
{
    for(int i = 0; i < 26; i++)
    {
        key[i] = 'a' + i;
    }

    srand((unsigned int)time(NULL));

    // Fisher-Yates 洗牌算法
    for(int i = 25; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Swap(key, i, j);
    }

    key[26] = '\0';

    printf("生成的key : %s\n", key);
}

// 加密
void Encrypt(char *msg, const char *key)
{
    for(int i = 0; msg[i] != '\0'; i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = key[msg[i] - 'a'];
        }
    }
}

void Decrypt(char *msg,char *key)
{
    for(int i = 0 ; i < strlen(msg); i++)
    {
        if(msg[i] <= 'z' && msg[i] >= 'a')
        {
            for(int j = 0;j < 26;j++)
            {
                if(msg[i] == key[j])
                {
                    msg[i] = 'a' + j; 
                    break;
                }
            }
        }
    }
}

int main(void)
{
    char key[27] = "zdqyrleoshvgbmfxakcuntiwpj";

    // generateKey(key);

    FILE *f = fopen("./1.txt", "rb");

    if(f == NULL)
    {
        perror("fopen");
        return 1;
    }

    // 获取文件大小
    if(fseek(f, 0, SEEK_END) != 0)
    {
        perror("fseek");
        fclose(f);
        return 1;
    }

    long fileSize = ftell(f);

    if(fileSize < 0)
    {
        perror("ftell");
        fclose(f);
        return 1;
    }

    rewind(f);

    // 分配文件大小 + 1 字节
    char *msg = malloc((size_t)fileSize + 1);

    if(msg == NULL)
    {
        perror("malloc");
        fclose(f);
        return 1;
    }

    // 读取整个文件
    size_t size = fread(msg, 1, (size_t)fileSize, f);

    if(size != (size_t)fileSize)
    {
        perror("fread");
        free(msg);
        fclose(f);
        return 1;
    }

    fclose(f);

    // 添加字符串结束符
    msg[size] = '\0';

    Encrypt(msg, key);

    printf("加密后：%s\n", msg);

    Decrypt(msg,key);
    printf("解密后: %s\n",msg);
    free(msg);

    return 0;
}
