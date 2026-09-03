#include <iostream>
#include <dirent.h>
#include "LinkTree.h"
#include "DynamicArray.h"
#include <sys/stat.h>

std::string Transform(size_t size)
{
    if (size < 1024)
        return std::to_string(size) + "B";
    else if (size < 1024 * 1024)
        return std::to_string((1.0 * size) / 1024) + "KB";
    else if (size < 1024 * 1024 * 1024)
        return std::to_string((1.0 * size) / (1024 * 1024)) + "MB";
    else
        return std::to_string((1.0 * size) / (1024 * 1024 * 1024)) + "GB";
}
void ExploreDirectory(const std::string &path, TreeNode *node)
{
    // 打开文件夹
    DIR *dir = opendir((path + "/").c_str());
    if (dir == nullptr)
    {
        std::cout << "文件夹路径有误!:" << path << std::endl;
        return;
    }
    dirent *e = nullptr;
    while ((e = readdir(dir)) != nullptr)
    {
        if (std::string(e->d_name) == "." || std::string(e->d_name) == "..")
            continue;

        TreeNode *child = new TreeNode(e->d_name);
        child->Connect(node);
        if (e->d_type == DT_DIR)
        {
            ExploreDirectory(path + "/" + std::string(e->d_name), child);
        }
        else
        {
            struct stat s;
            std::string filePath = path + "/" + std::string(e->d_name);

            if (stat(filePath.c_str(), &s) == 0)
            {
                std::cout << filePath
                          << " 大小: "
                          << Transform(s.st_size)
                          << std::endl;

                child->SetData(
                    std::string(e->d_name) +
                    " size:" +
                    Transform(s.st_size));
            }
        }
    }
    // 关闭目录流
    closedir(dir);
}
void Find(LinkTree &tree, const std::string &name)
{
    DARRAY::DynamicArray a = tree.FindByElement(name);
    for (int i = 0; i < a.Size(); i++)
    {
        std::cout << tree.GetNodePath((TreeNode *)a[i]) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    // LinkTree tree;
    // ExploreDirectory("../",tree.GetRoot());
    // tree.show();

    std::string path;
    if (argc < 2)
        path = "./";
    else
        path = argv[1];
    LinkTree tree;
    ExploreDirectory(path, tree.GetRoot());
    // tree.show();

    struct stat s;
    stat("./", &s);
    std::cout << "文件大小:" << s.st_size << std::endl;

    // if(argc >= 3)
    // {
    //     std::cout<<"argv2:"<<argv[2]<<std::endl;
    //     Find(tree,argv[2]);
    // }
    // else
    // {
    //     std::cout<<"未输入查找的文件名!\n";
    // }
    // return 0;

    // DARRAY::DynamicArray a = tree.FindByElement("1");
    // for(int i =0;i<a.Size(); i++)
    // {
    //     std::cout<<tree.GetNodePath((TreeNode*)a[i])<<std::endl;
    // }

    return 0;
}