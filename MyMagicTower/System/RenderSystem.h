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
        // 创建空地图
        std::vector<std::vector<std::string>> map(
            height,
            std::vector<std::string>(width, "🎄")
        );


        // 绘制所有带 Position + Symbol 的 Entity
        world.Each<Position, Symbol>(
            [&](Entity entity,
                Position& position,
                Symbol& symbol)
            {
                if (position.x < 0 ||
                    position.x >= width ||
                    position.y < 0 ||
                    position.y >= height)
                {
                    return;
                }

                map[position.y][position.x] = symbol.value;
            }
        );


        // 输出地图
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