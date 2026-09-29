#ifndef FACTORY_H
#define FACTORY_H

#include "../ECS/World.h"


#include <string>


inline Entity CreatePlayer(
    World& world,
    const std::string& name,
    int maxWidth,
    int maxHeight)
{
    Entity player = world.CreateEntity();

    world.AddComponent<Position>(
        player,
        {0, 0}
    );

    world.AddComponent<Velocity>(
        player,
        {0, 0}
    );

    world.AddComponent<Identity>(
        player,
        {name}
    );

    world.AddComponent<Symbol>(
        player,
        {"🤣"}
    );

    world.AddComponent<Health>(
        player,
        {100}
    );

    world.AddComponent<CombatStats>(
        player,
        {
            10,
            1,
            0,
            0
        }
    );

    world.AddComponent<PlayerStats>(
        player,
        {
            1,
            0,
            0,
            maxWidth,
            maxHeight
        }
    );

    world.AddComponent<Money>(
        player,
        {0}
    );

    return player;
}


inline Entity CreateSlime(
    World& world,
    Position position)
{
    Entity slime = world.CreateEntity();

    world.AddComponent<Position>(
        slime,
        position
    );

    world.AddComponent<Health>(
        slime,
        {10}
    );

    world.AddComponent<CombatStats>(
        slime,
        {
            2,
            1,
            0,
            0
        }
    );

    world.AddComponent<MonsterData>(
        slime,
        {
            "史莱姆",
            100,
            100
        }
    );

    world.AddComponent<Symbol>(
        slime,
        {"🎃"}
    );

    return slime;
}


inline Entity CreateShop(
    World& world,
    Position position)
{
    Entity shop = world.CreateEntity();

    world.AddComponent<Position>(
        shop,
        position
    );

    world.AddComponent<Symbol>(
        shop,
        {"🛒"}
    );

    world.AddComponent<ShopData>(
        shop,
        {}
    );

    return shop;
}

#endif