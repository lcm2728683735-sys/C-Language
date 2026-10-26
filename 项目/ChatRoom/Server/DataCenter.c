#include "DataCenter.h"
#include "StdSqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#define DBPath "./chatroom.db"

static SQL * s;

bool DataCenterInit()
{
    s = StdSqlite3Init(DBPath);
    if(s == NULL)
    {
        return false;
    }
    char sql[] = "create table if not exists user(name text primary key,passwd text not null);";
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

bool AddNewUser(const char *name, const char *passwd)
{
    char sql[1024] = {0};
    sprintf(sql,"insert into user values('%s','%s');",name,passwd);
    return SQLExec(s,sql);
}
