#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"

class MovementSystem : public ISystem
{
    public:
    void Update(World& world) override;
};
