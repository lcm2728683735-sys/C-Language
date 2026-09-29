#include "PlayerSystem.h"



void PlayerSystem::Update(World &world)
{
    world.Each<PlayerStats>([](Entity entity, PlayerStats player)
    {
        if(player.exp >= 100)
        {
            player.exp -= 100;
            player.level++;
            player.attrpoint += 5;

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
    std:: cout<<"=========================================="<< std::endl;
    std::cout << "玩家姓名：|" << stats.name << "|" << std::endl;
    std::cout << "生命  ❤️：|" << health.hp<< "|" << std::endl;
    std::cout << "攻击力🔪:|" << combat.attack << "|" << std::endl;
    std::cout << "防御力🛡️:|" << combat.defend << "|" << std::endl;
    std::cout << "等级  🎖️:|" << stats.level << "|" << std::endl;
    std::cout << "经验值🔢:|" << stats.exp << "|" << std::endl;
    std::cout << "金币  🤑:|" << money.golden << "|" << std::endl;
    std:: cout<<"=========================================="<< std::endl;
}

