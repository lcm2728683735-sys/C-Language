#include <iostream>
#include <cmath>
class Point
{
public:
    Point():x(0),y(0){}
    Point(int x, int y):x(x),y(y){}

    void show()
    {
        std::cout <<"("<<x<<","<<y<<")"<<std::endl; 
    }
    //友元函数的声明
    friend double Distance(const Point& p1,const Point& p2);
    //友元类的声明
    friend class tool;
private:
    int x;
    int y;
};

double Distance(const Point& p1,const Point& p2)
{
    return std::sqrt(std::pow((p1.x - p2.x),2)+ std::pow(p1.y-p2.y,2));
}

class tool
{
public:
    static double Distance(const Point& p1)
    {
        return std::sqrt(std::pow((p1.x),2) + std::pow(p1.y,2));
    }
};

int main()
{
    Point p1;
    p1.show();
    Point p2(1,1);
    p2.show();

    std::cout<<tool::Distance(p2)<<std::endl;
    return 0;
}