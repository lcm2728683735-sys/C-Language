#ifndef COMBAT_SYSTEM_H
#define COMBAT_SYSTEM_H

#include "../ECS/World.h"



class CombatSystem
{
public:

    void Battle(
        World& world,
        Entity player,
        Entity monster)
    {
        // =========================================
        // 检查 Entity
        // =========================================

        if (player == INVALID_ENTITY ||
            monster == INVALID_ENTITY)
        {
            return;
        }


        // =========================================
        // 获取玩家组件
        // =========================================

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


        // =========================================
        // 获取怪物组件
        // =========================================

        auto& monsterHealth =
            world.GetComponent<Health>(monster);

        auto& monsterCombat =
            world.GetComponent<CombatStats>(monster);

        auto& monsterData =
            world.GetComponent<MonsterData>(monster);


        // =========================================
        // 战斗循环
        // =========================================

        while (true)
        {
            // =====================================
            // 显示战斗界面
            // =====================================

            ShowBattleInterface(
                playerIdentity,
                playerHealth,
                playerCombat,
                monsterHealth,
                monsterCombat,
                monsterData
            );


            // =====================================
            // 玩家攻击
            // =====================================

            int playerDamage =
                std::max(
                    playerCombat.attack -
                    monsterCombat.defend,
                    0
                );


            monsterHealth.hp -=
                playerDamage;


            std::cout
                << playerIdentity.name
                << " 对 "
                << monsterData.name
                << " 造成了 |"
                << playerDamage
                << "| 点伤害\n";


            sleep(1);


            // =====================================
            // 怪物死亡
            // =====================================

            if (monsterHealth.hp <= 0)
            {
                monsterHealth.hp = 0;


                // 显示死亡后的战斗界面
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
                    << "|！\n";


                std::cout
                    << "获得经验值 |"
                    << monsterData.exp
                    << "| 和金钱 |"
                    << monsterData.golden
                    << "|\n";


                sleep(1);


                // =================================
                // 获得经验
                // =================================

                playerStats.exp +=
                    monsterData.exp;


                // =================================
                // 检查升级
                // =================================

                LevelUp(
                    playerStats
                );


                // =================================
                // 获得金币
                // =================================

                playerMoney.golden +=
                    monsterData.golden;


                std::cout
                    << "当前金币："
                    << playerMoney.golden
                    << "\n";


                sleep(1);


                // 战斗结束
                return;
            }


            // =====================================
            // 怪物攻击
            // =====================================

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


            sleep(1);


            // =====================================
            // 玩家死亡
            // =====================================

            if (playerHealth.hp <= 0)
            {
                playerHealth.hp = 0;


                ShowBattleInterface(
                    playerIdentity,
                    playerHealth,
                    playerCombat,
                    monsterHealth,
                    monsterCombat,
                    monsterData
                );


                std::cout
                    << "\n你输了！游戏结束！\n";


                sleep(1);


                exit(0);
            }
        }
    }


private:

    // =================================================
    // 战斗界面
    // =================================================

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
            << "====================== 战斗 ======================\n\n";


        // =========================================
        // 名字
        // =========================================

        std::cout
            << "玩家姓名：|"
            << playerIdentity.name
            << "|";


        std::cout
            << "       VS       ";


        std::cout
            << "怪兽姓名：|"
            << monsterData.name
            << "|"
            << std::endl;


        // =========================================
        // HP
        // =========================================

        std::cout
            << "血量：|"
            << playerHealth.hp
            << "|";


        std::cout
            << "             ";


        std::cout
            << "血量：|"
            << monsterHealth.hp
            << "|"
            << std::endl;


        // =========================================
        // Attack
        // =========================================

        std::cout
            << "攻击力：|"
            << playerCombat.attack
            << "|";


        std::cout
            << "             ";


        std::cout
            << "攻击力：|"
            << monsterCombat.attack
            << "|"
            << std::endl;


        // =========================================
        // Defense
        // =========================================

        std::cout
            << "防御力：|"
            << playerCombat.defend
            << "|";


        std::cout
            << "             ";


        std::cout
            << "防御力：|"
            << monsterCombat.defend
            << "|"
            << std::endl;


        std::cout
            << "\n==================================================\n";
    }


    // =================================================
    // 升级
    // =================================================

    void LevelUp(
        PlayerStats& playerStats)
    {
        // 使用 while
        // 防止一次获得大量经验无法连续升级

        while (playerStats.exp >= 100)
        {
            playerStats.exp -= 100;

            playerStats.level++;

            playerStats.attrPoint += 5;


            std::cout
                << "\n========================================\n";

            std::cout
                << "恭喜升级！\n";


            std::cout
                << "当前等级：|"
                << playerStats.level
                << "|\n";


            std::cout
                << "获得属性点：|5|\n";


            std::cout
                << "========================================\n";


            sleep(1);
        }
    }
};


#endif