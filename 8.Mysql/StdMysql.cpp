#include "StdMysql.h"
#include <mysql/mysql.h>
#include <iostream>
#include <queue>
#include <mutex>

struct StdMysqlPrivate
{
    MYSQL mysql;
    bool IsConnected = false;
};

StdMysql::StdMysql() : p(new StdMysqlPrivate)
{
    mysql_init(&p->mysql);
}

StdMysql:: ~StdMysql()
{
    if(p->IsConnected)
        mysql_close(&p->mysql);
    delete p;
}

bool StdMysql::Connect(CStrRef ip,CStrRef user, CStrRef passwd, CStrRef db, unsigned int port)
{
    if(mysql_real_connect(&p->mysql,ip.c_str(),user.c_str(),passwd.c_str(),db.c_str(),port,nullptr,0))
    {
        p->IsConnected = true;
        return true;
    }
    return false;
}

bool StdMysql::Exec(CStrRef sql)
{
    if(mysql_real_query(&p->mysql,sql.c_str(),sql.size()) == 0)
    {
        return true;
    }
    std::cout<<mysql_error(&p->mysql);
    return false;
}

StrMatrix StdMysql::GetTableInfo(CStrRef sql)
{
    if(Exec(sql))
    {
        auto result = mysql_store_result(&p->mysql);
        if(!result)
        {
            return {};
        }

        StrMatrix matrix;
        int field_count = mysql_field_count(&p->mysql);
        MYSQL_ROW row;
        while(row = mysql_fetch_row(result))
        {
            StrArray arr;
            for(int i = 0;i < field_count; i++)
            {
                arr.push_back(row[i]);
            }
            matrix.push_back(std::move(arr));
        }
        mysql_free_result(result);
        return matrix;
    }
    return {};
}

std::string StdMysql::GetFirstValue(CStrRef sql)
{
    auto result = GetTableInfo(sql);
    if(!result.empty())
    {
        if(!result[0].empty())
        {
            return result[0][0];
        }
    }
    return {};
}

bool StdMysql::IsConnected()
{
    if(!p->IsConnected)
        return false;
    if(mysql_ping(&p->mysql)!= 0)
    {
        p->IsConnected = false;
        return false;
    }
    return true;
}

bool StdMysql::ExecTransaction(const StrArray &SqlList)
{
    //设置自动提交为 0 成功
    if(!p->IsConnected)
        return false;
    
        if(mysql_autocommit(&p->mysql,false)!= 0)
        {
            std::cout << " 设置自动提交失败:"<<mysql_error(&p->mysql)<<'\n';
        }
        return false;

    bool success = true;

    for(const auto& sql : SqlList)
    {
        if(!Exec(sql))
        {
            success = false;
            break;
        }
    }

    if(success)
    {
        if(mysql_commit(&p->mysql) != 0)
            success = false;
    }
    else
    {
        mysql_rollback(&p->mysql);
    }

    if(mysql_autocommit(&p->mysql,true)!= 0)
        success = false;
    
    return success;
}


struct StdMysqlPool::StdMysqlPoolPrivate
{
    std::queue<MysqlPtr> pool;
    int MysqlCount;
    std::mutex mutex;

    std::string host;
    std::string user;
    std::string passwd;
    std::string db;
    int port;
};

StdMysqlPool *StdMysqlPool::getInstance()
{
    static StdMysqlPool mysql;
    return &mysql;
}

StdMysqlPool::StdMysqlPool(int MysqlCount) : p(new StdMysqlPoolPrivate)
{
    p->MysqlCount = MysqlCount;
}

StdMysqlPool::~StdMysqlPool()
{
    while(!p->pool.empty())
    {
        p->pool.pop();
    }
    delete p;
}

void StdMysqlPool::SetParams(CStrRef host, CStrRef user, CStrRef passwd, CStrRef db, unsigned int port)
{
    for(int i = 0;i < p->MysqlCount;i++)
    {
        p->host = host;
        p->user = user;
        p->passwd = passwd;
        p->db = db;
        p->port = port;
        MysqlPtr ptr = std::make_shared<StdMysql>();
        if(!ptr->Connect(host,user,passwd,db,port))
        {
            return;
        }
        p->pool.push(ptr);
    }
}

//mysql连接使用的是 Tcp ，tcp受网络波动会自动断开，所以先检查是否是可用的状态
MysqlPtr StdMysqlPool::GetMysqlPtr()
{
    std::lock_guard<std::mutex> lock(p->mutex);
    while(!p->pool.empty())//队列里仍有连接
    {
        auto ptr = p->pool.front();
        p->pool.pop();
        if(ptr->IsConnected())  //当前连接可用
        {
            return ptr;
        }
    }
    //无可用连接，准备新的
    MysqlPtr ptr = std::make_shared<StdMysql>();
    if(!ptr->Connect(p->host,p->user,p->passwd,p->db,p->port))
    {
        return nullptr;
    }
    return ptr;
}

void StdMysqlPool::ReleaseMysqlPtr(MysqlPtr ptr)
{
    if(!ptr->IsConnected())
        return ;
    std::lock_guard<std::mutex> lock(p->mutex);
    p->pool.push(ptr);
}
