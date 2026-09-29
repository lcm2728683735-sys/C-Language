# 最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名
project(MyMagicTower)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 添加可执行文件（手动列文件，更清晰）
add_executable(MyMagicTower
    main.cpp
    ECS/Entity.cpp
    ECS/World.cpp
    System/MovementSystem.cpp
    System/InputSystem.cpp
    System/PlayerSystem.cpp
    # ... 其他 .cpp
)


# 添加头文件目录
target_include_directories(MyMagicTower PRIVATE ${CMAKE_SOURCE_DIR})

# 链接库（以后如果用到 pthread 等）
# target_link_libraries(MyMagicTower pthread)