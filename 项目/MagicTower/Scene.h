#ifndef __SCENE_H__
#define __SCENE_H__
#include "Global.h" 
#include "Player.h"
#include "Monster.h"
#include "Shop.h"
class Scene
{
public: 
    Scene(int width,int height,Player& p);
    void Show();

    Point GetRandomPlace();
    //判断进入商店
    void BuyInShop();
    //判断进入战斗
    Monster* IsInSamePlace();

private:
    void InitialMonsters(); 
    void InitRandContainer();
    std::vector<std::vector<std::string>> Map;  //地图
    std::vector<Monster> Monsters;//怪兽列表
    std::vector<Point> RandPlaces;//随机坐标容器
    Player &player;   //引用成员
    Shop shop;
    int width;
    int height;
};

void Battle(Player &p,Monster &m);
void BattleInterface(Player &p,Monster &m);

#endif