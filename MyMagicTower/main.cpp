#include "Global.h"
#include "ECS/Component.h"



struct Health
{
    int hp;
    int maxHp;
};

struct PlayerStats
{
    int attack;
    int defense;
    int gold;
};


int main()
{
    ComponentManager manager;

    Entity player = 1;

    manager.AddComponent<Position>(player,{5, 10}); //等价于Position & AddComponent 

    manager.AddComponent<Health>(player,{100, 100}); 

    manager.AddComponent<PlayerStats>(player,{20, 10, 50});


    auto& position =manager.GetComponent<Position>(player);

    auto& health =manager.GetComponent<Health>(player);

    auto& stats =manager.GetComponent<PlayerStats>(player);


    std::cout << "Position: "
              << position.x << ", "
              << position.y << '\n';

    std::cout << "HP: "
              << health.hp << '\n';

    std::cout << "Attack: "
              << stats.attack << '\n';

    std::cout << "Gold: "
              << stats.gold << '\n';


    return 0;
}