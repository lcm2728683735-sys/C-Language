#pragma once

#include "System.h"

#include "../ECS/World.h"
#include "../Game/Prop.h"

class EquipmentSystem
{
public:

    void Update(World& world, Entity player)
    {
        if (player == INVALID_ENTITY)
            return;

        if (!world.HasComponents<
                Inventory,
                Equipment,
                CombatStats>(player))
        {
            return;
        }

        Inventory& inventory =
            world.GetComponent<Inventory>(player);

        Equipment& equipment =
            world.GetComponent<Equipment>(player);

        CombatStats& stats =
            world.GetComponent<CombatStats>(player);

        ShowInventory(
            inventory,
            equipment,
            stats
        );
    }


private:

    void ShowInventory(
        Inventory& inventory,
        Equipment& equipment,
        CombatStats& stats)
    {
        while (true)
        {
            system("clear");

            std::cout
                << "======================= 背包 =======================\n\n";

            if (inventory.items.empty())
            {
                std::cout
                    << "背包为空。\n\n";

                std::cout
                    << "按任意数字返回：";

                int temp;
                std::cin >> temp;

                return;
            }


            for (size_t i = 0;
                 i < inventory.items.size();
                 ++i)
            {
                std::cout
                    << i + 1
                    << "、";

                inventory.items[i]->show();
            }


            std::cout
                << inventory.items.size() + 1
                << "、退出\n";


            std::cout
                << "\n当前攻击力："
                << stats.attack
                << "\n";


            if (equipment.weapon)
            {
                std::cout
                    << "当前武器："
                    << equipment.weapon->GetName()
                    << "\n";
            }
            else
            {
                std::cout
                    << "当前武器：无\n";
            }


            std::cout
                << "\n请选择物品：";


            int choice;

            if (!(std::cin >> choice))
            {
                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<
                        std::streamsize
                    >::max(),
                    '\n'
                );

                continue;
            }


            // 退出
            if (choice ==
                static_cast<int>(
                    inventory.items.size()) + 1)
            {
                return;
            }


            if (choice < 1 ||
                choice >
                static_cast<int>(
                    inventory.items.size()))
            {
                continue;
            }


            PropPtr& prop =
                inventory.items[choice - 1];


            // 当前物品必须是 Weapon
            Weapon* weapon =
                dynamic_cast<Weapon*>(prop.get());


            if (weapon == nullptr)
            {
                continue;
            }


            // ==========================
            // 卸下旧武器
            // ==========================

            if (equipment.weapon)
            {
                Weapon* oldWeapon =
                    dynamic_cast<Weapon*>(
                        equipment.weapon.get()
                    );

                if (oldWeapon)
                {
                    stats.attack -=
                        oldWeapon->GetAttack();
                }
            }


            // ==========================
            // 装备新武器
            // ==========================

            equipment.weapon =
                prop->clone();


            stats.attack +=
                weapon->GetAttack();


            std::cout
                << "装备【"
                << weapon->GetName()
                << "】成功！\n";


            std::cout
                << "当前攻击力："
                << stats.attack
                << "\n";


            sleep(1);
        }
    }
};