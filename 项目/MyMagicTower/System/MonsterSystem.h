#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Factory.h"

class MonsterSystem : public ISystem
{
public:

    Entity CreateSlime(World& world, Position position);
};