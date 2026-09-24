#include "../Global.h"
#include "Entity.h"

class IComponentStorage
{
public:
    virtual ~IComponentStorage() = default;
};

template<typename T>
class ComponentStorage : public IComponentStorage
{
public:
    std::unordered_map<Entity, T> components;
};

class ComponentManager
{
public:
    template<typename T>
    void AddComponent(Entity entity, const T& component)
    {
        std::type_index type = typeid(T);

        auto it = storages.find(type);

        if(it == storages.end())
        {
            //如果找不到，那么新建
            auto storage = std::make_unique<ComponentStorage<T>>();
            storage ->components[entity] = component;
            storages[type] = std::move(storage);
            return;
        }
        auto *storage = static_cast<ComponentStorage<T>*>(it->second.get());
    }

    template<typename T>
    T& GetComponent(Entity entity)
    {
        std::type_index type = typeid(T);
        auto it = storages.find(type);

        if(it == storages.end())
        {
            //运行时间超时
            throw std::runtime_error("Component not found");
        }
        auto *storage = static_cast<ComponentStorage<T>*>(it->second.get());
        return storage->components.at(entity);
    }

    template<typename T>
    bool HasComponent(Entity entity)
    {
        std::type_index type = typeid(T);
        auto it = storages.find(type);
        if(it == storages.end())
        {
            throw false;
        }
        auto *storage = static_cast<ComponentStorage<T>*>(it->second.get());
        return storage->components.find(entity)
            != storage->components.end();
    }

    template<typename T>
    void RemoveComponent(Entity entity)
    {
        std::type_index type = typeid(T);
        auto it = storages.find(type);
        if(it == storages.end())
        {
            throw;
        }
        auto *storage = static_cast<ComponentStorage<T>*>(it->second.get());
        storage->components.erase(entity);
    }

private:    
    //核心容器  
    std::unordered_map<std::type_index,std::unique_ptr<IComponentStorage>>storages;
};

struct Position  //坐标
{
    int x;
    int y;
};

struct HP
{
    int Mix_Hp;
    int Hp;  
};

struct Player //玩家
{
    std::string name;
    int Hp;
    int Level;
    int Attack;
    int Defend;
    int Exp;
    int Golden;
};

struct Monster //怪物
{
    int attack;
    int defense;
    int gold;
    int exp;
};

struct PlayerSaveData
{
    int x;
    int y;
};