#include "Prop.h"

void Weapon::show()
{
    std::cout 
    <<"武器名:|" << GetName() 
    <<"|价格: |" << GetPrice() << "|" 
    <<"攻击力+|" << GetAttack()<< "|"
    <<std::endl;
}

PropPtr Weapon::clone()
{
    return std::make_shared<Weapon>(this->GetName(),this->GetPrice(),this->GetAttack());
}
