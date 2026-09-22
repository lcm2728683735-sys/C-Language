#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "VirObj.h"
class Monster:public VirObj 
{
public:
    Monster(const Point& p);
};


class Slime:public Monster
{
public:
    Slime(const Point& p);
};
#endif