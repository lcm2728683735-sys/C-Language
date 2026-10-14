#include <iostream>

struct request
{
    int money;
};

class Manager
{
public:
    Manager(const std::string & name):name(name){}
    void SetManager(Manager *m)
    {
        this->m = m;
    }
    virtual void GetRequest(request *r) = 0;
protected:
    std::string name;
    Manager *m;
};

class CommonManager:public Manager
{
public:
    using Manager::Manager;
    void GetRequest(request *r)
    {
        if(r->money <= 500)
        {
            std::cout << name <<"批准了" << r->money << "的涨薪请求"<< std::endl;
        }
        else
        {
            m->GetRequest(r);
        }
    }
};

class Major:public Manager
{
public:
    using Manager::Manager;
    void GetRequest(request *r)
    {
        if(r->money >= 500 && r->money <= 1000)
        {
            std::cout << name <<"批准了" << r->money << "的涨薪请求"<< std::endl;
        }
        else
        {
            m->GetRequest(r);
        }
    }
};

class GeneralManager:public Manager
{
public:
    using Manager::Manager;
    void GetRequest(request *r)
    {
        if(r->money > 1000)
        {
            std::cout << name <<"批准了" << r->money << "的涨薪请求"<< std::endl;
        }
    }
};


int main ()
{
    Manager *m1 = new CommonManager("张经理");
    Manager *m2 = new CommonManager("李总监");
    Manager *m3 = new CommonManager("王总");

    m1->SetManager(m2);
    m2->SetManager(m3);

    request *r = new request;
    r->money = 500;
    m1->GetRequest(r);
    return 0;
}