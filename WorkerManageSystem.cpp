#include <iostream>
#include "workerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
    // // 测试代码
    // Worker * worker = nullptr;
    // worker = new Employee(1, "张三", 1);
    // worker->showInfo();
    // delete worker;
    //
    // worker = new Manager(2, "李四", 2);
    // worker->showInfo();
    // delete worker;
    //
    // worker = new Boss(3, "王五", 3);
    // worker->showInfo();
    // delete worker;

    // 实例化管理者对象
    WorkerManager wm;

    int choice = 0; // 用来存储用户的选项

    while (true) {
        // 调用展示菜单成员函数
        wm.Show_Menu();

        std::cout << "请选择你的操作：" << std::endl;
        std::cin >> choice; // 接受用户的选项

        switch (choice) {
            case 0: // 退出系统
                wm.ExitSystem();
                break;
            case 1: // 添加职工
                wm.Add_Emp();
                break;
            case 2: // 显示职工
                wm.Show_Emp();
                break;
            case 3: // 删除职工
                wm.Del_Emp();
                break;
            case 4: // 修改职工
                break;
            case 5: // 查找职工
                break;
            case 6: // 排序职工
                break;
            case 7: // 清空文件
                break;
            default:
                system("clear"); // 清屏
                break;
        }
    }

    std::cout << "Press Enter to continue...";
    std::cin.get();

    return 0;
}
