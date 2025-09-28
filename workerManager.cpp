#include "workerManager.h"

#include "Employee.h"

WorkerManager::WorkerManager() {
    // 1.文件不存在
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in); // 读文件
    if (!ifs.is_open()) {
        // 测试代码
        // std::cout << "文件不存在" << std::endl;
        // 初始化属性
        this->m_EmpNum = 0; // 初始化记录人数为0
        this->m_EmpArray = nullptr; // 初始化数组指针为空
        this->m_FileIsEmpty = true; // 初始化文件为空
        ifs.close();
        return;
    }

    // 2.文件存在 数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        // 文件为空(测试代码)
        // std::cout << "文件为空" << std::endl;
        // 初始化属性
        this->m_EmpNum = 0; // 初始化记录人数为0
        this->m_EmpArray = nullptr; // 初始化数组指针为空
        this->m_FileIsEmpty = true; // 初始化文件为空
        ifs.close();
        return;
    }

    // 3.文件存在，并且记录数据
    int num = this->get_EmpNum();
    // 测试代码
    // std::cout << "职工人数为：" << num << "人" << std::endl;
    this->m_EmpNum = num;

    // 开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 将文件中的数据，存到数组中
    this->init_Emp();

    // 测试代码
    // for (int i = 0; i < this->m_EmpNum; i++) {
    //     std::cout << "职工编号：" << this->m_EmpArray[i]->m_Id
    //             << " 姓名：" << this->m_EmpArray[i]->m_Name
    //             << " 部门编号：" << this->m_EmpArray[i]->m_DeptId << std::endl;
    // }
}

// 展示菜单
void WorkerManager::Show_Menu() {
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

// 退出系统
void WorkerManager::ExitSystem() {
    std::cout << "欢迎下次使用" << std::endl;
    system("pause");
    exit(0); // 退出程序
}

// 添加员工
void WorkerManager::Add_Emp() {
    std::cout << "输入添加职工数量：" << std::endl;
    int addNum = 0; // 保存用户的输入数量
    std::cin >> addNum;
    if (addNum > 0) {
        // 添加
        // 计算添加新空间的大小
        int newSize = this->m_EmpNum + addNum; // 新空间大小 = 原来记录人数 + 新增人数

        // 开辟新空间
        Worker ** newSpace = new Worker *[newSize];

        // 将原来空间下的数据，拷贝到新空间下
        if (this->m_EmpArray != nullptr) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 批量添加新数据
        for (int i = 0; i < addNum; i++) {
            int id; // 职工编号
            std::string name; // 职工姓名
            int dSelect; // 部门选择

            std::cout << "请输入第" << i + 1 << "个新职工编号：" << std::endl;
            std::cin >> id;

            std::cout << "请输入第" << i + 1 << "个新职工姓名：" << std::endl;
            std::cin >> name;

            std::cout << "请选择该职工岗位：" << std::endl;
            std::cout << "1.普通职工" << std::endl;
            std::cout << "2.经理" << std::endl;
            std::cout << "3.老板" << std::endl;
            std::cin >> dSelect;

            Worker * worker = nullptr;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            // 将创建职工指针，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }
        // 释放原来空间（该对象中m_EmpArray指针指向的动态数组内存）
        delete [] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的职工人数
        this->m_EmpNum = newSize;

        // 更新职工不为空的标志
        this->m_FileIsEmpty = false;

        // 提示添加成功
        std::cout << "成功添加" << addNum << "名新职工" << std::endl;

        // 保存数据到文件中
        this->save();
    } else {
        std::cout << "输入数据有误" << std::endl;
    }

    Clear();
}

// 保存文件
void WorkerManager::save() {
    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::out); // 用输出的方式打开文件（写文件）

    // 将每个人的数据写入到文件中
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "
                << this->m_EmpArray[i]->m_Name << " "
                << this->m_EmpArray[i]->m_DeptId << std::endl;
    }

    // 关闭文件
    ofs.close();
}

// 统计文件中人数
int WorkerManager::get_EmpNum() {
    std::fstream ifs;
    ifs.open(FILENAME, std::ios::in); // 打开文件 读

    int id;
    std::string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {
        // 统计人数变量
        num++;
    }
    return num;
}

// 初始化员工
void WorkerManager::init_Emp() {
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);

    int id;
    std::string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker * worker = nullptr;

        // 普通员工
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        }
        // 经理
        else if (dId == 2) {
            worker = new Manager(id, name, dId);
        }
        // 老板
        else {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

    // 关闭文件
    ifs.close();
}

// 显示职工
void WorkerManager::Show_Emp() {
    // 判断文件是否为空
    if (this->m_FileIsEmpty) {
        std::cout << "文件不存在或记录为空！" << std::endl;
    } else {
        for (int i = 0; i < m_EmpNum; i++) {
            // 利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    Clear();
}

// 删除职工
void WorkerManager::Del_Emp() {
    if (this->m_FileIsEmpty) {
        std::cout << "文件不存在或记录为空！" << std::endl;
    } else {
        // 按照职工编号删除
        std::cout << "请输入要删除的职工编号：" << std::endl;
        int id = 0;
        std::cin >> id;
        int index = this->IsExist(id);
        if (index != -1) {
            // 说明职工存在，并且要删除掉index位置上的职工
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                // 数据前移(覆盖)
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--; // 更新数组中记录人员个数
            // 数据同步更新到文件中
            this->save();
            std::cout << "删除成功！" << std::endl;
        } else {
            std::cout << "删除失败，未找到该职工" << std::endl;
        }
    }

    Clear();
}

// 判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->get_EmpNum(); i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            // 找到职工
            index = i;
            break;
        }
    }
    return index;
}

// 按任意键清屏
void WorkerManager::Clear() {
    // 按任意键后 清屏回到上级目录
    std::cout << "按任意键后,清屏回到上级目录";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("clear");
}

// 析构函数
WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != nullptr) {
        delete [] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}
