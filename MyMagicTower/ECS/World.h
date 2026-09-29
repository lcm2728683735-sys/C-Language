#pragma once

#include "../Global.h"
#include "Entity.h"
#include "Component.h"

class World
{
public:

    Entity CreateEntity();

    // 销毁 Entity，同时删除它的所有 Component
    void DestroyEntity(Entity entity);

    // 判断 Entity 是否有效
    bool IsValid(Entity entity);


    //使用模板函数接管Component,并且在此基础上初始化
    template<typename T>
    void AddComponent(Entity entity,const T& component)
    {
        componentmanager.AddComponent<T>(entity,component);
    }

    template<typename T>
    T& GetComponent(Entity entity)
    {
        return componentmanager.GetComponent<T>(entity);
    }

    template<typename T>
    bool HasComponent(Entity entity)
    {
        return componentmanager.HasComponent<T>(entity);
    }

    template<typename T>
    void RemoveComponent(Entity entity)
    {
        componentmanager.RemoveComponent<T>(entity);
    }

    template<typename... Components>
    bool HasComponents(Entity entity)
    {
        return (HasComponent<Components>(entity)&& ...);
    }

    template<typename... Components,typename Func>
    void Each(Func func)
    {
        for(Entity entity:entitymanager.GetEntities())
        {
            if(!HasComponents<Components...>(entity))
                continue;
            func(entity,GetComponent<Components>(entity)...);
        }
    }


private:
    ComponentManager componentmanager;
    EntityManager entitymanager;
};

