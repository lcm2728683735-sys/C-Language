#ifndef __STDSQLITE3_H__
#define __STDSQLITE3_H__

#include <stdbool.h>

struct StdSqlite3;
typedef struct StdSqlite3 SQL;

SQL * StdSqlite3Init(const char* dbPath);

bool SQLExec(SQL *s,const char * sql);
char** GetTableInfo(SQL * s,const char *sql,int *row,int * column);
void FreeTableInfo(char ** result);
int GetTableLen(SQL * s,const char *tableName);
void ClearSQL(SQL *s);

#endif