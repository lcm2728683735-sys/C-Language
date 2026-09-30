#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "../ECS/World.h"

class CollisionSystem
{
public:
    void Update(World &world, Entity player);

    Entity CheckMonsterCollision(World &world,Entity player);
    
};

#endif