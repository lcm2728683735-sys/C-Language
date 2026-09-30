#include "PlayerSystem.h"



void PlayerSystem::Update(World &world)
{
    world.Each<PlayerStats>([](Entity entity, PlayerStats player)
    {
        if(player.exp >= 100)
        {
            player.exp -= 100;
            player.level++;
            player.attrPoint += 5;

            std:: cout<<"=======================" << 
            "恭喜升级!升级到:" << player.level << "级!" 
            <<"==================="<< std::endl;
        }

    }
    );
}

void PlayerSystem::ShowPlayer(World &world, Entity player)
{
    auto & stats = world.GetComponent<PlayerStats>(player);
    auto & health = world.GetComponent<Health>(player);
    auto & combat = world.GetComponent<CombatStats>(player);
    auto & money = world.GetComponent<Money>(player);
    auto & id = world.GetComponent<Identity>(player);
    std:: cout<<"=========================================="<< std::endl;
    std::cout << "玩家姓名：|" << id.name << "|" << std::endl;
    std::cout << "生命  ❤️：|" << health.hp<< "|" << std::endl;
    std::cout << "攻击力🔪:|" << combat.attack << "|" << std::endl;
    std::cout << "防御力🛡️:|" << combat.defend << "|" << std::endl;
    std::cout << "等级  🎖️:|" << stats.level << "|" << std::endl;
    std::cout << "经验值🔢:|" << stats.exp << "|" << std::endl;
    std::cout << "金币  🤑:|" << money.golden << "|" << std::endl;
    std:: cout<<"=========================================="<< std::endl;
}

Entity PlayerSystem::CreatePlayer(World world, const std::string &name)
{
    Entity player = world.CreateEntity();

    world.AddComponent<Position>(
        player,
        Position{0, 0}
    );

    world.AddComponent<Velocity>(
        player,
        Velocity{0, 0}
    );

    world.AddComponent<Identity>(
        player,
        Identity{name}
    );

    world.AddComponent<Symbol>(
        player,
        Symbol{"🤣"}
    );

    world.AddComponent<Health>(
        player,
        Health{100}
    );

    world.AddComponent<CombatStats>(
        player,
        CombatStats{
            10,  // attack
            1,   // defend
            0,   // criticalHit
            0    // agile
        }
    );

    world.AddComponent<PlayerStats>(
        player,
        PlayerStats{
            1,      // level
            0,      // exp
            0,      // attrPoint
            16,     // maxWidth
            10      // maxHeight
        }
    );

    world.AddComponent<Money>(
        player,
        Money{0}
    );

    world.AddComponent<Inventory>(
    player,
    Inventory{}
);

    return player;
}