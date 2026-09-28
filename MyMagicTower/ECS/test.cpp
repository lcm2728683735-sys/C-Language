#include "../Global.h"
#include "World.h"

int main()
{
    World world;

    Entity player = world.CreateEntity();
    Entity NPC = world.CreateEntity();
    std::cout << player <<std::endl;
    std::cout << NPC <<std::endl;

    world.AddComponent<Position>(player,{5,5});
    world.AddComponent<Health>(player,{100,100});

    auto & pos = world.GetComponent<Position>(player);
    auto & hel = world.GetComponent<Health>(player);

    world.DestroyEntity(player);

    Entity Monster = world.CreateEntity();

    std::cout << Monster <<std::endl;

    std::cout <<pos.x << std::endl;
    
    return 0;
}