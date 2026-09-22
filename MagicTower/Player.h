#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "VirObj.h"
#include "Prop.h"
class Player : public VirObj
{
public:
    Player() = default;
    Player(CStrRef);
    void Move();
    void LevelUp();
    void AttrInterface(); 
    void Show();
    void ShowBag();
    int GetIntInput(const std::string& input);
    DEFINE_MEMEBER(MaxWidth,int);
    DEFINE_MEMEBER(MaxHeight,int);
    DEFINE_MEMEBER(Level,int);
    DEFINE_MEMEBER(AttrPoint,int);

    void InsertBag(const PropPtr & ptr); 
private:
    std::vector<PropPtr> bag;
    Weapon* w;//武器

};


#endif