#include "UserSystem.h"

void UserSystem::RegisterLoginUI()
{
    while (1)
    {
        std::cout << "=============================================================" << std::endl;
        std::cout << "|                                                           |" << std::endl;
        std::cout << "======================= 欢迎游玩魔塔！========================" << std::endl;
        std::cout << "|                                                           |" << std::endl;
        std::cout << "=============================================================" << std::endl;
        std::cout << "|                                                           |" << std::endl;
        std::cout << "=========================1. 新游戏 ===========================" << std::endl;
        std::cout << "|                                                           |" << std::endl;
        std::cout << "=========================2.继续游戏 ==========================" << std::endl;
        std::cout << "|                                                           |" << std::endl;
        std::cout << "=========================3.结束游戏 ==========================" << std::endl;
        std::cout << "|                                                           |" << std::endl;
        std::cout << "=============================================================" << std::endl;
        std::cout << "请输入你的选择:" << std::endl;
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            Register();
            Login();
        }
        if (choice == '2')
        {
            Login();
        }
        if (choice == '3')
        {
            std::cout << "欢迎下次再来!" << std::endl;
            sleep(2);
            std::exit(0);
        }

        else
        {
            std::cout << "输入错误,重新输入!" << std::endl;
        }
    }
}

void UserSystem::SaveUser(UserData &userdata)
{
    std::ofstream file(USER_DATA_PATH,std::ios::app);

    if (!file.is_open())
    {
        std::cout << "打开用户文件失败!";
        return;
    }

    file << userdata.UserName << ' ' << userdata.PassWord << '\n';

    file.close();
}

void UserSystem::ReadUser()
{
    std::ifstream file(USER_DATA_PATH,std::ios::in);

    if (!file.is_open())
    {
        std::cout << "打开用户文件失败!";
        return;
    }

    std::string username;
    std::string password;

    while (file >> username >> password)
    {
        std::cout << "用户名:" << username
                  << "密码:" << password << "\n";
    }

    file.close();
}

bool UserSystem::CheckUser(const std::string &username, const std::string &password)
{
    std::ifstream file(USER_DATA_PATH);

    if (!file.is_open())
    {
        std::cout << "打开用户文件失败!";
        return false;
    }

    std::string savedusername;
    std::string savedpassword;

    while (file >> savedusername >> savedpassword)
    {

        std::cout << "读取到用户名: [" << savedusername << "] 密码: [" << savedpassword << "]" << std::endl;
        std::cout << "正在对比: [" << username << "] 和 [" << password << "]" << std::endl;
        
        if (savedusername == username && savedpassword == password)
            return true;
    }
    return false;
}

bool UserSystem::UserExists(const std::string &username)
{
    std::ifstream file(USER_DATA_PATH);
    if (!file.is_open())
    {
        std::cout << "打开用户文件失败!";
        return false;
    }

    std::string savedusername;
    std::string savedpassword;

    while (file >> savedusername >> savedpassword)
    {
        if (savedusername == username)
            return true;
    }
    return false;
}

void UserSystem::Register()
{

    UserData userdata;

    while (1)
    {
        std::cout << "请输入用户名:";
        std::cin >> userdata.UserName;

        if (UserExists(userdata.UserName))
        {
            std::cout << "用户名为: " << userdata.UserName << "已经存在,重新输入用户名!" << std::endl;
            continue;
        }

        std::cout << "用户名为: " << userdata.UserName << "确认吗？(Y/N)" << std::endl;
        char choice;
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
            break; // 确认通过，退出循环
        else
            std::cout << "已取消，请重新输入用户名。" << std::endl;
    }
    while (1)
    {
        std::cout << "请输入密码: ";
        std::cin >> userdata.PassWord;

        std::string verifyPassword;
        std::cout << "请再次输入密码: ";
        std::cin >> verifyPassword;

        if (userdata.PassWord == verifyPassword)
        {
            break; // 两次密码一致
        }
        else
        {
            std::cout << "两次密码不一致，请重新输入！" << std::endl;
        }
    }
    SaveUser(userdata);
    std::cout << "用户名: " << userdata.UserName << "注册成功!" << std::endl;
}

void UserSystem::Login()
{
    UserData userdata;

    while (1)
    {                   
        std::cout << "请输入用户名:";
        std::cin >> userdata.UserName;

        if (!UserExists(userdata.UserName))
        {
            std::cout << "用户名为: " << userdata.UserName << "不存在,重新输入用户名!" << std::endl;
            continue;
        }

        while (1)
        {
            std::cout << "请输入密码: ";
            std::cin >> userdata.PassWord;
            if (CheckUser(userdata.UserName, userdata.PassWord))
            {
                std::cout << "用户: " << userdata.UserName << " 登录成功！" << std::endl;
                break; // 登录成功，退出循环
            }
            else
            {
                std::cout << "密码不正确，请重新输入！" << std::endl;
            }
        }
        // 登录
        std::cout << "用户:" << userdata.UserName << "登录成功！" << std::endl;
    }
}
