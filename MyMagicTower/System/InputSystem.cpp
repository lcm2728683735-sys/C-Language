#include "InputSystem.h"

void InputSystem::Update(World &world, Entity player)
{
    char choice;

    std::cout << "请输入操作(w/a/s/d):";
    std::cin >> choice;

    auto &velocity =
        world.GetComponent<Velocity>(player);

    velocity.dx = 0;
    velocity.dy = 0;

    switch (choice)
    {
    case 'w':
        velocity.dy = -1;
        break;

    case 's':
        velocity.dy = 1;
        break;

    case 'a':
        velocity.dx = -1;
        break;

    case 'd':
        velocity.dx = 1;
        break;

    default:
        break;
    }
}
