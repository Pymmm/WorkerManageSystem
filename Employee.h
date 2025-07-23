//
// Created by 💫Pym on 25-7-23.
// 普通员工文件
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Worker.h"

class Employee : public Worker {
public:
    // 构造函数
    Employee(int id, std::string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual std::string getDeptName();
};

#endif //EMPLOYEE_H
