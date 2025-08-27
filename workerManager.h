//
// Created by 💫Pym on 25-7-18.
//
// 防止头文件重复包含
#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include <iostream> // 包含输入输出流头文件
#include "Worker.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
#define FILENAME "./empFile.txt"

class WorkerManager {
public:
    // 构造函数
    WorkerManager();

    // 显示菜单
    void Show_Menu();

    // 退出系统
    void ExitSystem();

    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker ** m_EmpArray;

    // 添加职工
    void Add_Emp();

    // 保存文件
    void save();

    // 析构函数
    ~WorkerManager();
};


#endif //WORKERMANAGER_H
