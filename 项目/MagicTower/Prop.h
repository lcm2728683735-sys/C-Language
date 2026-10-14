#ifndef __PROP_H__
#define __PROP_H__

#include "Global.h"

class Prop;
using PropPtr = std::shared_ptr<Prop>;
class Prop
{
public:
    Prop(CStrRef Name,int Price):Name(Name),Price(Price){}
    DEFINE_MEMEBER(Name,std::string);
    DEFINE_MEMEBER(Price,int);
    virtual void show(){}
    virtual PropPtr clone() = 0;
};



class Weapon:public Prop
{
public:
    Weapon(CStrRef Name, int Price,int attack):Prop(Name,Price),Attack(attack){}
    //可以增加的攻击力
    DEFINE_MEMEBER(Attack,int);
    void show() override;
    PropPtr clone() override;
};

using WeaponPtr = std::shared_ptr<Weapon>;

#endif