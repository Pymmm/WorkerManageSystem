cmake_minimum_required(VERSION 3.30)
project(基于多态的职工管理系统)

set(CMAKE_CXX_STANDARD 20)

add_executable(WorkerManageSystem
        WorkerManageSystem.cpp
        workerManager.cpp
        Employee.cpp
        Manager.cpp
        Boss.cpp
)
