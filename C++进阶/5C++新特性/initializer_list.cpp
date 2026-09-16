#include <iostream>
#include <vector>
#include <initializer_list>//列表初始化
#include <memory>

std::vector<std::vector<std::unique_ptr<int>>> func()
{
    return {};
}

int main ()
{
    std::vector<int> v = {1,2,3,4,5};
    std::pair<int ,int> p = {0,0};
    return 0;
}