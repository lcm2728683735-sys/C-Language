#include "StdSqlite3.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

struct StdSqlite3
{
    sqlite3 *db;
};

SQL *StdSqlite3Init(const char *dbPath)
{
    SQL * s = (SQL*)malloc(sizeof(SQL));
    if(s ==NULL)
    {
        printf("StdSqlite3Init malloc error!\n");
        return NULL;
    }
    int ret = sqlite3_open(dbPath,&s->db);
    if(ret != SQLITE_OK)
    {
        printf("open db error : %s\n",sqlite3_errmsg(s->db));
        free(s);
        return NULL;
    }
    return s;
}

bool SQLExec(SQL *s, const char *sql)
{
    int ret = sqlite3_exec(s->db,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("EXEC db error : %s\n",sqlite3_errmsg(s->db));
        return false;
    }
    return false;
}

char **GetTableInfo(SQL *s, const char *sql, int *row, int *column)
{
    char* *result;
    row =0;
    column =0;
    int ret = sqlite3_get_table(s->db,sql,&result,row,column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("get table error : %s\n",sqlite3_errmsg(s->db));
        return NULL;
    }
    return result;
}

void FreeTableInfo(char **result)
{
    sqlite3_free_table(result);
}

int GetTableLen(SQL *s, const char *tableName)
{
    char sql[1024] = {0};
    sprintf(sql,"select cout(*) from %s;",tableName);
    char ** result = GetTableInfo(s,sql,NULL,NULL);
    if(result == NULL)
        return -1;
    int len = atoi(result[1]);
    sqlite3_free_table(result);

    return len;
}

void ClearSQL(SQL *s)
{
    sqlite3_close(s->db);
    free(s);
}
