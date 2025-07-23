//
// Created by 💫Pym on 25-7-18.
//
// 防止头文件重复包含
#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include <iostream> // 包含输入输出流头文件

class WorkerManager {
public:
    // 构造函数
    WorkerManager();

    // 显示菜单
    void Show_Menu();

    // 退出系统
    void ExitSystem();

    // 析构函数
    ~WorkerManager();
};


#endif //WORKERMANAGER_H
