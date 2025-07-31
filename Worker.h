//
// Created by 💫Pym on 25-7-23.
//

#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>

// 职工抽象类
class Worker {
public:
    // 显示个人信息
    virtual void showInfo() = 0;

    // 获取岗位名称
    virtual std::string getDeptName() = 0;

    virtual ~Worker() = default; // 不加会报错

    // 职工编号
    int m_Id;

    // 职工姓名
    std::string m_Name;

    // 部门编号
    int m_DeptId;
};


#endif //WORKER_H
