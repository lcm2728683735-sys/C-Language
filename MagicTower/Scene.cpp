#include "Scene.h"

Scene::Scene(int width, int height, Player &p) : player(p),shop(p),width(width), height(height)
{
    shop.Setx(width / 2);
    shop.Sety(height /2);
    Map.resize(height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Map[i].push_back("🤗");
        }
    }
    p.SetMaxWidth(width);
    p.SetMaxHeight(height);

    InitRandContainer();
    InitialMonsters();
}

void Scene::Show()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Map[i][j] = "🎄";
        }
    }
    // 把地图上的位置给玩家
    Map[player.Gety()][player.Getx()] = player.GetSymbol();
    //位置留给商店
    Map[shop.Gety()][shop.Getx()] = shop.GetSymbol();
    for (auto m : Monsters )
    {
        if(m.GetHP() > 0)
            Map[m.Gety()][m.Getx()] = m.GetSymbol();
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << Map[i][j];
        }
        std::cout << std::endl;
    }
}

void Scene::InitialMonsters()
{
    srand(time(nullptr));
    Monsters.push_back(Slime(GetRandomPlace()));
    Monsters.push_back(Slime(GetRandomPlace()));
    Monsters.push_back(Slime(GetRandomPlace()));
    Monsters.push_back(Slime(GetRandomPlace()));
    Monsters.push_back(Slime(GetRandomPlace()));
}

void Scene::InitRandContainer()
{
    // 把除玩家所有位置放入容器 洗牌
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (player.Getx() == j && player.Gety() == i)
                continue;
            if(j == width /2 && i == height /2)
                continue;
            RandPlaces.push_back(Point(j, i));
        }
    }
    srand(time(nullptr));
    std::random_shuffle(RandPlaces.begin(), RandPlaces.end());
}

Point Scene::GetRandomPlace()
{
    Point p = *(RandPlaces.end() - 1);
    RandPlaces.pop_back();
    return p;
}

void Scene::BuyInShop()
{
    if(player.Getx() == shop.Getx() && player.Gety() == shop.Gety())
    {
        shop.show();
    }
}

Monster *Scene::IsInSamePlace()
{
    for (auto &m : Monsters)
    {
        if (m.GetHP() > 0 && player.Getx() == m.Getx() && player.Gety() == m.Gety())
        {
            return &m;
        }
    }
    return nullptr; 
}

void Battle(Player &p, Monster &m)
{
    while (1)
    {
        BattleInterface(p,m);
        int PlayerAttack = std::max(p.GetAttack() - m.GetDefend(),0);
        m.SetHP(m.GetHP() - PlayerAttack);
        std::cout << p.GetName() << "对" << m.GetName()  << "造成了|" << PlayerAttack << "|点伤害\n";
        sleep(1);
        if(m.GetHP() <= 0)
        {
            m.SetHP(0);
            BattleInterface(p,m);
            std::cout<<"你战胜了|" << m.GetName() << "!\n";
            std::cout<<"获得经验值|" <<  m.GetExp() << "|和金钱|" << m.GetGolden() << "|" << std::endl;
            sleep(1);
            p.SetExp(p.GetExp() + m.GetExp());
            p.LevelUp();
            p.SetGolden(m.GetGolden() + p.GetGolden());
            sleep(1);
            return;
        }

        int MonsterAttack = m.GetAttack() - p.GetDefend();
        p.SetHP(p.GetHP() - MonsterAttack);
        std::cout << m.GetName() << "对|" << p.GetName() << "|造成了|"<< PlayerAttack << "|点伤害\n";
        if(p.GetHP() <= 0)
        {
            std::cout << "你输了!游戏结束!\n";
            sleep(1);
            exit(-1);
        }
    }
}

void BattleInterface(Player &p, Monster &m)
{
    system("clear");
    std::cout << "玩家姓名:|" << p.GetName() << "|" << "   VS   ";
    std::cout << "怪兽姓名:|" << m.GetName() << "|" << std::endl;
    std::cout << "血量:|" << p.GetHP() << "|" << "             ";
    std::cout << "血量:|" << m.GetHP() << "|" << std::endl;
    std::cout << "攻击力:|" << p.GetAttack() << "|" << "            ";
    std::cout << "攻击力:|" << m.GetAttack() << "|" << std::endl;
    std::cout << "防御力:|" << p.GetDefend() << "|" << "             ";
    std::cout << "防御力:|" << m.GetDefend() << "|" << std::endl;
    std::cout << std::endl;
}
