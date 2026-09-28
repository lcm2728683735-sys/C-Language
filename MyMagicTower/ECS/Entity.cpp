#include "Entity.h"

Entity EntityManager::CreateEntity()
{
    Entity entity;
    if(!freeEntities.empty())
    {
        entity = freeEntities.front();
        freeEntities.pop();
        return entity;
    }
    else
    {
        entity = nextentity++;
    }

    aliveEntities.insert(entity);

    return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
    if(!IsValid(entity))
    {
        return;
    }
    aliveEntities.erase(entity);
    freeEntities.push(entity);
}

bool EntityManager::IsValid(Entity entity)
{
    return aliveEntities.find(entity) != aliveEntities.end();
}
