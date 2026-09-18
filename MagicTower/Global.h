#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <iostream>
#include <string>
#include <vector>

 //##连接字符串
#define DEFINE_MEMEBER(name, type) private:type name; public: void Set##name(type name){this->name = name;} type Get##name(){return this->name;}

using CStrRef = const std::string &;
#endif