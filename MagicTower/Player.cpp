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
    this->SetLevel(1);
    this->SetExp(0);
    this->SetGolden(0);
    this->SetAttrPoint(0);
    w = nullptr;

}

void Player::Move()
{
    std::cout << "请输入玩家操作(w:上 s:下 a:左 d:右 p:查看玩家属性 b:背包):";
    char choice;
    std::cin >> choice;
    switch (choice)
    {
    case 'w':
        up();
        break;
    case 's':
        down();
        if (Gety() >= MaxHeight)
            Sety(MaxHeight - 1);
        break;
    case 'a':
        left();
        break;
    case 'd':
        right();
        if (Getx() >= MaxWidth)
            Setx(MaxWidth - 1);
        break;
    case 'p':
        AttrInterface();
        break;
    case 'b':
        ShowBag();
        break;
    default:
        break;
    }
}

void Player::LevelUp()
{
    if (GetExp() >= 100)
    {
        SetExp(GetExp() - 100);
        Level++;
        AttrPoint +=5;
        std::cout << "恭喜升级!升到|" << Level << "|级!\n";
    }
}

void Player::AttrInterface()
{
    while(1)
    {
        std::cout <<"当前可分配的属性点是:|" << AttrPoint << "|" << std::endl;
        std::cout << "1、攻击力:" <<GetAttack() <<std::endl;
        std::cout << "2、防御力:" <<GetDefend() <<std::endl;
        std::cout << "3、血量:" << GetHP() << std::endl;
        std::cout << "4、退出加点" << std::endl;
        int number;

        std::cout << "请选择你要分配的属性:";
        int choice =GetIntInput("请输入你的选择：");
        if(choice == 4)
            return;
        std::cout << "请选择你要添加的数量:";
        std::cin >> number;
        while(number > AttrPoint && number < 0)
        {
            std::cout << " 分配点数不符合规则，请重新选择!";
            sleep(1);
        }
        AttrPoint -= number;
        switch (choice)
        {
        case 1:
            SetAttack(GetAttack() + number);
            break;
        case 2:
            SetDefend(GetDefend() + number);
        case 3:
            SetHP(GetHP() + number);
            break;
        case 4:
            return;
        default:
            break;
        }
        std::cout << "分配成功!\n"; 
    }
}

void Player::Show()
{
    std::cout << "玩家姓名：|" << GetName() << "|" << std::endl;
    std::cout << "血量❤️：|" << GetHP() << "|" << std::endl;
    std::cout << "攻击力🔪:|" << GetAttack() << "|" << std::endl;
    std::cout << "防御力🛡️:|" << GetDefend() << "|" << std::endl;
    std::cout << "等级:|" << GetLevel() << "|" << "经验值:|" << GetExp() << "|" << std::endl;
    std::cout << "金币:|" << GetGolden() << "|" << std::endl;
    if(w)
        std::cout << "武器:|" << w->GetName() << "|" << std::endl; 
}
 
void Player::ShowBag()
{
    std::cout << "=======================背包=======================\n"
            << std::endl;
    int i = 0;
    for (; i < bag.size(); i++)
    {
        std::cout << i + 1 << "、";
        bag[i]->show();
    }
    std::cout << i + 1 << "、" << "退出"<< std::endl;
    std::cout <<"请选择你要操作的物品" <<std::endl;
    int choice =GetIntInput("请输入你的选择：");
    if(choice == i + 1)
    {
        return ;
    }
    if(auto ptr = dynamic_cast<Weapon *>(bag[choice-1].get());ptr != nullptr)
    {
        std::cout << "是否要更换武器?(y/n)";
        char c = 0;
        std::cin >> c;

        
        if(c == 'y' || c == 'Y')
        {
            if(w)
            {
                std::cout << "卸下|"  << w->GetName() << "|" <<std:: endl;
                SetAttack(GetAttack() - w->GetAttack());
            }
            w = ptr;
            std::cout << "装备|" << w->GetName() << "|" << std::endl;
            SetAttack(GetAttack() + w->GetAttack());
            sleep(1);
        }
    } 
}

int Player::GetIntInput(const std::string &input)
{
    int value = 0;
    while (true)
    {
        std::cout << input;
        if(std::cin >>value)
        {
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "输入无效,请输入数字!\n";
    }
    return 0;
}

void Player::InsertBag(const PropPtr &ptr)
{
    bag.push_back(ptr->clone());
}
