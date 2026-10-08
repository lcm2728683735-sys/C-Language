#include <iostream>

class Car
{
public:
    void SetEngine(const std::string & engine)
    {
        this->engine = engine;
    }
    void SetWheel(const std::string &wheel)
    {
        this->wheel = wheel;
    }
    void SetBody(const std::string &body)
    {
        this->body = body;
    }
    void show()
    {
        std::cout<<engine<<" "<< wheel << body << std::endl;
    }
private:
    std::string engine;
    std::string wheel;
    std::string body;
};

//抽象建造者

class Assemble
{
public:
    Assemble()
    {
        c = new Car;
    }
    virtual void AssembleEngine() = 0;
    virtual void AssembleWheel() = 0;
    virtual void AssembleBody() = 0;
    Car * GetCar()
    {
        AssembleEngine();
        AssembleWheel();
        AssembleBody();
        return c;
    }
protected:
    Car *c;
};


class AssembleA : public Assemble
{
    void AssembleEngine()
    {
        c->SetEngine("A引擎");
    }
    void AssembleWheel()
    {
        c->SetWheel("A轮胎");
    }
    void AssembleBody()
    {
        c->SetBody("A车身");
    }
};

class AssembleB : public Assemble
{
    void AssembleEngine()
    {
        c->SetEngine("B引擎");
    }
    void AssembleWheel()
    {
        c->SetWheel("B轮胎");
    }
    void AssembleBody()
    {
        c->SetBody("B车身");
    }
};

int main ()
{
    Assemble * a= new AssembleA;
    a->GetCar()->show();
    return 0;
}