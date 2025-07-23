#include <iostream>
#include "workerManager.h"

int main() {
    // 实例化管理者对象
    WorkerManager wm;

    int choice = 0; // 用来存储用户的选项

    while (true) {
        // 调用展示菜单成员函数
        wm.Show_Menu();

        std::cout << "请选择你的操作：" << std::endl;
        std::cin >> choice;;

        switch (choice) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                break;
        }
    }

    std::cout << "Press Enter to continue...";
    std::cin.get();

    return 0;
}
