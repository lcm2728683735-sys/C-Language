#ifndef __POINT_H__
#define __POINT_H__

#include "Global.h"
class Point
{
public:
    Point() : x(0),y(0){}
    void up()   {if(y>=1)y--;}
    void down() {y++;}
    void left() {if(x>=1)x--;}
    void right(){x++;}
    DEFINE_MEMEBER(x,int); 
    DEFINE_MEMEBER(y,int);
};


#endif