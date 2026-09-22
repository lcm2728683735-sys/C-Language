#include "Global.h"

struct UserData
{
    std::string UserName;
    std::string PassWord;
};

class UserSystem
{
public:
    void RegisterLoginUI();
    void TryRegister();
    void TryLogin();
    bool Register(UserData & userdata);
    bool Login(UserData & userdata);

private:
    bool CheckUserName(const std::string & username);
    bool CheckPassWord(const std::string & password);


};

// void MakeDir(const std::string &path)
// {
//     std::string cmd = "makdir" + path;
//     system(cmd.c_str());
// }

// namespace fs = std::filesystem;

// void SaveLoadFile(int ArchiveID)
// {
//     if(std::filesystem::exists())
//     {
//         std::string name = "zhangsan";
//         MakeDir("./存档/" + name);
//         MakeDir("./存档/" + name +"/存档1");
//         MakeDir("./存档/" + name +"/存档2");
//         MakeDir("./存档/" + name +"/存档3 ");
//     }

//     if(ArchiveID < 1 || ArchiveID >3)
//         std::cout << "请在1~3中选择存档!"<< std ::endl;
// }
