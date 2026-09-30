#pragma once

#include "../ECS/World.h"
#include "../Game/Prop.h"
#include "../Global.h"

class SaveSystem
{
public:

    // 保存玩家游戏数据
    bool Save(
        World& world,
        Entity player,
        const std::string& username
    );

    // 加载玩家游戏数据
    bool Load(
        World& world,
        Entity player,
        const std::string& username
    );

    // 判断玩家是否存在存档
    bool Exists(
        const std::string& username
    ) const;

private:

    // 获取存档路径
    std::string GetSavePath(
        const std::string& username
    ) const;
};