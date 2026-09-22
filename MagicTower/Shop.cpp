#include "Shop.h"
#include "Player.h"
Shop::Shop(Player &p) : p(p)
{
    this->SetSymbol("🛒");
    PropVec.push_back(std::make_shared<Weapon>("饮血剑", 10, 10));
    PropVec.push_back(std::make_shared<Weapon>("无尽之刃", 20, 20));
    PropVec.push_back(std::make_shared<Weapon>("BKB", 30, 30));
    PropVec.push_back(std::make_shared<Weapon>("跳刀", 40, 40));
}

void Shop::show()
{
    Player player;
    while (1)
    {
        system("clear");
        std::cout << "================== 欢迎来到商店==================\n";
        int i = 0;
        for (; i < PropVec.size(); i++)
        {
            std::cout << i + 1 << "、";
            PropVec[i]->show();
        }
        std::cout << i + 1 << "、退出" << std::endl;
        std::cout << "请输入你要购买的编号：\n";
        std::cout << "==================================================\n";
        int choice =player.GetIntInput("请输入你的选择：");

        if (choice == i + 1)
        {
            std::cout << "欢迎再次光临\n";
            std::cout << "==================================================\n";
            sleep(1);
            return;
        }

        if (choice > i + 1 || choice < 0)
        {
            std::cout << "输入非法，请重新输入\n";
            std::cout << "==================================================\n";
            continue;
        }

        p.SetGolden(p.GetGolden() - PropVec[choice - 1]->GetPrice());
        std::cout << "恭喜购买了|" <<PropVec[choice - 1]->GetName() << "|!" << std::endl;
        p.InsertBag(PropVec[choice - 1]) ;
        sleep(1);
    }
}

