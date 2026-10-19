cmake_minimum_required(VERSION 3.10)

project(MyIPCLib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MyIPCLib SHARED

StdFIFO.cpp
StdMsgQueue.cpp
StdSem.cpp
StdShrdMem.cpp
)

target_include_directories(MyIPCLib PUBLIC .)

# target_link_libraries()  # 链接文件

set(CMAKE_INSTALL_PREFIX "/usr/local")

install(TARGETS MyIPCLib DESTINATION lib)

install(FILES
    StdFIFO.h
    StdMsgQueue.h
    StdSem.h
    StdShrdMem.h
    DESTINATION include
)