#include "MovementSystem.h"

void MovementSystem::Update(World &world)
{
    world.Each<Position,Velocity>
    (
        [&](Entity entity,Position & position,Velocity & velocity)
        {  
        position.x += velocity.dx;
        position.y += velocity.dy;

        if(position.x < 0)
            position.x = 0;

        if (position.x >= width)
            position.x = width - 1;

        if (position.y < 0)
            position.y = 0;

        if (position.y >= height)
            position.y = height - 1;
        
        velocity.dx = 0;
        velocity.dy = 0;
        }
    );
}

