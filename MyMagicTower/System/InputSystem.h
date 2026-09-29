#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"

class InputSystem
{
public:
    void Update(World& world, Entity player);

};
