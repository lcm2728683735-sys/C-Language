#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Factory.h"
#include "../Game/Prop.h"



class ShopSystem
{
public:

    void Update(
        World& world,
        Entity player)
    {
        // 玩家无效
        if (player == INVALID_ENTITY)
            return;

        // 玩家没有位置
        if (!world.HasComponent<Position>(player))
            return;

        Position& playerPosition =
            world.GetComponent<Position>(player);


        // 找商店
        world.Each<
            Position,
            Symbol,
            ShopData
        >(
            [&](Entity shop,
                Position& shopPosition,
                Symbol& symbol,
                ShopData& shopData)
            {
                // 玩家没有站在商店上
                if (playerPosition.x != shopPosition.x ||
                    playerPosition.y != shopPosition.y)
                {
                    return;
                }


                OpenShop(
                    world,
                    player,
                    shopData
                );
            }
        );
    }


private:

    void OpenShop(
        World& world,
        Entity player,
        ShopData& shopData)
    {
        Inventory& inventory =
            world.GetComponent<Inventory>(player);

        PlayerStats& stats =
            world.GetComponent<PlayerStats>(player);


        while (true)
        {
            system("clear");


            std::cout
                << "================== 欢迎来到商店 ==================\n\n";


            // ==============================
            // 显示商品
            // ==============================

            for (size_t i = 0;
                 i < shopData.props.size();
                 i++)
            {
                std::cout
                    << i + 1
                    << "、";

                shopData.props[i]->show();
            }


            // ==============================
            // 退出
            // ==============================

            std::cout
                << shopData.props.size() + 1
                << "、退出\n";


            std::cout
                << "\n当前金币:"
                << stats.golden
                << "\n";


            std::cout
                << "==================================================\n";


            int choice;


            std::cout
                << "请输入你要购买的编号：";


            if (!(std::cin >> choice))
            {
                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout
                    << "输入无效！\n";

                sleep(1);

                continue;
            }


            // ==============================
            // 退出商店
            // ==============================

            if (choice ==
                static_cast<int>(shopData.props.size()) + 1)
            {
                std::cout
                    << "欢迎再次光临！\n";

                sleep(1);

                return;
            }


            // ==============================
            // 判断编号
            // ==============================

            if (choice < 1 ||
                choice > static_cast<int>(shopData.props.size()))
            {
                std::cout
                    << "输入非法，请重新选择！\n";

                sleep(1);

                continue;
            }


            // ==============================
            // 获取商品
            // ==============================

            PropPtr& prop =
                shopData.props[choice - 1];


            int price =
                prop->GetPrice();


            // ==============================
            // 判断金币
            // ==============================

            if (stats.golden < price)
            {
                std::cout
                    << "金币不足！\n";

                sleep(1);

                continue;
            }


            // ==============================
            // 扣除金币
            // ==============================

            stats.golden -= price;


            // ==============================
            // 加入背包
            // ==============================

            inventory.items.push_back(
                prop->clone()
            );


            std::cout
                << "恭喜购买了【"
                << prop->GetName()
                << "】！\n";


            std::cout
                << "剩余金币："
                << stats.golden
                << "\n";


            sleep(1);
        }
    }
};