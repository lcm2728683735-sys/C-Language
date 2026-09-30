#pragma once

#include "../ECS/World.h"

class LevelSystem
{
public:

    void AddExp(
        World& world,
        Entity player,
        int exp)
    {
        if (!world.HasComponent<PlayerStats>(player))
            return;

        PlayerStats& stats =
            world.GetComponent<PlayerStats>(player);

        stats.exp += exp;

        CheckLevelUp(world, player);
    }


private:

    void CheckLevelUp(
        World& world,
        Entity player)
    {
        PlayerStats& stats =
            world.GetComponent<PlayerStats>(player);

        while (stats.exp >= 100)
        {
            stats.exp -= 100;

            stats.level++;

            stats.attrPoint += 5;

            std::cout
                << "恭喜升级！\n"
                << "当前等级："
                << stats.level
                << "\n"
                << "获得属性点：5\n";
        }
    }
};