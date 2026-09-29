#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"


class PlayerSystem : public ISystem
{
public:
    void Update(World & world) override;
    void ShowPlayer(World & world ,Entity player);
};