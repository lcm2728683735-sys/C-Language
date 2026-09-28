#pragma once

#include "../Global.h"
#include "Entity.h"

class IComponentStorage
{
public:
    //作为类型擦除的父类接口
    virtual ~IComponentStorage() = default;
    //删除Entity的虚函数
    virtual void RemoveEntity(Entity entity) = 0;
};

//模板子类用来实现删除Entity
template<typename T>
class ComponentStorage : public IComponentStorage
{
public:
    //一个Component对应一个容器
    //即Entity-> T
    std::unordered_map<Entity, T> components;

    void RemoveEntity(Entity entity) override
    {
        components.erase(entity);  
    }
};



class ComponentManager
{
public:
    template<typename T>
    void AddComponent(Entity entity, const T& component)
    {
        //生成T对应的类型id
        std::type_index type = typeid(T);
        //查找类型id
        auto it = storages.find(type);

        if(it == storages.end())
        {
            //如果找不到，那么新建
            auto storage = std::make_unique<ComponentStorage<T>>();

            //ComponentStorage<T>就是std::unordered_map<Entity, T>

            storage ->components[entity] = component;
            storages[type] = std::move(storage);
            return;
        }
        auto *storage = static_cast<ComponentStorage<T>*>(it->second.get());
        storage->components[entity] = component;
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
            return false;
        }
        auto *storage = static_cast<ComponentStorage<T>*>(it->second.get());
        return storage->components.find(entity)!= storage->components.end();
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

    void RemoveAllComponent(Entity entity)
    {
        for(auto & [type,storage] : storages)
        {
            storage->RemoveEntity(entity);
        }
    }
private:    
    //核心容器 :通过T的类型找到对应储存器
    //storages->由模板生成的类型T的typeid-> T 的储存空间
    std::unordered_map<
    std::type_index,  //类型id
    //把不同容器的类型变成一个统一的IComponentStorage*，std::unique_ptr用于父类析构时自动销毁
    std::unique_ptr<IComponentStorage>
    >storages;
};




struct Position  {int x;int y;};
struct Velocity{int dx;int dy;};
struct PlayerSaveData{int x;int y;};
struct PlayerStats{int attack;int defense;int gold;};
struct Health{int hp;int maxHp;};




