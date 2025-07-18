//
// Created by 💫Pym on 25-7-18.
//

#include "workerManager.h"

WorkerManager::WorkerManager() {

}

// 展示菜单
void WorkerManager::Show_Menu(){
    std::cout << "*********************************" << std::endl;
    std::cout << "******* 欢迎使用职工管理系统 *******" << std::endl;
    std::cout << "********* 0.退出管理程序 **********" << std::endl;
    std::cout << "********* 1.增加职工信息 **********" << std::endl;
    std::cout << "********* 2.显示职工信息 **********" << std::endl;
    std::cout << "********* 3.删除离职职工 **********" << std::endl;
    std::cout << "********* 4.修改职工信息 **********" << std::endl;
    std::cout << "********* 5.查找职工信息 **********" << std::endl;
    std::cout << "********* 6.按照编号排序 **********" << std::endl;
    std::cout << "********* 7.清空所有文档 **********" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << std::endl;
}

//析构函数
WorkerManager::~WorkerManager() {

}