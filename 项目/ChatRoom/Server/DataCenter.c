#include "DataCenter.h"
#include "StdSqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>
#define DBPath "./chatroom.db"

static SQL * s;

bool DataCenterInit()
{
    s = StdSqlite3Init(DBPath);
    if(s == NULL)
    {
        return false;
    }
    char sql[] = "create table if not exists user(name text primary key,passwd text not null,salt text not null);";
    return SQLExec(s,sql);
}

bool IsUserExist(const char *name)
{
    char sql[1024] = {0};
    sprintf(sql,"select count(*)from user where name = '%s';",name);
    char ** result = GetTableInfo(s,sql,NULL,NULL);
    if(result == NULL)
        return false;
    int count = atoi(result[1]);
    FreeTableInfo(result);
    return count!=0;
}

char * GenerateSalt()
{
    static bool seeded = false;
    if(!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }

    unsigned char rawsalt[8];
    for(int i = 0;i<8; i++)
        rawsalt[i] = rand() % 256;

    char *salthex = (char*)malloc(17);
    if(salthex == NULL)
        return NULL;
    
    for(int i = 0;i < 8; i++)
    {
        sprintf(salthex +( i * 2), "%02x",rawsalt[i]);
    }
    salthex[16] = '\0';
    return strdup(salthex);
}

char* HashPasswd(const char *passwd,const char * salt)
{
    int newLen = strlen(passwd) + strlen(salt) + 1;
    char *newPasswd = (char*)malloc(strlen(passwd)+strlen(salt)+1);
    if(newPasswd == NULL)
    {
        printf("AddNewUser malloc error!\n");
        return NULL;
    }
    memset(newPasswd,0,newLen);
    strcat(newPasswd,passwd);
    strcat(newPasswd,salt);

    unsigned char hashPasswd[SHA256_DIGEST_LENGTH] = {0};
    SHA256((const unsigned char*)newPasswd,strlen(newPasswd),hashPasswd);
    free(newPasswd);

    char *result = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    if (result == NULL) return NULL;
    
    //补零，固定哈希值长度
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(result + (i * 2), "%02x", hashPasswd[i]);
    }
    result[SHA256_DIGEST_LENGTH * 2] = '\0';
    
    return result;
}

bool AddNewUser(const char *name, const char *passwd)
{
    //生成随机盐值
    char *salt =GenerateSalt();
    char *result = HashPasswd(passwd,salt);
    char sql[1024] = {0};
    sprintf(sql,"insert into user values('%s','%s','%s');",name,result,salt);
    free(salt);
    free(result);
    return SQLExec(s,sql);
}

char* GetUserSalt(const char * name)
{
    char sql[1024] = {0};
    sprintf(sql, "select salt from user where name = '%s';", name);
    
    int r = 0, c = 0;
    char ** result = GetTableInfo(s, sql, &r, &c);
    if(result == NULL || r < 1) // 确保查到了数据
        return NULL;

    char *salt = strdup(result[1]);
    FreeTableInfo(result);
    return salt;
}

bool IsAccountEqual(const char *name, const char *passwd)
{
    char sql[1024] = {0};
    char* salt = GetUserSalt(name);
    if(salt ==NULL)
        return false;
    
    char * hashpasswd = HashPasswd(passwd,salt);
    sprintf(sql,"select count(*)from user where name = '%s' and passwd ='%s';",name,hashpasswd);
    free(hashpasswd);
    free(salt);

    char ** result = GetTableInfo(s,sql,NULL,NULL);
    if(result == NULL)
        return false;
    int count = atoi(result[1]);
    FreeTableInfo(result);
    return count!=0;
}
