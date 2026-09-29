#include "InputSystem.h"

void InputSystem::Update(World &world)
{
        char choice;

        std::cin >> choice;

        world.Each<Velocity>([choice](Entity entity, Velocity& velocity)
        {
            switch (choice)
                {
                case 'w':
                    velocity.dx = 0;
                    velocity.dy = -1;
                    break;

                case 's':
                    velocity.dx = 0;
                    velocity.dy = 1;
                    break;

                case 'a':
                    velocity.dx = -1;
                    velocity.dy = 0;
                    break;

                case 'd':
                    velocity.dx = 1;
                    velocity.dy = 0;
                    break;

                default:
                    velocity.dx = 0;
                    velocity.dy = 0;
                    break;
                }
            }
        );
    }
