#include <iostream>

class Animal
{
public: 
    virtual void speak() = 0;
    virtual void move() = 0;
};

class dog:public Animal
{
    void speak()
    {
        std::cout<<"汪汪";
    }
    void move()
    {
        std::cout<<"跑步";
    }
};

class bird:public Animal
{
    void speak()
    {
        std::cout<<"唧唧\n";
    }
    void move()
    {
        std::cout<<"飞翔\n";
    }
};

void makeAnimalSpeak(Animal* animal)
{
    animal->speak();
}

int main()
{
    Animal* dog1 = new dog;
    Animal* bird1 = new bird;
    makeAnimalSpeak(dog1);
    makeAnimalSpeak(bird1);
    return 0;
}