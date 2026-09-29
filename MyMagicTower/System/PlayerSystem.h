#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Factory.h"

class PlayerSystem : public ISystem
{
public:
    void Update(World & world) override;
    void ShowPlayer(World & world ,Entity player);
    Entity CreatePlayer(World world,const std::string & name);
};