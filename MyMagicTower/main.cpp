#include "Global.h"

#include "ECS/World.h"

#include "System/RenderSystem.h"
#include "System/MovementSystem.h"
#include "System/CollisionSystem.h"
#include "System/CombatSystem.h"
#include "System/ShopSystem.h"


int main()
{
    World world;


    // =========================================
    // 创建玩家
    // =========================================

    Entity player =
        world.CreateEntity();


    world.AddComponent<Position>(
        player,
        Position{0, 0}
    );


    world.AddComponent<Symbol>(
        player,
        Symbol{"🤣"}
    );


    world.AddComponent<Health>(
        player,
        Health{100}
    );


    world.AddComponent<PlayerStats>(
        player,
        PlayerStats{}
    );


    world.AddComponent<Inventory>(
        player,
        Inventory{}
    );


    // =========================================
    // 创建商店
    // =========================================

    Entity shop =
        world.CreateEntity();


    world.AddComponent<Position>(
        shop,
        Position{
            WIDTH / 2,
            HEIGHT / 2
        }
    );


    world.AddComponent<Symbol>(
        shop,
        Symbol{"🛒"}
    );


    world.AddComponent<ShopData>(
        shop,
        ShopData{}
    );


    // =========================================
    // 创建系统
    // =========================================

    RenderSystem renderSystem(WIDTH,HEIGHT);

    MovementSystem movementSystem(WIDTH, HEIGHT);

    CollisionSystem collisionSystem;

    CombatSystem combatSystem;

    ShopSystem shopSystem;


    // =========================================
    // 游戏循环
    // =========================================

    while (true)
    {
        system("clear");


        // 地图
        renderSystem.Update(world);


        // 玩家移动
        movementSystem.Update(
            world
        );

        // 商店
        shopSystem.Update(
            world,
            player
        );


        // 战斗
        Entity monster =
            collisionSystem.CheckMonsterCollision(
                world,
                player
            );


        if (monster != INVALID_ENTITY)
        {
            combatSystem.Battle(
                world,
                player,
                monster
            );
        }
    }


    return 0;
}