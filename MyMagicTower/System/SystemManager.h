#pragma once
#include "System.h"
#include "../Global.h"

class SystemManager
{
public:
    template<typename T>
    void AddSystem()
    {
        systems.push_back(std::make_unique<T>());
    }

    void Update(World & world)
    {
        for(auto & system:systems)
        {
            system->Update(world);
        }
    }
private:
    std::vector<std::unique_ptr<ISystem>> systems;
};