#ifndef __SHOP_H__
#define __SHOP_H__

#include "Prop.h"
#include "Player.h"
class Shop:public SceneObj
{
public:
    Shop(Player &p);
    void show();
private:
    std::vector<PropPtr> PropVec;
    Player &p;
};

#endif