#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Factory.h"


class MovementSystem : public ISystem
{
public:
    MovementSystem(int width, int height):width(width), height(height){}

    void Update(World& world) override;
    
private:
    int width;
    int height;
};
