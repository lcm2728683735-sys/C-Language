#include "Scene.h"
#include "Point.h"

int main()
{
    Player p("张三");
    Scene s(16,10,p);
    while(1)
    {
        system("clear");
        s.show();
        p.Move();
    }
    return 0;
}