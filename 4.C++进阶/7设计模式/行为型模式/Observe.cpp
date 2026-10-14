#include <iostream>
#include <set>
class ObserverBase
{
public:
    ObserverBase(const std::string& name):name(name){}
    virtual void GetMsg(const std::string& words) = 0;
protected:
    std::string name;
};


class TargetBase // 被观察者基类
{
public:
    virtual void Update(const std::string & words) = 0;
    void AddObserver(ObserverBase *b)  //添加观察者
    {
        observers.insert(b);  
    }
    void RemoveObserve(ObserverBase *b)
    {
        observers.erase(b);
    }
protected:
    std::set<ObserverBase*> observers;
};


class Target:public TargetBase
{
public:
    void Update(const std::string &words)
    {
        for(auto ob : observers)
        {
            ob->GetMsg(words);
        }
    }
};

class Observer : public ObserverBase
{
public:
    using ObserverBase::ObserverBase;
    void GetMsg(const std::string &words)
    {
        std::cout << name <<"收到信息:" << words << std::endl;
    }
};

int main()
{
    ObserverBase *b = new Observer("张三");
    ObserverBase *b2 = new Observer("李四");

    TargetBase *t = new Target;
    t->AddObserver(b);
    t->AddObserver(b2);

    t->Update("今晚交作业");
    t->RemoveObserve(b);
    t->Update("没交作业的补作业");
    return 0;
}