#include "CollisionSystem.h"

void CollisionSystem::Update(World &world, Entity player)
{
    Position &playerPosition =
        world.GetComponent<Position>(player);

    world.Each<Position, Health, MonsterData>(
        [&](Entity monster,
            Position &monsterPosition,
            Health &health,
            MonsterData &monsterData)
        {
            // 怪物已经死亡，不检测
            if (health.hp <= 0)
                return;

            // 玩家和怪物坐标相同
            if (playerPosition.x == monsterPosition.x &&
                playerPosition.y == monsterPosition.y)
            {
                std::cout
                    << "遇到了怪物："
                    << monsterData.name
                    << std::endl;
            }
        });
}

Entity CollisionSystem::CheckMonsterCollision(World &world, Entity player)
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