#include "Global.h"

#include "ECS/World.h"

#include "Game/Factory.h"

#include "System/RenderSystem.h"
#include "System/InputSystem.h"
#include "System/MovementSystem.h"
#include "System/CollisionSystem.h"
#include "System/CombatSystem.h"
#include "System/ShopSystem.h"
#include "System/AttributeSystem.h"
#include "System/EquipmentSystem.h"

int main()
{

    World world;

    Entity player =
        CreatePlayer(
            world,
            "张三",
            WIDTH,
            HEIGHT);

    Entity shop =
        CreateShop(
            world,
            {WIDTH / 2,
             HEIGHT / 2});

    CreateSlime(
        world,
        {3, 2});

    CreateSlime(
        world,
        {5, 3});

    CreateSlime(
        world,
        {7, 2});

    CreateSlime(
        world,
        {10, 7});

    CreateSlime(
        world,
        {13, 4});

    RenderSystem renderSystem(
        WIDTH,
        HEIGHT);

    InputSystem inputSystem;

    MovementSystem movementSystem(
        WIDTH,
        HEIGHT);

    CollisionSystem collisionSystem;

    EquipmentSystem equipmentSystem;

    CombatSystem combatSystem;

    ShopSystem shopSystem;

    AttributeSystem attributeSystem;

    // =========================================
    // 游戏循环
    // =========================================

    while (true)
    {
        system("clear");

        // =============================
        // 地图
        // =============================

        renderSystem.Update(world);

        // =============================
        // 输入
        // =============================

        inputSystem.Update(
            world,
            player);

        // =============================
        // 属性
        // =============================

        if (inputSystem.IsAttributeRequested())
        {
            attributeSystem.Update(
                world,
                player);

            continue;
        }

        // =============================
        // 背包
        // =============================

        if (inputSystem.IsBagRequested())
        {
            equipmentSystem.Update(
                world,
                player
            );
            continue;
        }

        // =============================
        // 移动
        // =============================

        movementSystem.Update(
            world);

        // =============================
        // 商店
        // =============================

        shopSystem.Update(
            world,
            player);

        // =============================
        // 怪物碰撞
        // =============================

        Entity monster =
            collisionSystem.CheckMonsterCollision(
                world,
                player);

        // =============================
        // 战斗
        // =============================

        if (monster != INVALID_ENTITY)
        {
            combatSystem.Battle(
                world,
                player,
                monster);
        }
    }

    return 0;
}