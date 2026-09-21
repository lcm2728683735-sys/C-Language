#include "Scene.h"
#include <iostream>

Scene::Scene(int width,int height,Player &p):player(p),width(width),height(height)
{
    Map.resize(height);
    for (int i = 0;i < height; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            Map[i].push_back("🤣");
        }
    }
    p.SetMaxWidth(width);
    p.SetMaxHeight(height);
}


void Scene::show()
{
    for (int i = 0;i < height; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            Map[i][j] ="🤗";
        }
    }
    //把地图上的位置给玩家
    Map[player.Gety()][player.Getx()] = player.GetSymbol();

    for (int i = 0;i < height; i++)
    {
        for(int j = 0; j< width ; j++)
        {
            std::cout << Map[i][j];
        }
        std::cout << std::endl;
    }
}
