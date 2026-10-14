#pragma once

#include "../ECS/World.h"

class AttributeSystem
{
public:

    void Update(
        World& world,
        Entity player)
    {
        if (!world.HasComponent<PlayerStats>(player))
            return;

        PlayerStats& stats =
            world.GetComponent<PlayerStats>(player);

        while (true)
        {
            system("clear");

            std::cout
                << "================ 属性加点 ================\n\n";

            std::cout
                << "剩余属性点："
                << stats.attrPoint
                << "\n\n";

            std::cout
                << "1、攻击力\n"
                << "2、防御力\n"
                << "3、生命值\n"
                << "4、退出\n\n";

            int choice;

            std::cout
                << "请选择：";

            std::cin >> choice;

            if (choice == 4)
                return;

            if (choice < 1 || choice > 3)
                continue;

            if (stats.attrPoint <= 0)
            {
                std::cout
                    << "没有可用属性点！\n";

                sleep(1);

                continue;
            }

            std::cout
                << "请输入增加数量：";

            int number;

            std::cin >> number;

            if (number <= 0 ||
                number > stats.attrPoint)
            {
                std::cout
                    << "属性点数量不合法！\n";

                sleep(1);

                continue;
            }

            switch (choice)
            {
            case 1:
            {
                CombatStats& combat =
                    world.GetComponent<CombatStats>(
                        player
                    );

                combat.attack += number;

                break;
            }

            case 2:
            {
                CombatStats& combat =
                    world.GetComponent<CombatStats>(
                        player
                    );

                combat.defend += number;

                break;
            }

            case 3:
            {
                Health& health =
                    world.GetComponent<Health>(
                        player
                    );

                health.hp += number;

                break;
            }
            }

            stats.attrPoint -= number;

            std::cout
                << "加点成功！\n";

            sleep(1);
        }
    }
};