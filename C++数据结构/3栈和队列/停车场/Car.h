#ifndef __CAR_H__
#define __CAR_H__

#include <string>
struct Car
{
    Car(){}
    Car(const std::string & name,int ArriveTime);
    std::string name;
    int ArriveTime;
    int LeaveTime;   
}; 


#endif