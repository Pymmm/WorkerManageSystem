#include <iostream>
#include "workerManager.h"

int main() {
    // 实例化管理者对象
    WorkerManager wm;

    // 调用展示菜单成员函数
    wm.Show_Menu();

    std::cout << "Press Enter to continue...";
    std::cin.get();

    return 0;
}
