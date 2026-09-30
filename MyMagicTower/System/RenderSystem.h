#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"
#include "../Game/Factory.h"


class RenderSystem
{
private:

    int width;
    int height;

public:

    RenderSystem(int width, int height)
        : width(width), height(height)
    {
    }


    void Update(World& world)
    {
        // =========================================
        // 1. 创建地图背景
        // =========================================

        std::vector<std::vector<std::string>> map(
            height,
            std::vector<std::string>(width, "🎄")
        );


        // =========================================
        // 2. 绘制所有 Position + Symbol
        // =========================================

        world.Each<Position, Symbol>(
            [&](Entity entity,
                Position& position,
                Symbol& symbol)
            {
                // ---------------------------------
                // 防止坐标越界
                // ---------------------------------

                if (position.x < 0 ||
                    position.x >= width ||
                    position.y < 0 ||
                    position.y >= height)
                {
                    return;
                }


                // ---------------------------------
                // 如果是怪物
                // ---------------------------------

                if (world.HasComponent<MonsterData>(entity))
                {
                    Health& health =
                        world.GetComponent<Health>(entity);

                    // 怪物死亡，不绘制
                    if (health.hp <= 0)
                    {
                        return;
                    }
                }


                // ---------------------------------
                // 正常绘制
                // ---------------------------------

                map[position.y][position.x] =
                    symbol.value;
            }
        );


        // =========================================
        // 3. 输出地图
        // =========================================

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                std::cout << map[y][x];
            }

            std::cout << '\n';
        }
    }
};