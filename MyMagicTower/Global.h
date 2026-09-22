#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <unistd.h>   //sleep
#include <memory>
#include <limits>
#include <filesystem>
//##连接字符串
#define DEFINE_MEMEBER(name, type) private:type name; public: void Set##name(type name){this->name = name;} type Get##name()const{return this->name;}

using CStrRef = const std::string &;

#define WIDTH 16
#define HEIGHT 10
#endif