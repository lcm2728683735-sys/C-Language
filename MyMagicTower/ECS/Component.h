#pragma once

#include "../Global.h"
#include "Entity.h"
#include "../Game/Prop.h"


class IComponentStorage
{
public:
    virtual ~IComponentStorage() = default;

    virtual void RemoveEntity(Entity entity) = 0;
};


template<typename T>
class ComponentStorage : public IComponentStorage
{
public:

    std::unordered_map<Entity, T> components;

    void RemoveEntity(Entity entity) override
    {
        components.erase(entity);
    }
};


// ============================================================
// Component Manager
// ============================================================

class ComponentManager
{
public:

    // 添加 Component
    template<typename T>
    void AddComponent(
        Entity entity,
        const T& component)
    {
        std::type_index type = typeid(T);

        auto it = storages.find(type);

        if (it == storages.end())
        {
            auto storage =
                std::make_unique<ComponentStorage<T>>();

            storage->components[entity] = component;

            storages[type] =
                std::move(storage);

            return;
        }

        auto* storage =
            static_cast<ComponentStorage<T>*>(
                it->second.get()
            );

        storage->components[entity] =
            component;
    }


    // 获取 Component
    template<typename T>
    T& GetComponent(Entity entity)
    {
        std::type_index type = typeid(T);

        auto it = storages.find(type);

        if (it == storages.end())
        {
            throw std::runtime_error(
                "Component storage not found"
            );
        }

        auto* storage =
            static_cast<ComponentStorage<T>*>(
                it->second.get()
            );

        return storage->components.at(entity);
    }


    // 判断 Entity 是否拥有 Component
    template<typename T>
    bool HasComponent(Entity entity)
    {
        std::type_index type = typeid(T);

        auto it = storages.find(type);

        if (it == storages.end())
        {
            return false;
        }

        auto* storage =
            static_cast<ComponentStorage<T>*>(
                it->second.get()
            );

        return
            storage->components.find(entity)
            != storage->components.end();
    }


    // 删除 Component
    template<typename T>
    void RemoveComponent(Entity entity)
    {
        std::type_index type = typeid(T);

        auto it = storages.find(type);

        if (it == storages.end())
        {
            return;
        }

        auto* storage =
            static_cast<ComponentStorage<T>*>(
                it->second.get()
            );

        storage->components.erase(entity);
    }


    // 删除 Entity 的所有 Component
    void RemoveAllComponent(Entity entity)
    {
        for (auto& [type, storage] : storages)
        {
            storage->RemoveEntity(entity);
        }
    }


private:

    std::unordered_map<
        std::type_index,
        std::unique_ptr<IComponentStorage>
    > storages;
};


// ============================================================
// Game Components
// ============================================================

struct Identity
{
    std::string name;
};


struct Position
{
    int x = 0;
    int y = 0;
};


struct Velocity
{
    int dx = 0;
    int dy = 0;
};


struct Symbol
{
    std::string value;
};


struct Health
{
    int hp = 0;
};


// 玩家等级相关数据
struct PlayerStats
{
    int level = 1;
    int exp = 0;
    int attrPoint = 0;
};


// 金钱
struct Money
{
    int golden = 100;
};


// 战斗属性
struct CombatStats
{
    int attack = 0;
    int defend = 0;
    int criticalHit = 0;
    int agile = 0;
};


// 怪物专属数据
struct MonsterData
{
    std::string name;

    int exp = 0;

    int golden = 0;
};


// 玩家背包
struct Inventory
{
    std::vector<PropPtr> items;
};


// 商店
struct ShopData
{
    std::vector<PropPtr> props;

    ShopData()
    {
        props.push_back(
            std::make_shared<Weapon>(
                "饮血剑",
                10,
                10
            )
        );

        props.push_back(
            std::make_shared<Weapon>(
                "无尽之刃",
                20,
                20
            )
        );

        props.push_back(
            std::make_shared<Weapon>(
                "BKB",
                30,
                30
            )
        );

        props.push_back(
            std::make_shared<Weapon>(
                "跳刀",
                40,
                40
            )
        );
    }
};


// 当前装备
struct Equipment
{
    PropPtr weapon = nullptr;
};