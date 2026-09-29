#include "Global.h"
#include "ECS/Component.h"
#include "ECS/World.h"
#include "ECS/Entity.h"
#include "System/MovementSystem.h"
#include "System/SystemManager.h"

#include <iostream>
#include <unistd.h>

#include "ECS/World.h"

#include "Components/Position.h"
#include "Components/Velocity.h"

#include "Game/Factory.h"

#include "System/RenderSystem.h"


#define WIDTH 16
#define HEIGHT 10


int main()
{
    World world;


    // =========================
    // 创建玩家
    // =========================

    Entity player =
        CreatePlayer(
            world,
            "张三",
            WIDTH,
            HEIGHT
        );


    // =========================
    // 创建商店
    // =========================

    Entity shop =
        CreateShop(
            world,
            {
                WIDTH / 2,
                HEIGHT / 2
            }
        );


    // =========================
    // 创建怪物
    // =========================

    CreateSlime(world, {3, 2});
    CreateSlime(world, {5, 7});
    CreateSlime(world, {8, 3});
    CreateSlime(world, {12, 6});
    CreateSlime(world, {14, 1});


    RenderSystem renderSystem(
        WIDTH,
        HEIGHT
    );


    // =========================
    // 测试显示
    // =========================

    renderSystem.Update(world);


    return 0;
}