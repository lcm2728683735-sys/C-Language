#pragma once

#include "../Global.h"
#include "../ECS/World.h"

class MovementSystem
{
public:
    void Update(World& world,Entity entity);
    // void Move(Velocity & velocity);
    // void up(Velocity & velocity);
    // void down(Velocity & velocity);
    // void left(Velocity & velocity);
    // void right(Velocity & velocity);
};

