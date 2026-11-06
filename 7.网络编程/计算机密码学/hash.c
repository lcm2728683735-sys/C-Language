#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int hash(char * key)
{
    int count = 0;
    for(int i = 0; i <strlen(key) ; i++)
    {
        count = (count * 31 + key[i]) % 100;
    }
    return count;
}

int main()
{
    char salt[17] = "qwertyuiopasdfgh";
    char passwd[100] = {0};
    printf("请输入你的密码:");
    scanf("%s",passwd);

    strcat(passwd,salt);
    printf("原密码:%s\n",passwd);

    unsigned char hashPasswd[SHA256_DIGEST_LENGTH] = {0};
    SHA256(passwd,strlen(passwd),hashPasswd);

    for(int i = 0;i < SHA256_DIGEST_LENGTH;i++)
        printf("%x",hashPasswd[i]);
    printf("\n");
    return 0;
}