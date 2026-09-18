#ifndef __VIROBJ_H__
#define __VIROBJ_H__

#include "Point.h"
class VirObj:public Point
{
    DEFINE_MEMEBER(Name,std::string);
    DEFINE_MEMEBER(Symbol,std::string);
    DEFINE_MEMEBER(HP,int);
    DEFINE_MEMEBER(Attack,int);
    DEFINE_MEMEBER(Defend,int);
};






#endif