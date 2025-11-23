/**
 * 单链表实验 - 待办事项管理器
 * 学生提交模板
 *
 * 姓名：________________
 * 学号：________________
 * 日期：________________
 *
 * 实验说明：
 * 本实验实现一个基于单链表的待办事项管理系统。
 * 请完成所有标记为 TODO 的函数。
 */

#include <iostream>
#include <string>
using namespace std;

// ==================== 任务1：节点结构体定义 ====================
/**
 * TODO: 定义Node结构体
 * 要求：
 * - id: 任务ID (int类型)
 * - task: 任务描述 (string类型)
 * - priority: 优先级1-5 (int类型)
 * - next: 指向下一个节点的指针
 */
struct Node {
    // 请在此处定义成员变量


};


// ==================== 任务2：头插法建表 ====================
/**
 * 在链表头部插入新节点
 * @param head 链表头指针的引用
 * @param id 任务ID
 * @param task 任务描述
 * @param priority 优先级
 *
 * TODO: 实现头插法
 * 步骤：
 * 1. 创建新节点
 * 2. 设置新节点的数据域
 * 3. 将新节点的next指向原头节点
 * 4. 更新头指针指向新节点
 */
void insertAtHead(Node*& head, int id, const string& task, int priority) {
    // 请在此处实现


}


// ==================== 任务3：尾插法建表 ====================
/**
 * 在链表尾部插入新节点
 * @param head 链表头指针的引用
 * @param id 任务ID
 * @param task 任务描述
 * @param priority 优先级
 *
 * TODO: 实现尾插法
 * 步骤：
 * 1. 创建新节点
 * 2. 设置新节点的数据域，next设为nullptr
 * 3. 如果链表为空，直接让head指向新节点
 * 4. 否则遍历到链表尾部，将尾节点的next指向新节点
 */
void insertAtTail(Node*& head, int id, const string& task, int priority) {
    // 请在此处实现


}


// ==================== 任务4：遍历打印 ====================
/**
 * 遍历并打印链表所有节点
 * @param head 链表头指针
 *
 * TODO: 实现链表遍历
 * 输出格式：ID: x, 任务: xxx, 优先级: x
 * 每个任务占一行
 * 如果链表为空，输出"任务列表为空"
 */
void printList(Node* head) {
    // 请在此处实现


}


// ==================== 任务5：查找功能 ====================
/**
 * 根据ID查找节点
 * @param head 链表头指针
 * @param id 要查找的任务ID
 * @return 找到返回节点指针，否则返回nullptr
 *
 * TODO: 实现按ID查找
 * 步骤：
 * 1. 从头节点开始遍历
 * 2. 比较每个节点的id
 * 3. 找到则返回该节点指针
 * 4. 遍历完未找到返回nullptr
 */
Node* findById(Node* head, int id) {
    // 请在此处实现

    return nullptr;
}


// ==================== 任务6：插入操作 ====================
/**
 * 在指定节点后插入新节点
 * @param prevNode 前驱节点指针
 * @param id 新任务ID
 * @param task 新任务描述
 * @param priority 新任务优先级
 * @return 插入成功返回true，否则返回false
 *
 * TODO: 实现在指定节点后插入
 * 步骤：
 * 1. 检查prevNode是否为空
 * 2. 创建新节点并设置数据
 * 3. 新节点的next指向prevNode的next
 * 4. prevNode的next指向新节点
 */
bool insertAfter(Node* prevNode, int id, const string& task, int priority) {
    // 请在此处实现

    return false;
}

/**
 * 在指定位置插入新节点（从0开始计数）
 * @param head 链表头指针的引用
 * @param position 插入位置（0表示插入到头部）
 * @param id 任务ID
 * @param task 任务描述
 * @param priority 优先级
 * @return 插入成功返回true，位置无效返回false
 *
 * TODO: 实现按位置插入
 */
bool insertAtPosition(Node*& head, int position, int id, const string& task, int priority) {
    // 请在此处实现

    return false;
}


// ==================== 任务7：删除操作 ====================
/**
 * 删除指定ID的节点
 * @param head 链表头指针的引用
 * @param id 要删除的任务ID
 * @return 删除成功返回true，未找到返回false
 *
 * TODO: 实现删除指定节点
 * 步骤：
 * 1. 检查链表是否为空
 * 2. 如果要删除的是头节点，特殊处理
 * 3. 否则找到待删除节点的前驱节点
 * 4. 修改前驱节点的next指针
 * 5. 释放被删除节点的内存
 */
bool deleteNode(Node*& head, int id) {
    // 请在此处实现

    return false;
}


// ==================== 任务8：链表反转 ====================
/**
 * 反转链表
 * @param head 链表头指针的引用
 *
 * TODO: 实现链表反转
 * 使用迭代法：
 * 1. 使用三个指针：prev, current, next
 * 2. 遍历链表，逐个反转每个节点的next指针
 * 3. 最后更新头指针
 */
void reverseList(Node*& head) {
    // 请在此处实现


}


// ==================== 任务9：内存管理 ====================
/**
 * 清空链表并释放所有内存
 * @param head 链表头指针的引用
 *
 * TODO: 实现内存清理
 * 步骤：
 * 1. 遍历链表
 * 2. 保存下一个节点的指针
 * 3. 删除当前节点
 * 4. 最后将head设为nullptr
 */
void clearList(Node*& head) {
    // 请在此处实现


}

/**
 * 获取链表长度
 * @param head 链表头指针
 * @return 链表中节点的数量
 *
 * TODO: 实现获取链表长度
 */
int getLength(Node* head) {
    // 请在此处实现

    return 0;
}


// ==================== 辅助函数（已实现）====================

/**
 * 打印分隔线
 */
void printSeparator(const string& title) {
    cout << "\n========== " << title << " ==========\n";
}


// ==================== 主函数（测试代码）====================
int main() {
    Node* taskList = nullptr;

    printSeparator("测试1：尾插法建表");
    insertAtTail(taskList, 1, "完成数据结构作业", 5);
    insertAtTail(taskList, 2, "复习线性代数", 4);
    insertAtTail(taskList, 3, "准备英语演讲", 5);
    cout << "使用尾插法插入3个任务后：" << endl;
    printList(taskList);

    printSeparator("测试2：头插法建表");
    insertAtHead(taskList, 4, "锻炼身体", 3);
    cout << "使用头插法在头部插入任务后：" << endl;
    printList(taskList);

    printSeparator("测试3：查找功能");
    Node* found = findById(taskList, 2);
    if (found != nullptr) {
        cout << "找到任务：ID=" << found->id
             << ", 任务: " << found->task
             << ", 优先级: " << found->priority << endl;
    } else {
        cout << "未找到ID为2的任务" << endl;
    }

    found = findById(taskList, 99);
    if (found != nullptr) {
        cout << "找到任务：ID=" << found->id << endl;
    } else {
        cout << "未找到ID为99的任务" << endl;
    }

    printSeparator("测试4：在指定节点后插入");
    Node* task2 = findById(taskList, 2);
    if (task2 != nullptr) {
        insertAfter(task2, 5, "购买学习资料", 2);
        cout << "在ID=2的任务后插入新任务：" << endl;
        printList(taskList);
    }

    printSeparator("测试5：按位置插入");
    insertAtPosition(taskList, 0, 6, "早起跑步", 4);
    cout << "在位置0插入任务后：" << endl;
    printList(taskList);

    insertAtPosition(taskList, 3, 7, "整理笔记", 3);
    cout << "在位置3插入任务后：" << endl;
    printList(taskList);

    printSeparator("测试6：删除操作");
    cout << "删除ID=1的任务：";
    if (deleteNode(taskList, 1)) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
    }
    printList(taskList);

    cout << "\n删除ID=99的任务：";
    if (deleteNode(taskList, 99)) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败（任务不存在）" << endl;
    }

    printSeparator("测试7：链表长度");
    cout << "当前任务数量：" << getLength(taskList) << endl;

    printSeparator("测试8：链表反转");
    cout << "反转前：" << endl;
    printList(taskList);
    reverseList(taskList);
    cout << "反转后：" << endl;
    printList(taskList);

    printSeparator("测试9：清空链表");
    clearList(taskList);
    cout << "清空后：" << endl;
    printList(taskList);
    cout << "链表长度：" << getLength(taskList) << endl;

    printSeparator("所有测试完成");

    return 0;
}
