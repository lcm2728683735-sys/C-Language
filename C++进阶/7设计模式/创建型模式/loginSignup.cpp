#include <iostream>
#include <map>
#include <memory>

class Request
{
public:
    virtual void run() = 0;
};

class Login:public Request
{
public :
    void run()
    {
        std::cout << "登录" << std::endl;
    }
};

class Signup:public Request
{
public :
    void run()
    {
        std::cout << "注册" << std::endl;
    }
};

using RequestPtr = std::shared_ptr<Request>;

class Factory
{
public:
    Factory()
    {
        m.insert({"Login",std::make_shared<Login>()});
        m.insert({"Signup",std::make_shared<Signup>()});
    }
    RequestPtr operator[](const std::string & str)
    {
        return m[str];
    }
private:
    std::map<std::string, RequestPtr> m;
};

int main()
{
    Factory f;
    f["Login"]->run();
    return 0;
}
