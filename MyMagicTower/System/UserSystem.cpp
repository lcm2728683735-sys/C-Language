#include "UserSystem.h"

#include <fstream>
#include <unistd.h>


// ============================================================
// 注册 / 登录界面
// ============================================================

void UserSystem::RegisterLoginUI()
{
    while (true)
    {
        system("clear");

        std::cout
            << "========================================\n"
            << "              魔塔游戏\n"
            << "========================================\n\n";

        std::cout
            << "1、注册\n"
            << "2、登录\n"
            << "3、退出\n\n";

        std::cout << "请选择：";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            Register();
            break;

        case 2:
            if (Login())
            {
                return;
            }
            break;

        case 3:
            std::cout << "游戏退出。\n";
            exit(0);

        default:
            std::cout << "输入错误！\n";
            sleep(1);
            break;
        }
    }
}


// ============================================================
// 注册
// ============================================================

void UserSystem::Register()
{
    system("clear");

    std::cout
        << "========================================\n"
        << "                 注册\n"
        << "========================================\n\n";

    UserData userdata;

    std::cout << "请输入用户名：";
    std::cin >> userdata.UserName;

    // 检查用户名是否已经存在
    if (UserExists(userdata.UserName))
    {
        std::cout
            << "\n用户名【"
            << userdata.UserName
            << "】已经存在！\n";

        sleep(1);
        return;
    }

    std::cout << "请输入密码：";
    std::cin >> userdata.PassWord;

    SaveUser(userdata);

    std::cout
        << "\n注册成功！\n";

    sleep(1);
}


// ============================================================
// 登录
// ============================================================

bool UserSystem::Login()
{
    UserData userdata;

    while (true)
    {
        system("clear");

        std::cout
            << "========================================\n"
            << "                 登录\n"
            << "========================================\n\n";

        std::cout << "请输入用户名：";
        std::cin >> userdata.UserName;

        // 用户不存在
        if (!UserExists(userdata.UserName))
        {
            std::cout
                << "\n用户名【"
                << userdata.UserName
                << "】不存在！\n";

            std::cout
                << "1、重新输入\n"
                << "2、返回\n"
                << "\n请选择：";

            int choice;
            std::cin >> choice;

            if (choice == 2)
            {
                return false;
            }

            continue;
        }

        // 用户存在，输入密码
        while (true)
        {
            std::cout << "请输入密码：";
            std::cin >> userdata.PassWord;

            if (CheckUser(
                    userdata.UserName,
                    userdata.PassWord))
            {
                // 保存当前登录用户
                currentUser = userdata.UserName;

                std::cout
                    << "\n用户【"
                    << currentUser
                    << "】登录成功！\n";

                sleep(1);

                return true;
            }

            std::cout
                << "\n密码错误！\n"
                << "1、重新输入\n"
                << "2、返回\n"
                << "\n请选择：";

            int choice;
            std::cin >> choice;

            if (choice == 2)
            {
                return false;
            }
        }
    }
}


// ============================================================
// 保存用户账号密码
// ============================================================

void UserSystem::SaveUser(UserData& userdata)
{
    std::ofstream file(USER_DATA_PATH, std::ios::app);

    if (!file.is_open())
    {
        std::cout
            << "无法打开用户数据文件！\n";
        return;
    }

    /*
        文件格式：

        用户名 密码
    */

    file
        << userdata.UserName
        << " "
        << userdata.PassWord
        << "\n";

    file.close();
}


// ============================================================
// 读取用户信息
// ============================================================

void UserSystem::ReadUser()
{
    std::ifstream file(USER_DATA_PATH);

    if (!file.is_open())
    {
        std::cout
            << "无法打开用户数据文件！\n";
        return;
    }

    UserData userdata;

    while (
        file
        >> userdata.UserName
        >> userdata.PassWord
    )
    {
        std::cout
            << "用户名："
            << userdata.UserName
            << "\n";

        std::cout
            << "密码："
            << userdata.PassWord
            << "\n\n";
    }

    file.close();
}


// ============================================================
// 检查用户名是否存在
// ============================================================

bool UserSystem::UserExists(
    const std::string& username)
{
    std::ifstream file(USER_DATA_PATH);

    if (!file.is_open())
    {
        return false;
    }

    UserData userdata;

    while (
        file
        >> userdata.UserName
        >> userdata.PassWord
    )
    {
        if (userdata.UserName == username)
        {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}


// ============================================================
// 检查用户名 + 密码
// ============================================================

bool UserSystem::CheckUser(
    const std::string& username,
    const std::string& password)
{
    std::ifstream file(USER_DATA_PATH);

    if (!file.is_open())
    {
        return false;
    }

    UserData userdata;

    while (
        file
        >> userdata.UserName
        >> userdata.PassWord
    )
    {
        if (
            userdata.UserName == username &&
            userdata.PassWord == password
        )
        {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}
