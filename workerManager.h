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

    // 判断文件是否为空 标志
    bool m_FileIsEmpty;

    // 统计文件中人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示所有职工信息
    void Show_Emp();

    // 删除职工
    void Del_Emp();

    // 判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
    int IsExist(int id);

    // 按任意键清屏
    void Clear();

    // 析构函数
    ~WorkerManager();
};
#endif //WORKERMANAGER_H
