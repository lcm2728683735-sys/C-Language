
#pragma once
#include "System.h"
#include "../Global.h"


#define USER_DATA_PATH "Data/PassWord.txt"

struct UserData
{
    std::string UserName;
    std::string PassWord;
};

class UserSystem
{
public:
    // 注册 / 登录界面
    void RegisterLoginUI();

    // 注册
    void Register();

    // 登录
    bool Login();

    // 保存用户账号密码
    void SaveUser(UserData& userdata);

    // 读取用户信息
    void ReadUser();

    // 检查用户名和密码是否正确
    bool CheckUser(
        const std::string& username,
        const std::string& password
    );

    // 检查用户名是否存在
    bool UserExists(
        const std::string& username
    );

    // 获取当前登录用户
    const std::string& GetCurrentUser() const
    {
        return currentUser;
    }

private:
    // 当前登录的用户名
    std::string currentUser;
};
