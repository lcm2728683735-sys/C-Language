#include "LinkQueue.h"
#include "LinkStack.h"
#include <iostream>
#include "Car.h"
class CarStop
{
public:
    CarStop(const int &size) : StopSize(size) {}
    void ComeCar();
    void LeaveCar();
    void display();

private:
    LinkStack stop;
    LinkQueue pavement;
    const int StopSize;
};

void CarStop::ComeCar()
{
    Car *c = new Car;
    std::cout << "输入车牌";
    std::cin >> c->name;
    std::cout << "输入到达时间：";
    std::cin >> c->ArriveTime;

    if (stop.Size() == StopSize)
    {
        std::cout << "停车场已满,|" << c->name << "|停在了便道上\n"
                  << std::endl;
        pavement.Push(c);
    }
    else
    {
        std::cout << "🚗|"
                  << c->name
                  << "|进入停车场"
                  << std::endl;

        stop.Push(c);

        Car *test = (Car *)stop.GetTop();

        std::cout << "当前栈顶车辆："
                  << test->name
                  << std::endl;
    }
}

void CarStop::LeaveCar()
{
    std::cout << "输入离场车辆：";
    std::string leaveName;
    std::cin >> leaveName;

    LinkStack tempStop;
    int LeaveTime = 0;
    while (stop.IsEmpty() == false)
    {
        Car *c = (Car *)stop.GetTop();
        if (c->name == leaveName)
        {
            std::cout << "请输入车辆的离场时间：" << std::endl;
            std::cin >> c->LeaveTime;
            LeaveTime = c->LeaveTime;
            int money = (c->LeaveTime - c->ArriveTime) * 5;
            std::cout << "🚗" << c->name << "|于|"
                      << c->LeaveTime << "离开停车场，费用是|"
                      << money << "|" << std::endl;
            delete c;
            stop.Pop();
            break;
        }
        stop.Pop();
        tempStop.Push(c);
    }
    while (tempStop.IsEmpty() == false)
    {
        stop.Push(tempStop.GetTop());
        tempStop.Pop();
    }
    if (stop.Size() < StopSize && pavement.IsEmpty() == false)
    {
        Car *c = (Car *)pavement.GetFront();
        std::cout << "便道上的车|" << c->name << "|在" << c->ArriveTime << "进入停车场";
        pavement.Pop();
        stop.Push(c);
    }
}

void CarStop::display()
{
    LinkStack tempStop;
    while (stop.IsEmpty() == false)
    {
        tempStop.Push(stop.GetTop());
        stop.Pop();
    }
    while (tempStop.IsEmpty() == false)
    {
        Car *c = (Car *)tempStop.GetTop();
        std::cout << "|🚗|" << c->name << std::endl;
        tempStop.Pop();
        stop.Push(c);
    }
    for (int i = 0; i < pavement.Size(); i++)
        std::cout << "___";
    std::cout << std::endl;
    LinkQueue tempPavement;
    while (pavement.IsEmpty() == false)
    {
        Car *c = (Car *)pavement.GetFront();
        std::cout << "🚗" << c->name << " ";
        pavement.Pop();
        tempPavement.Push(c);
    }
    std::cout << std::endl;
    while (tempPavement.IsEmpty() == false)
    {
        pavement.Push(tempPavement.GetFront());
        tempPavement.Pop();
    }
    for (int i = 0; i < pavement.Size(); i++)
        std::cout << "____";
    std::cout << std::endl;
}

int main()
{
    CarStop s(3);
    while (1)
    {
        s.display();
        std::cout << "1、车辆进入停车场\n";
        std::cout << "2、车辆离开停车场\n";
        std::cout << "3、退出\n";

        int choice = -1;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            s.ComeCar();
            break;
        case 2:
            s.LeaveCar();
            break;
        default:
            exit(-1);
        }
    }
    return 0;
}
