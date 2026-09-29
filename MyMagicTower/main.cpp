#include <iostream>
#include <cstdlib>
#include "ECS/World.h"
#include "Game/Factory.h"
#include "System/CollisionSystem.h"
#include "System/InputSystem.h"
#include "System/MovementSystem.h"
#include "System/RenderSystem.h"

#define WIDTH 16
#define HEIGHT 10

int main()
{
    World world;
    CollisionSystem collisionSystem;

    Entity player =
        CreatePlayer(
            world,
            "张三",
            WIDTH,
            HEIGHT);

    CreateShop(
        world,
        {WIDTH / 2,
         HEIGHT / 2});

    CreateSlime(world, {3, 2});
    CreateSlime(world, {5, 7});
    CreateSlime(world, {8, 3});
    CreateSlime(world, {12, 6});
    CreateSlime(world, {14, 1});

    InputSystem inputSystem;

    MovementSystem movementSystem(
        WIDTH,
        HEIGHT);

    RenderSystem renderSystem(
        WIDTH,
        HEIGHT);

    while (true)
    {
    renderSystem.Update(world);

    inputSystem.Update(world, player);

    movementSystem.Update(world);

    collisionSystem.Update(world, player);
    }

    return 0;
}