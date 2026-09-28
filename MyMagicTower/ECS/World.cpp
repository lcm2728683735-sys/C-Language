#include "World.h"

Entity World::CreateEntity()
{
    return entitymanager.CreateEntity();
}

void World::DestroyEntity(Entity entity)
{
    if (!entitymanager.IsValid(entity))
    {
        return;
    }
    componentmanager.RemoveAllComponent(entity);

    entitymanager.DestroyEntity(entity);
}

bool World::IsValid(Entity entity)
{
    return entitymanager.IsValid(entity);
}
