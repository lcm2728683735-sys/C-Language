#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Factory.h"

struct ShopData
{
    Entity CreateShop(World& world, Position position);
};

