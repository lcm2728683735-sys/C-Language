#include <iostream>

class AbstractPlayer;
class Mediator //中介抽象类`    
{
public:
    virtual void SendMsg(const std::string & msg,AbstractPlayer *p) = 0;
};

class AbstractPlayer //抽象用户
{
public:
    AbstractPlayer(const std::string & name,Mediator *m):name(name),m(m){}
    virtual void SendMsg(const std::string & msg) = 0;
    virtual void GetMsg(const std::string & msg) = 0;
protected:
    Mediator *m;
    std::string name;
};

class SellPerson : public AbstractPlayer
{
public:
    using AbstractPlayer::AbstractPlayer;
    void SendMsg(const std::string & msg)
    {
        m->SendMsg(msg,this);
    }
    void GetMsg(const std::string & msg)
    {
        std::cout << "卖房子的人收到消息:" << msg <<std::endl;
    }
};

class BuyPerson:public AbstractPlayer
{
public:
    using AbstractPlayer::AbstractPlayer;
    void SendMsg(const std::string & msg)
    {
        m->SendMsg(msg,this);
    }
    void GetMsg(const std::string & msg)
    {
        std::cout << name << "收到消息:" << msg <<std::endl;
    }
};

class ConcreMediator : public Mediator
{
public:
    void SetPlayer(AbstractPlayer *p1,AbstractPlayer *p2)
    {
        this->p1 = p1;
        this->p2 = p2; 
    }
    void SendMsg(const std::string & msg,AbstractPlayer *p)
    {
        if(p == p1)
        {
            p2->GetMsg(msg);
        }
        else
        {
            p1->GetMsg(msg);
        }
    }
private:
    AbstractPlayer *p1;
    AbstractPlayer *p2;
};

int main  ()
{
    ConcreMediator * m = new ConcreMediator;
    AbstractPlayer *p1 = new SellPerson("卖房子1",m);
    AbstractPlayer *p2 = new SellPerson("卖房子2",m);

    AbstractPlayer *p3 = new BuyPerson("买房子1",m);
    AbstractPlayer *p4 = new BuyPerson("买房子2",m);

    m->SetPlayer(p1,p3);
    p1->SendMsg("你好,房子卖200万");

    return 0;
}