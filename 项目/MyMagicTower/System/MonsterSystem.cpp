#include "MonsterSystem.h"

Entity MonsterSystem::CreateSlime(World &world, Position position)
{
    Entity slime = world.CreateEntity();

    world.AddComponent<Position>(
        slime,
        position
    );

    world.AddComponent<Health>(
        slime,
        Health{10}
    );

    world.AddComponent<CombatStats>(
        slime,
        CombatStats{
            2,  // attack
            1,  // defend
            0,  // criticalHit
            0   // agile
        }
    );

    world.AddComponent<MonsterData>(
        slime,
        MonsterData{
            "史莱姆",
            100,
            100
        }
    );

    world.AddComponent<Symbol>(
        slime,
        Symbol{"🎃"}
    );

    return slime;
}