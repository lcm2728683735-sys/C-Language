#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Prop.h"

class ShopSystem
{
private:
    // 防止退出商店后下一帧立即重新进入
    bool inShop = false;

public:

    void Update(
        World& world,
        Entity player)
    {
        if (player == INVALID_ENTITY)
            return;

        if (!world.HasComponent<Position>(player))
            return;

        Position& playerPosition =
            world.GetComponent<Position>(player);

        world.Each<Position, Symbol, ShopData>(
            [&](Entity shop,
                Position& shopPosition,
                Symbol& symbol,
                ShopData& shopData)
            {
                // 玩家没有站在商店上
                if (playerPosition.x != shopPosition.x ||
                    playerPosition.y != shopPosition.y)
                {
                    inShop = false;
                    return;
                }


                // 已经处理过这个商店
                if (inShop)
                    return;


                inShop = true;


                OpenShop(
                    world,
                    player,
                    shopData
                );


                // 退出商店
                inShop = false;
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


        Money& money =
            world.GetComponent<Money>(player);


        while (true)
        {
            system("clear");


            std::cout
                << "================== 欢迎来到商店 ==================\n\n";


            // ============================
            // 商品
            // ============================

            for (size_t i = 0;
                 i < shopData.props.size();
                 i++)
            {
                std::cout
                    << i + 1
                    << "、";

                shopData.props[i]->show();
            }


            // ============================
            // 退出
            // ============================

            std::cout
                << shopData.props.size() + 1
                << "、退出\n";


            std::cout
                << "\n当前金币："
                << money.golden
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


            // ============================
            // 退出
            // ============================

            if (choice ==
                static_cast<int>(shopData.props.size()) + 1)
            {
                std::cout
                    << "欢迎再次光临！\n";

                sleep(1);

                return;
            }


            // ============================
            // 判断编号
            // ============================

            if (choice < 1 ||
                choice > static_cast<int>(
                    shopData.props.size()))
            {
                std::cout
                    << "输入非法，请重新选择！\n";

                sleep(1);

                continue;
            }


            // ============================
            // 获取商品
            // ============================

            PropPtr& prop =
                shopData.props[choice - 1];


            int price =
                prop->GetPrice();


            // ============================
            // 金币不足
            // ============================

            if (money.golden < price)
            {
                std::cout
                    << "你的金币不足！\n";

                sleep(1);

                continue;
            }


            // ============================
            // 扣钱
            // ============================

            money.golden -= price;


            // ============================
            // 加入背包
            // ============================

            inventory.items.push_back(
                prop->clone()
            );


            std::cout
                << "恭喜购买了【"
                << prop->GetName()
                << "】！\n";


            std::cout
                << "剩余金币："
                << money.golden
                << "\n";


            sleep(1);
        }
    }
};