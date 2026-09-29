#include "MovementSystem.h"

void MovementSystem::Update(World &world)
{
    world.Each<Position,Velocity>
    (
        [](Entity entity,Position & position,Velocity & velocity)
        {  
        position.x += velocity.dx;
        position.y += velocity.dy;
        velocity.dx = 0;
        velocity.dy = 0;
        }
    );
}

