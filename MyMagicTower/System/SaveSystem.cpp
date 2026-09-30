#include "SaveSystem.h"


void InputSystem::Update(
    World& world,
    Entity player)
{
    openAttribute = false;
    openBag = false;
    quit = false;


    if (!world.HasComponent<Velocity>(player))
        return;


    Velocity& velocity =
        world.GetComponent<Velocity>(player);


    // 每次输入之前清零
    velocity.dx = 0;
    velocity.dy = 0;


    std::cout
        << "请输入玩家操作"
        << "(w:上 s:下 a:左 d:右 "
        << "p:属性 b:背包 q:退出): ";


    char choice;

    std::cin >> choice;


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


    case 'p':

        openAttribute = true;

        break;


    case 'b':

        openBag = true;

        break;


    case 'q':

        quit = true;

        break;


    default:

        break;
    }
}