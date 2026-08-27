#include <iostream>

using namespace std;

class Animal
{
public:
    int age = 10;

    virtual void speak()
    {
        cout << "Animal speak" << endl;
    }

    virtual void eat()
    {
        cout << "Animal eat" << endl;
    }
};

class Dog : public Animal
{
public:
    int weight = 20;

    void speak() override
    {
        cout << "Dog speak" << endl;
    }
};

int main()
{
    Animal animal;
    Dog dog;

    cout << "Animal sizeof: "
         << sizeof(Animal)
         << endl;

    cout << "Dog sizeof: "
         << sizeof(Dog)
         << endl;

    Animal* p = &dog;

    p->speak();

    p->eat();

    return 0;
}