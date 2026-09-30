#pragma once

#include "System.h"
#include "../Global.h"
#include "../ECS/World.h"


class InputSystem
{
private:
    bool openAttribute = false;
    bool openBag = false;

public:

    void Update(World& world, Entity player);
    

    bool IsAttributeRequested() const
    {
        return openAttribute;
    }

    bool IsBagRequested() const
    {
        return openBag;
    }
};