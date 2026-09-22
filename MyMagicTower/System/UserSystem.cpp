#include "UserSystem.h"

void UserSystem::RegisterLoginUI()
{
    while(1)
    {
    std::cout << "=============================================================";
    std::cout << "|                                                           |";
    std::cout << "======================== 欢迎游玩魔塔！=======================";
    std::cout << "|                                                           |";
    std::cout << "=============================================================";  
    std::cout << "|                                                           |";
    std::cout << "=========================1. 新游戏 ===========================";    
    std::cout << "|                                                           |";
    std::cout << "=========================2.继续游戏 ==========================";   
    std::cout << "|                                                           |";
    std::cout << "=========================3.结束游戏 =========================="; 
    std::cout << "|                                                           |";
    std::cout << "=============================================================";
    }
}

void UserSystem::TryRegister()
{
    UserData userdata;
    userdata.UserName = nullptr;
    userdata.PassWord = nullptr;
    std::string VerifyPassWord = nullptr;

    //输入用户名
    std::cout << "请输入用户名:"<<std::endl;
    std::cin >> userdata.UserName;

    //检查是否存在
    if(userdata.UserName == 1)
    {
        std::cout << "用户名为: "<< userdata.UserName <<"已经存在,重新输入用户名!"<<std::endl;
        userdata.UserName = nullptr;
    }

    std::cout << "用户名为: "<< userdata.UserName <<"确认吗？(Y/N)"<<std::endl;
    char choice; 
    std::cin >> choice;
    if(choice != 'Y' ||choice != 'y' )
    {
        std::cout << "重新输入用户名!" << std::endl;
        TryRegister();
        sleep(1);
    }

    //输入密码
    std::cout << "请输入密码():"<<std::endl;
    std::cin >> userdata.PassWord;
    std::cout << "请再次输入密码():"<<std::endl;
    std::cin >> VerifyPassWord;
    if(VerifyPassWord != userdata.PassWord)
    {
        std::cout << "两次密码不一致!重新输入!" << std::endl;
        userdata.PassWord = nullptr;
        TryRegister();
        sleep(1);
    }

    //创建用户
    Register(userdata);
}

void UserSystem::TryLogin()
{
    UserData userdata;
    userdata.UserName = nullptr;
    userdata.PassWord = nullptr;

    //输入用户名
    std::cout << "请输入用户名:"<<std::endl;
    std::cin >> userdata.UserName;

    //检查是否存在
    if(userdata.UserName != 1)
    {
        std::cout << "用户名为: "<< userdata.UserName <<"不存在这个用户!重新输入用户名!"<<std::endl;
        userdata.UserName = nullptr;
        TryLogin();
    }

    //输入密码
    std::cout << "请输入密码:"<<std::endl;
    std::cin >> userdata.PassWord;
    if(userdata.PassWord != )
    {
        std::cout << "密码不正确！重新输入！"<<std::endl;
        TryLogin();
    }

    //创建用户
    Register(userdata);
}
