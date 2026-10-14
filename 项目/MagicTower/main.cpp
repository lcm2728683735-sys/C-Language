#include "Scene.h"
#include "Point.h"
#include "Shop.h"
int main()
{
    Player p("张三");
    Scene s(WIDTH,HEIGHT,p);
    // Shop shop(p);
    // shop.show();
    while(1)
    {
        system("clear");
        s.Show();
        p.Show();
        p.Move();
        s.BuyInShop();
        Monster *m = s.IsInSamePlace();
        if(m)
        {
            Battle(p,*m);
        }
    }
    return 0;
}