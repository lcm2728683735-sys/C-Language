#include <iostream>

class AbstractSystem
{
public:
    virtual void run () = 0;
};

class MySystem : public AbstractSystem
{
public:
    void run()
    {
        std::cout << "普通用户启动!\n";
    }
};

class AdminSystem : public AbstractSystem
{
public:
    void run()
    {
        std::cout << "管理员用户启动!\n";
    }
};

class Proxy
{
public:
    void Login(const std::string &name,const std::string & passwd)
    {
        if(name == "root" && passwd == "123456")
        {
            s = new AdminSystem;
            s->run();
        }
        else if(name == "ubuntu" && passwd == "123")
        {
            s = new MySystem;
            s->run();
        }
    }
private:
    AbstractSystem *s;
};

int main ()
{
    Proxy p;
    p.Login("root","123456");
    return 0;
}