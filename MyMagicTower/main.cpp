#include "Global.h"

#include "ECS/World.h"
#include "Game/Factory.h"

#include "System/UserSystem.h"
#include "System/SaveSystem.h"
#include "System/RenderSystem.h"
#include "System/InputSystem.h"
#include "System/MovementSystem.h"
#include "System/CollisionSystem.h"
#include "System/CombatSystem.h"
#include "System/ShopSystem.h"
#include "System/AttributeSystem.h"
#include "System/EquipmentSystem.h"


// ============================================================
// 创建固定游戏世界
// ============================================================

void CreateGameWorld(World& world)
{
    // 商店
    CreateShop(
        world,
        {
            WIDTH / 2,
            HEIGHT / 2
        }
    );


    // 怪物
    CreateSlime(
        world,
        {3, 2}
    );

    CreateSlime(
        world,
        {5, 3}
    );

    CreateSlime(
        world,
        {7, 2}
    );

    CreateSlime(
        world,
        {10, 7}
    );

    CreateSlime(
        world,
        {13, 4}
    );
}


// ============================================================
// 继续游戏 / 新游戏
// ============================================================

bool AskLoadGame(
    SaveSystem& saveSystem,
    const std::string& username)
{
    if (!saveSystem.Exists(username))
    {
        return false;
    }


    while (true)
    {
        system("clear");

        std::cout
            << "========================================\n"
            << "              发现游戏存档\n"
            << "========================================\n\n";

        std::cout
            << "玩家："
            << username
            << "\n\n";

        std::cout
            << "1、继续游戏\n"
            << "2、新游戏\n"
            << "3、返回登录\n\n";

        std::cout
            << "请选择：";


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


        if (choice == 1)
        {
            return true;
        }


        if (choice == 2)
        {
            return false;
        }


        if (choice == 3)
        {
            // 这里退出整个程序。
            // 如果以后想做返回登录，
            // 再把 main 改成外层登录循环。
            exit(0);
        }
    }
}


// ============================================================
// Main
// ============================================================

int main()
{
    // ========================================================
    // 用户登录
    // ========================================================

    UserSystem userSystem;

    userSystem.RegisterLoginUI();


    const std::string username =
        userSystem.GetCurrentUser();


    if (username.empty())
    {
        return 0;
    }


    // ========================================================
    // World
    // ========================================================

    World world;


    // ========================================================
    // 创建玩家
    // ========================================================

    Entity player =
        CreatePlayer(
            world,
            username,
            WIDTH,
            HEIGHT
        );


    // ========================================================
    // SaveSystem
    // ========================================================

    SaveSystem saveSystem;


    bool loadGame =
        AskLoadGame(
            saveSystem,
            username
        );


    // ========================================================
    // 创建固定世界
    // ========================================================

    CreateGameWorld(world);


    // ========================================================
    // 加载玩家存档
    // ========================================================

    if (loadGame)
    {
        std::cout
            << "\n正在加载存档...\n";

        sleep(1);


        if (!saveSystem.Load(
                world,
                player,
                username))
        {
            std::cout
                << "存档加载失败，将开始新游戏。\n";

            sleep(1);
        }
    }


    // ========================================================
    // Systems
    // ========================================================

    RenderSystem renderSystem(
        WIDTH,
        HEIGHT
    );


    InputSystem inputSystem;


    MovementSystem movementSystem(
        WIDTH,
        HEIGHT
    );


    CollisionSystem collisionSystem;


    CombatSystem combatSystem;


    ShopSystem shopSystem;


    AttributeSystem attributeSystem;


    EquipmentSystem equipmentSystem;


    // ========================================================
    // 游戏循环
    // ========================================================

    while (true)
    {
        system("clear");


        // ====================================================
        // 渲染
        // ====================================================

        renderSystem.Update(world);


        // ====================================================
        // 输入
        // ====================================================

        inputSystem.Update(
            world,
            player
        );


        // ====================================================
        // 退出
        // ====================================================

        if (inputSystem.IsQuitRequested())
        {
            break;
        }


        // ====================================================
        // 属性
        // ====================================================

        if (inputSystem.IsAttributeRequested())
        {
            attributeSystem.Update(
                world,
                player
            );

            continue;
        }


        // ====================================================
        // 背包
        // ====================================================

        if (inputSystem.IsBagRequested())
        {
            equipmentSystem.Update(
                world,
                player
            );

            continue;
        }


        // ====================================================
        // 移动
        // ====================================================

        movementSystem.Update(
            world
        );


        // ====================================================
        // 商店
        // ====================================================

        shopSystem.Update(
            world,
            player
        );


        // ====================================================
        // 怪物碰撞
        // ====================================================

        Entity monster =
            collisionSystem.CheckMonsterCollision(
                world,
                player
            );


        // ====================================================
        // 战斗
        // ====================================================

        if (monster != INVALID_ENTITY)
        {
            combatSystem.Battle(
                world,
                player,
                monster
            );
        }
    }


    // ========================================================
    // 正常退出 → 保存
    // ========================================================

    std::cout
        << "\n正在保存游戏...\n";


    if (saveSystem.Save(
            world,
            player,
            username))
    {
        std::cout
            << "游戏保存成功！\n";
    }
    else
    {
        std::cout
            << "游戏保存失败！\n";
    }


    sleep(1);


    return 0;
}