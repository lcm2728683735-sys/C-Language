#include <sqlite3.h>
#include <stdio.h>


int main ()
{
    sqlite3 * db;
    //打开数据库
    int ret = sqlite3_open("./1.db",&db);
    if(ret != SQLITE_OK)
    {
        printf("open db error : %s\n",sqlite3_errmsg(db));
        return -1;
    }
    printf("打开数据库成功!\n");

    // char sql[] ="insert into student values(11,'王五','女',100);";
    // ret = sqlite3_exec(db,sql,NULL,NULL,NULL);
    // if(ret != SQLITE_OK)
    // {
    //     printf("EXEC db error : %s\n",sqlite3_errmsg(db));
    // }
    
    char sql[] = "select * from student;";
    char** result;
    int row =0;
    int column =0;
    ret = sqlite3_get_table(db,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("get table error : %s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    for(int i = 1; i <= row; i++)
    {
        for(int j = 0;j < column;j++)
        {
            printf("%s ",result[i * column + j]);
        }
        printf("\n");
    }

    sqlite3_free_table(result);
    //关闭数据库
    sqlite3_close(db);
    return 0;
}