#include "StdSqlite3.h"
#include <stdio.h>

int main()
{
    SQL * s =StdSqlite3Init("./1.db");
    printf("len : %d\n",GetTableLen(s,"student"));
    ClearSQL(s);
    return 0;
}