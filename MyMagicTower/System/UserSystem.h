#pragma once

#include "../Global.h"
#include <fstream>

#define USER_DATA_PATH "../Data/PassWord.txt"

struct UserData
{
    std::string UserName;
    std::string PassWord;
};

class UserSystem
{
public:
    void RegisterLoginUI();

    //保存用户信息
    void SaveUser(UserData & userdata);
    //把所有用户信息读取
    void ReadUser();
    //验证账号密码
    bool CheckUser(const std::string & username,const std::string & password);
    //验证用户是否存在
    bool UserExists(const std::string & username);

    void Register();
    void Login();
private:
};
