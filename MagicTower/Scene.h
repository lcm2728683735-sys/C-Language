#ifndef __SCENE_H__
#define __SCENE_H__
#include "Global.h" 
#include "Player.h"

class Scene
{
public: 
    Scene(int width,int height,Player& p);
    void show();
private:
    std::vector<std::vector<std::string>> Map;
    Player &player;
    int width;
    int height;
};

#endif