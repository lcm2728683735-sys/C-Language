#include "Scene.h"

int main()
{
    Player p("张三");
    Scene s(16,10,p);
    s.show();
    return 0;
}