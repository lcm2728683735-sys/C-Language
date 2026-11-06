#ifndef __STDMYSQL_H__
#define __STDMYSQL_H__

#include <string>
#include <vector>
#include <memory>
using CStrRef = const std::string&;
using StrArray = std::vector<std::string>;
using StrMatrix = std::vector<StrArray>;
struct StdMysqlPrivate;
class StdMysql
{
public:
    StdMysql();
    ~StdMysql();

    bool Connect(CStrRef ip,CStrRef user,CStrRef passwd,CStrRef db,unsigned int port =3306);
    bool Exec(CStrRef sql);

    StrMatrix GetTableInfo(CStrRef sql);
    std::string GetFirstValue(CStrRef sql);
    bool IsConnected();

    //执行事务
    bool ExecTransaction(const StrArray &SqlList);
private:
    StdMysqlPrivate *p;
};

using MysqlPtr = std::shared_ptr<StdMysql>;


//mysql连接池
class StdMysqlPool
{
public:
    static StdMysqlPool * getInstance();
    StdMysqlPool(int MysqlCount = 10);
    ~StdMysqlPool();
    void SetParams(CStrRef ip,CStrRef user,CStrRef passwd,CStrRef db,unsigned int port =3306);
    MysqlPtr GetMysqlPtr();
    void ReleaseMysqlPtr(MysqlPtr ptr);
private:
    struct StdMysqlPoolPrivate;
    StdMysqlPoolPrivate *p;
};

#define MYSQLPOOL StdMysqlPool::getInstance()

#endif
