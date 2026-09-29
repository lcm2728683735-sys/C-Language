#include "Global.h"
#include "ECS/Component.h"
#include "ECS/World.h"
#include "ECS/Entity.h"
#include "System/MovementSystem.h"
#include "System/SystemManager.h"

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


    SystemManager systems;

    systems.AddSystem<MovementSystem>();

    systems.Update(world);


    auto& position =
        world.GetComponent<Position>(player);

    std::cout<< position.x << " "<< position.y <<std::endl;
}