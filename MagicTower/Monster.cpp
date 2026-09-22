#include "Monster.h"


Monster::Monster(const Point& p)
{
    Setx(p.Getx());
    Sety(p.Gety());
}

Slime::Slime(const Point &p):Monster(p)
{
    SetName("史莱姆");
    SetHP(10);
    SetAttack(2);
    SetDefend(1);
    SetSymbol("🎃");
    SetExp(100);
    SetGolden(100);
}
