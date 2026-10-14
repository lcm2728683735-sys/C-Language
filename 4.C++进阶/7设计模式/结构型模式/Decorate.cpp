#include <iostream>
#include <string>

class Car //被装饰的基类
{
public: 
    Car() = default;
    Car(const std::string & name): name(name){}
    virtual void showInfo() = 0;
protected:
    std::string name;
};

class BMW:public Car  //被装饰的具体类
{
public:
    using Car::Car;
    void showInfo()
    {
        std::cout<<name<<std::endl;
    }
};

class Decorate:public Car //抽象装饰类
{
public:
    using Car::Car;
    void decorate(Car *c)
    {
        this->c = c;
    }
protected:
    Car *c;
};

class SelfDrive : public Decorate
{
public:
    void showInfo()
    {
        std::cout << "自动驾驶";
        c->showInfo();
    }
};

class Navigator : public Decorate
{
public:
    void showInfo()
    {
        std::cout << "导航";
        c->showInfo();
    }
};

class VoiceControl : public Decorate
{
public:
    void showInfo()
    {
        std::cout << "语音识别";
        c->showInfo();
    }
};

int main()
{
    Car *c = new BMW("宝马");
    c->showInfo();

    Decorate *d1 = new SelfDrive;
    Decorate *d2 = new VoiceControl;
    Decorate *d3 = new Navigator;
    d1->decorate(c);
    d1->showInfo();
    c->showInfo();
    return 0;
}