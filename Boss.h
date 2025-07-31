//
// Created by 💫Pym on 25-7-31.
//

#ifndef BOSS_H
#define BOSS_H

#include <iostream>
#include "Worker.h"

//老板类
class Boss : public Worker {
public:
    // 构造函数
    Boss(int id, std::string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual std::string getDeptName();
};

#endif //BOSS_H
