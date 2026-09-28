#include "Global.h"
#include "ECS/Component.h"
#include "ECS/World.h"
#include "ECS/Entity.h"
#include "System/MovementSystem.h"

int main()
{
    World world;

    Entity player = world.CreateEntity();

    world.AddComponent<Position>(
        player,
        {5, 5}
    );

    world.AddComponent<Velocity>(
        player,
        {1, 0}
    );

    MovementSystem movementSystem;

    movementSystem.Update(world, player);

    auto& position =
        world.GetComponent<Position>(player);

    std::cout << position.x << " "
              << position.y << '\n';
}