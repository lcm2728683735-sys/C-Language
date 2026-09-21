#ifndef __SCENE_H__
#define __SCENE_H__
#include "Global.h" 
#include "Player.h"
#include "Monster.h"
class Scene
{
public: 
    Scene(int width,int height,Player& p);
    void show();
    void IntialMonsters(); 
private:
    std::vector<std::vector<std::string>> Map;
    std::vector<Monster> Monsters;
    Player &player;
    int width;
    int height;
};

#endif