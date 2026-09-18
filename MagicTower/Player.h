#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "VirObj.h"
class Player : public VirObj
{
public:
    Player(CStrRef);
    void Move();
    void SetMaxSize(int Max);
};


#endif