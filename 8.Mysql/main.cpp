#include <iostream>
#include "StdMysql.h"
#include <thread>

class SmartMysqlPtr
{
public:
    SmartMysqlPtr(MysqlPtr ptr)
    {
        srcPtr = ptr;
    }
    ~SmartMysqlPtr()
    {
        MYSQLPOOL->ReleaseMysqlPtr(srcPtr);
    }
    MysqlPtr &operator->()
    {
        return srcPtr;
    }

private:
    MysqlPtr srcPtr;
};


int main()
{

    MYSQLPOOL->SetParams("192.168.191.129","root","as158158","test");


    for(int i = 0;i<10;i++)
    {
        std::thread([]()
        {    
        auto ptr = MYSQLPOOL->GetMysqlPtr();
        if (!ptr)
        {
            std::cout << "指针为空\n";
            return;
        }
        SmartMysqlPtr sptr(ptr);
        auto result = ptr->GetTableInfo("SELECT * FROM student;");
        for (const auto& arr : result)
        {
            for (const auto& str : arr)
            {
                std::cout << str << " ";
            }
            std::cout << std::endl;
        }
        while(1);
        }).detach();
        while(1);
    }

    return 0;
}