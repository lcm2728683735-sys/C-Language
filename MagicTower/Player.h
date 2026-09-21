#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "VirObj.h"
class Player : public VirObj
{
public:
    Player(CStrRef);
    void Move();
    DEFINE_MEMEBER(MaxWidth,int);
    DEFINE_MEMEBER(MaxHeight,int);
};


#endif