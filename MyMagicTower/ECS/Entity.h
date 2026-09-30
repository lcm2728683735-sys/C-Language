#pragma once

#include "../Global.h"

using Entity = std::uint32_t;

constexpr Entity INVALID_ENTITY = 0;

class EntityManager
{
//生成Entity,优先使用已经销毁的Entity
public:
    Entity CreateEntity();

    void DestroyEntity(Entity entity);

    bool IsValid(Entity entity);

    const std::unordered_set<Entity>& GetEntities(){return aliveEntities;}

private:
    Entity nextentity = 1;
    //存放已经销毁的Entity
    std::queue<Entity> freeEntities;
    //存放还存活的entity
    std::unordered_set<Entity> aliveEntities;
};