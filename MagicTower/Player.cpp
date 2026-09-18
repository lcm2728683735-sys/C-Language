#include "Player.h"

Player::Player(CStrRef name)
{
    this->SetName(name);
    this->SetSymbol("🤣");
    this->SetAttack(10);
    this->SetHP(100);
    this->SetDefend(1);
    this->Setx(0);
    this->Sety(0);
}

void Player::Move()
{
    std::cout << "请输入玩家操作(w:上 s:下 a:左 d:右):";
    int choice = -1;
    std::cin >> choice;
    switch(choice)
    {
    case 'w':
        up();
    break;
    case 's':
        down();
    break;
    case 'a':
        left();
    break;
    case 'd':
        right();
    break;
    default:
        break;
    }

}
