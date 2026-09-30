#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "../ECS/World.h"

class CollisionSystem
{
public:
    Entity CheckMonsterCollision(
        World &world,
        Entity player)
    {
        Position &playerPosition =
            world.GetComponent<Position>(player);

        Entity result = INVALID_ENTITY;

        world.Each<Position, Health, MonsterData>(
            [&](Entity monster,
                Position &monsterPosition,
                Health &health,
                MonsterData &monsterData)
            {
                if (health.hp <= 0)
                    return;

                if (playerPosition.x == monsterPosition.x &&
                    playerPosition.y == monsterPosition.y)
                {
                    result = monster;
                }
            });
        return result;
    }
};

#endif