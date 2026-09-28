#include "MovementSystem.h"

void MovementSystem::Update(World& world,Entity entity)
{
    if(!world.HasComponent<Position>(entity))
        return;
    if(!world.HasComponent<Velocity>(entity))
        return;

    auto& position = world.GetComponent<Position>(entity);
    auto& velocity = world.GetComponent<Velocity>(entity);

    position.x += velocity.dx;
    position.y += velocity.dy;
}

// void MovementSystem::Move(Velocity & velocity)
// {
//     char choice;
//     std::cin >> choice;
//     switch (choice)
//     {
//     case 'w':
//         up(velocity);
//         break;
//     case 's':
//         down(velocity);
//         break;
//     case 'a':
//         left(velocity);
//         break;
//     case 'd':
//         right(velocity);
//         break;
//     default:
//         break;
//     }
// }
