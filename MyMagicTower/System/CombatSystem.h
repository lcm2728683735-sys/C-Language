#ifndef COMBAT_SYSTEM_H
#define COMBAT_SYSTEM_H

#include "../ECS/World.h"
#include <iostream>
#include <algorithm>
#include <unistd.h>


class CombatSystem
{
public:

    void Battle(World& world,Entity player,Entity monster)
    {
        // 获取玩家组件

        auto& playerHealth =
            world.GetComponent<Health>(player);

        auto& playerCombat =
            world.GetComponent<CombatStats>(player);

        auto& playerStats =
            world.GetComponent<PlayerStats>(player);

        auto& playerMoney =
            world.GetComponent<Money>(player);

        auto& playerIdentity =
            world.GetComponent<Identity>(player);

        // 获取怪物组件


        auto& monsterHealth =
            world.GetComponent<Health>(monster);

        auto& monsterCombat =
            world.GetComponent<CombatStats>(monster);

        auto& monsterData =
            world.GetComponent<MonsterData>(monster);

        // =========================

        while (true)
        {
            // 显示战斗界面
            ShowBattleInterface(
                playerIdentity,
                playerHealth,
                playerCombat,
                monsterHealth,
                monsterCombat,
                monsterData
            );


            // =================================
            // 玩家攻击
            // =================================

            int playerDamage =
                std::max(
                    playerCombat.attack -
                    monsterCombat.defend,
                    0
                );

            monsterHealth.hp -= playerDamage;

            std::cout
                << playerIdentity.name
                << " 对 "
                << monsterData.name
                << " 造成了 |"
                << playerDamage
                << "| 点伤害\n";

            sleep(1);


            // =================================
            // 怪物死亡
            // =================================

            if (monsterHealth.hp <= 0)
            {
                monsterHealth.hp = 0;

                ShowBattleInterface(
                    playerIdentity,
                    playerHealth,
                    playerCombat,
                    monsterHealth,
                    monsterCombat,
                    monsterData
                );

                std::cout
                    << "你战胜了 |"
                    << monsterData.name
                    << "|!\n";

                std::cout
                    << "获得经验值 |"
                    << monsterData.exp
                    << "| 和金钱 |"
                    << monsterData.golden
                    << "|\n";

                sleep(1);


                // =========================
                // 获得经验
                // =========================

                playerStats.exp +=
                    monsterData.exp;


                // =========================
                // 升级
                // =========================

                LevelUp(
                    playerStats,
                    playerCombat,
                    playerHealth
                );


                // =========================
                // 获得金币
                // =========================

                playerMoney.golden +=
                    monsterData.golden;

                sleep(1);

                return;
            }


            // =================================
            // 怪物攻击
            // =================================

            int monsterDamage =
                std::max(
                    monsterCombat.attack -
                    playerCombat.defend,
                    0
                );

            playerHealth.hp -=
                monsterDamage;

            std::cout
                << monsterData.name
                << " 对 "
                << playerIdentity.name
                << " 造成了 |"
                << monsterDamage
                << "| 点伤害\n";


            // =================================
            // 玩家死亡
            // =================================

            if (playerHealth.hp <= 0)
            {
                playerHealth.hp = 0;

                std::cout
                    << "你输了！游戏结束！\n";

                sleep(1);

                exit(-1);
            }

            sleep(1);
        }
    }


private:

    // =====================================
    // 战斗界面
    // =====================================

    void ShowBattleInterface(
        Identity& playerIdentity,
        Health& playerHealth,
        CombatStats& playerCombat,
        Health& monsterHealth,
        CombatStats& monsterCombat,
        MonsterData& monsterData)
    {
        system("clear");

        std::cout
            << "玩家姓名:|"
            << playerIdentity.name
            << "|"
            << "   VS   ";

        std::cout
            << "怪兽姓名:|"
            << monsterData.name
            << "|"
            << std::endl;


        std::cout
            << "血量:|"
            << playerHealth.hp
            << "|"
            << "             ";

        std::cout
            << "血量:|"
            << monsterHealth.hp
            << "|"
            << std::endl;


        std::cout
            << "攻击力:|"
            << playerCombat.attack
            << "|"
            << "            ";

        std::cout
            << "攻击力:|"
            << monsterCombat.attack
            << "|"
            << std::endl;


        std::cout
            << "防御力:|"
            << playerCombat.defend
            << "|"
            << "             ";

        std::cout
            << "防御力:|"
            << monsterCombat.defend
            << "|"
            << std::endl;


        std::cout << std::endl;
    }


    // 升级

    void LevelUp(
        PlayerStats& playerStats,
        CombatStats& playerCombat,
        Health& playerHealth)
    {
        if (playerStats.exp >= 100)
        {
            playerStats.exp -= 100;

            playerStats.level++;

            playerStats.attrPoint += 5;

            std::cout
                << "恭喜升级！升到 |"
                << playerStats.level
                << "| 级！\n";
        }
    }
};

#endif