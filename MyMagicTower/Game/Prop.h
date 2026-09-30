#pragma once

#include "../Global.h"

#include <iostream>
#include <memory>
#include <string>



class Prop
{
public:

    virtual ~Prop() = default;
    virtual void show() = 0;
    virtual std::shared_ptr<Prop> clone() = 0;
    virtual std::string GetName() const = 0;
    virtual int GetPrice() const = 0;
};

class Weapon : public Prop
{
private:

    std::string name;

    int price;

    int attack;


public:

    Weapon(
        const std::string& name,
        int price,
        int attack)
        : name(name),
          price(price),
          attack(attack)
    {
    }


    void show() override
    {
        std::cout
            << "武器名:|"
            << name
            << "|价格:|"
            << price
            << "|攻击力+|"
            << attack
            << "|"
            << std::endl;
    }


    std::shared_ptr<Prop> clone() override
    {
        return std::make_shared<Weapon>(
            name,
            price,
            attack
        );
    }


    std::string GetName() const override
    {
        return name;
    }


    int GetPrice() const override
    {
        return price;
    }


    int GetAttack() const
    {
        return attack;
    }
};


using PropPtr = std::shared_ptr<Prop>;