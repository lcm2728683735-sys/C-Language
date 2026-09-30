#include "SaveSystem.h"

#include "../Game/Prop.h"

#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;


// ============================================================
// 获取存档路径
// ============================================================

string SaveSystem::GetSavePath(
    const string& username) const
{
    return "../Data/Save/" + username + ".save";
}


// ============================================================
// 判断存档是否存在
// ============================================================

bool SaveSystem::Exists(
    const string& username) const
{
    return filesystem::exists(
        GetSavePath(username)
    );
}


// ============================================================
// 保存
// ============================================================

bool SaveSystem::Save(
    World& world,
    Entity player,
    const string& username)
{
    // 如果 Save 文件夹不存在，就创建
    filesystem::create_directories(
        "../Data/Save"
    );

    string path =
        GetSavePath(username);


    ofstream file(path);

    if (!file.is_open())
    {
        cerr
            << "无法打开存档文件："
            << path
            << endl;

        return false;
    }


    // ========================================================
    // 存档版本
    // ========================================================

    file << "MAGICTOWER_SAVE_V1\n";


    // ========================================================
    // Position
    // ========================================================

    if (world.HasComponent<Position>(player))
    {
        Position& position =
            world.GetComponent<Position>(player);

        file
            << "POSITION "
            << position.x
            << " "
            << position.y
            << "\n";
    }


    // ========================================================
    // Health
    // ========================================================

    if (world.HasComponent<Health>(player))
    {
        Health& health =
            world.GetComponent<Health>(player);

        file
            << "HEALTH "
            << health.hp
            << "\n";
    }


    // ========================================================
    // CombatStats
    // ========================================================

    if (world.HasComponent<CombatStats>(player))
    {
        CombatStats& combat =
            world.GetComponent<CombatStats>(player);

        file
            << "COMBAT "
            << combat.attack
            << " "
            << combat.defend
            << "\n";
    }


    // ========================================================
    // PlayerStats
    // ========================================================

    if (world.HasComponent<PlayerStats>(player))
    {
        PlayerStats& stats =
            world.GetComponent<PlayerStats>(player);

        file
            << "STATS "
            << stats.level
            << " "
            << stats.exp
            << " "
            << stats.attrPoint
            << "\n";
    }


    // ========================================================
    // Money
    // ========================================================

    if (world.HasComponent<Money>(player))
    {
        Money& money =
            world.GetComponent<Money>(player);

        file
            << "MONEY "
            << money.golden
            << "\n";
    }


    // ========================================================
    // Equipment
    // ========================================================

    if (world.HasComponent<Equipment>(player))
    {
        Equipment& equipment =
            world.GetComponent<Equipment>(player);

        if (equipment.weapon)
        {
            Weapon* weapon =
                dynamic_cast<Weapon*>(
                    equipment.weapon.get()
                );

            if (weapon)
            {
                file
                    << "EQUIPMENT "
                    << weapon->GetName()
                    << " "
                    << weapon->GetPrice()
                    << " "
                    << weapon->GetAttack()
                    << "\n";
            }
        }
        else
        {
            file
                << "EQUIPMENT NONE\n";
        }
    }


    // ========================================================
    // Inventory
    // ========================================================

    if (world.HasComponent<Inventory>(player))
    {
        Inventory& inventory =
            world.GetComponent<Inventory>(player);

        file
            << "INVENTORY "
            << inventory.items.size()
            << "\n";


        for (auto& item : inventory.items)
        {
            Weapon* weapon =
                dynamic_cast<Weapon*>(
                    item.get()
                );

            if (weapon)
            {
                file
                    << "WEAPON "
                    << weapon->GetName()
                    << " "
                    << weapon->GetPrice()
                    << " "
                    << weapon->GetAttack()
                    << "\n";
            }
        }
    }


    file << "END\n";

    file.close();

    return true;
}


// ============================================================
// 加载
// ============================================================

bool SaveSystem::Load(
    World& world,
    Entity player,
    const string& username)
{
    string path =
        GetSavePath(username);


    ifstream file(path);

    if (!file.is_open())
    {
        cerr
            << "无法打开存档："
            << path
            << endl;

        return false;
    }


    string type;


    while (file >> type)
    {
        // ====================================================
        // Position
        // ====================================================

        if (type == "POSITION")
        {
            int x;
            int y;

            file >> x >> y;


            if (world.HasComponent<Position>(player))
            {
                Position& position =
                    world.GetComponent<Position>(player);

                position.x = x;
                position.y = y;
            }
        }


        // ====================================================
        // Health
        // ====================================================

        else if (type == "HEALTH")
        {
            int hp;

            file >> hp;


            if (world.HasComponent<Health>(player))
            {
                Health& health =
                    world.GetComponent<Health>(player);

                health.hp = hp;
            }
        }


        // ====================================================
        // Combat
        // ====================================================

        else if (type == "COMBAT")
        {
            int attack;
            int defend;

            file
                >> attack
                >> defend;


            if (world.HasComponent<CombatStats>(player))
            {
                CombatStats& combat =
                    world.GetComponent<CombatStats>(player);

                combat.attack = attack;
                combat.defend = defend;
            }
        }


        // ====================================================
        // PlayerStats
        // ====================================================

        else if (type == "STATS")
        {
            int level;
            int exp;
            int attrPoint;

            file
                >> level
                >> exp
                >> attrPoint;


            if (world.HasComponent<PlayerStats>(player))
            {
                PlayerStats& stats =
                    world.GetComponent<PlayerStats>(player);

                stats.level = level;
                stats.exp = exp;
                stats.attrPoint = attrPoint;
            }
        }


        // ====================================================
        // Money
        // ====================================================

        else if (type == "MONEY")
        {
            int golden;

            file >> golden;


            if (world.HasComponent<Money>(player))
            {
                Money& money =
                    world.GetComponent<Money>(player);

                money.golden = golden;
            }
        }


        // ====================================================
        // Equipment
        // ====================================================

        else if (type == "EQUIPMENT")
        {
            string name;

            file >> name;


            if (!world.HasComponent<Equipment>(player))
            {
                continue;
            }


            Equipment& equipment =
                world.GetComponent<Equipment>(player);


            if (name == "NONE")
            {
                equipment.weapon = nullptr;
                continue;
            }


            int price;
            int attack;

            file
                >> price
                >> attack;


            equipment.weapon =
                make_shared<Weapon>(
                    name,
                    price,
                    attack
                );
        }


        // ====================================================
        // Inventory
        // ====================================================

        else if (type == "INVENTORY")
        {
            int count;

            file >> count;


            if (!world.HasComponent<Inventory>(player))
            {
                continue;
            }


            Inventory& inventory =
                world.GetComponent<Inventory>(player);

            inventory.items.clear();


            for (int i = 0; i < count; ++i)
            {
                string itemType;

                file >> itemType;


                if (itemType == "WEAPON")
                {
                    string name;
                    int price;
                    int attack;

                    file
                        >> name
                        >> price
                        >> attack;


                    inventory.items.push_back(
                        make_shared<Weapon>(
                            name,
                            price,
                            attack
                        )
                    );
                }
            }
        }


        // ====================================================
        // END
        // ====================================================

        else if (type == "END")
        {
            break;
        }
    }


    file.close();

    return true;
}