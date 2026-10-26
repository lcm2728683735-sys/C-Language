#ifndef __DATACENTER_H__
#define __DATACENTER_H__

#include <stdbool.h>

bool DataCenterInit();
bool IsUserExist(const char* name);
bool AddNewUser(const char * name ,const char * passwd);

#endif