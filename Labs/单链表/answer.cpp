/**
 * 单链表实验 - 待办事项管理器
 * 标准答案
 *
 * 本文件包含所有函数的完整实现，无内存泄漏。
 * 用于教师评分参考。
 */

#include <iostream>
#include <string>
using namespace std;

// ==================== 任务1：节点结构体定义 ====================
/**
 * Node结构体定义
 * 包含：
 * - id: 任务ID
 * - task: 任务描述
 * - priority: 优先级（1-5）
 * - next: 指向下一个节点的指针
 */
struct Node {
    int id;           // 任务ID
    string task;      // 任务描述
    int priority;     // 优先级（1-5，5最高）
    Node* next;       // 指向下一个节点的指针

    // 构造函数（可选，方便创建节点）
    Node(int _id = 0, const string& _task = "", int _priority = 0)
        : id(_id), task(_task), priority(_priority), next(nullptr) {}
};


// ==================== 任务2：头插法建表 ====================
/**
 * 在链表头部插入新节点
 * 时间复杂度：O(1)
 *
 * @param head 链表头指针的引用
 * @param id 任务ID
 * @param task 任务描述
 * @param priority 优先级
 */
void insertAtHead(Node*& head, int id, const string& task, int priority) {
    // 1. 创建新节点
    Node* newNode = new Node;

    // 2. 设置新节点的数据域
    newNode->id = id;
    newNode->task = task;
    newNode->priority = priority;

    // 3. 将新节点的next指向原头节点
    newNode->next = head;

    // 4. 更新头指针指向新节点
    head = newNode;
}


// ==================== 任务3：尾插法建表 ====================
/**
 * 在链表尾部插入新节点
 * 时间复杂度：O(n)，需要遍历到尾部
 *
 * @param head 链表头指针的引用
 * @param id 任务ID
 * @param task 任务描述
 * @param priority 优先级
 */
void insertAtTail(Node*& head, int id, const string& task, int priority) {
    // 1. 创建新节点
    Node* newNode = new Node;

    // 2. 设置新节点的数据域
    newNode->id = id;
    newNode->task = task;
    newNode->priority = priority;
    newNode->next = nullptr;  // 尾节点的next为空

    // 3. 如果链表为空，直接让head指向新节点
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // 4. 遍历到链表尾部
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // 5. 将尾节点的next指向新节点
    temp->next = newNode;
}


// ==================== 任务4：遍历打印 ====================
/**
 * 遍历并打印链表所有节点
 * 时间复杂度：O(n)
 *
 * @param head 链表头指针
 */
void printList(Node* head) {
    // 检查链表是否为空
    if (head == nullptr) {
        cout << "任务列表为空" << endl;
        return;
    }

    // 遍历链表并打印每个节点
    Node* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id
             << ", 任务: " << temp->task
             << ", 优先级: " << temp->priority << endl;
        temp = temp->next;
    }
}


// ==================== 任务5：查找功能 ====================
/**
 * 根据ID查找节点
 * 时间复杂度：O(n)
 *
 * @param head 链表头指针
 * @param id 要查找的任务ID
 * @return 找到返回节点指针，否则返回nullptr
 */
Node* findById(Node* head, int id) {
    // 从头节点开始遍历
    Node* temp = head;

    while (temp != nullptr) {
        // 比较每个节点的id
        if (temp->id == id) {
            return temp;  // 找到，返回节点指针
        }
        temp = temp->next;
    }

    return nullptr;  // 遍历完未找到
}


// ==================== 任务6：插入操作 ====================
/**
 * 在指定节点后插入新节点
 * 时间复杂度：O(1)
 *
 * @param prevNode 前驱节点指针
 * @param id 新任务ID
 * @param task 新任务描述
 * @param priority 新任务优先级
 * @return 插入成功返回true，否则返回false
 */
bool insertAfter(Node* prevNode, int id, const string& task, int priority) {
    // 1. 检查prevNode是否为空
    if (prevNode == nullptr) {
        return false;
    }

    // 2. 创建新节点并设置数据
    Node* newNode = new Node;
    newNode->id = id;
    newNode->task = task;
    newNode->priority = priority;

    // 3. 新节点的next指向prevNode的下一个节点
    newNode->next = prevNode->next;

    // 4. prevNode的next指向新节点
    prevNode->next = newNode;

    return true;
}

/**
 * 在指定位置插入新节点（从0开始计数）
 * 时间复杂度：O(n)
 *
 * @param head 链表头指针的引用
 * @param position 插入位置（0表示插入到头部）
 * @param id 任务ID
 * @param task 任务描述
 * @param priority 优先级
 * @return 插入成功返回true，位置无效返回false
 */
bool insertAtPosition(Node*& head, int position, int id, const string& task, int priority) {
    // 位置不能为负数
    if (position < 0) {
        return false;
    }

    // 位置0表示头插
    if (position == 0) {
        insertAtHead(head, id, task, priority);
        return true;
    }

    // 找到position-1位置的节点
    Node* temp = head;
    int currentPos = 0;

    while (temp != nullptr && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    // 检查位置是否有效
    if (temp == nullptr) {
        return false;  // 位置超出链表长度
    }

    // 在temp后插入新节点
    return insertAfter(temp, id, task, priority);
}


// ==================== 任务7：删除操作 ====================
/**
 * 删除指定ID的节点
 * 时间复杂度：O(n)
 *
 * @param head 链表头指针的引用
 * @param id 要删除的任务ID
 * @return 删除成功返回true，未找到返回false
 */
bool deleteNode(Node*& head, int id) {
    // 1. 检查链表是否为空
    if (head == nullptr) {
        return false;
    }

    // 2. 如果要删除的是头节点
    if (head->id == id) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;  // 释放内存
        return true;
    }

    // 3. 查找待删除节点的前驱节点
    Node* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }

    // 4. 未找到待删除节点
    if (temp->next == nullptr) {
        return false;
    }

    // 5. 删除节点
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;  // 释放内存

    return true;
}


// ==================== 任务8：链表反转 ====================
/**
 * 反转链表（迭代法）
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 * @param head 链表头指针的引用
 */
void reverseList(Node*& head) {
    // 空链表或单节点链表无需反转
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* prev = nullptr;     // 前驱节点
    Node* current = head;     // 当前节点
    Node* next = nullptr;     // 后继节点

    while (current != nullptr) {
        // 1. 保存下一个节点
        next = current->next;

        // 2. 反转当前节点的指针
        current->next = prev;

        // 3. 移动prev和current
        prev = current;
        current = next;
    }

    // 4. 更新头指针
    head = prev;
}


// ==================== 任务9：内存管理 ====================
/**
 * 清空链表并释放所有内存
 * 时间复杂度：O(n)
 *
 * @param head 链表头指针的引用
 */
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;      // 保存当前节点
        head = head->next;      // 头指针后移
        delete temp;            // 删除当前节点
    }
    // 循环结束后head已经是nullptr
}

/**
 * 获取链表长度
 * 时间复杂度：O(n)
 *
 * @param head 链表头指针
 * @return 链表中节点的数量
 */
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;

    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    return length;
}


// ==================== 辅助函数 ====================

/**
 * 打印分隔线
 */
void printSeparator(const string& title) {
    cout << "\n========== " << title << " ==========\n";
}

/**
 * 判断链表是否为空
 * @param head 链表头指针
 * @return 空返回true，否则返回false
 */
bool isEmpty(Node* head) {
    return head == nullptr;
}

/**
 * 获取链表尾节点
 * @param head 链表头指针
 * @return 尾节点指针，空链表返回nullptr
 */
Node* getTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

/**
 * 复制链表（深拷贝）
 * @param head 原链表头指针
 * @return 新链表的头指针
 */
Node* copyList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // 创建新链表的头节点
    Node* newHead = new Node(head->id, head->task, head->priority);
    Node* newTail = newHead;
    Node* temp = head->next;

    // 复制剩余节点
    while (temp != nullptr) {
        Node* newNode = new Node(temp->id, temp->task, temp->priority);
        newTail->next = newNode;
        newTail = newNode;
        temp = temp->next;
    }

    return newHead;
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

    printSeparator("测试9：链表复制");
    Node* copiedList = copyList(taskList);
    cout << "原链表：" << endl;
    printList(taskList);
    cout << "复制的链表：" << endl;
    printList(copiedList);

    printSeparator("测试10：清空链表");
    clearList(taskList);
    cout << "原链表清空后：" << endl;
    printList(taskList);
    cout << "链表长度：" << getLength(taskList) << endl;

    // 清理复制的链表，避免内存泄漏
    clearList(copiedList);
    cout << "复制链表也已清空" << endl;

    printSeparator("所有测试完成");
    cout << "程序正常退出，无内存泄漏。" << endl;

    return 0;
}

/*
 * 预期输出：
 *
 * ========== 测试1：尾插法建表 ==========
 * 使用尾插法插入3个任务后：
 * ID: 1, 任务: 完成数据结构作业, 优先级: 5
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 *
 * ========== 测试2：头插法建表 ==========
 * 使用头插法在头部插入任务后：
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 1, 任务: 完成数据结构作业, 优先级: 5
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 *
 * ========== 测试3：查找功能 ==========
 * 找到任务：ID=2, 任务: 复习线性代数, 优先级: 4
 * 未找到ID为99的任务
 *
 * ========== 测试4：在指定节点后插入 ==========
 * 在ID=2的任务后插入新任务：
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 1, 任务: 完成数据结构作业, 优先级: 5
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 5, 任务: 购买学习资料, 优先级: 2
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 *
 * ========== 测试5：按位置插入 ==========
 * 在位置0插入任务后：
 * ID: 6, 任务: 早起跑步, 优先级: 4
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 1, 任务: 完成数据结构作业, 优先级: 5
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 5, 任务: 购买学习资料, 优先级: 2
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 * 在位置3插入任务后：
 * ID: 6, 任务: 早起跑步, 优先级: 4
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 1, 任务: 完成数据结构作业, 优先级: 5
 * ID: 7, 任务: 整理笔记, 优先级: 3
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 5, 任务: 购买学习资料, 优先级: 2
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 *
 * ========== 测试6：删除操作 ==========
 * 删除ID=1的任务：删除成功
 * ID: 6, 任务: 早起跑步, 优先级: 4
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 7, 任务: 整理笔记, 优先级: 3
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 5, 任务: 购买学习资料, 优先级: 2
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 *
 * 删除ID=99的任务：删除失败（任务不存在）
 *
 * ========== 测试7：链表长度 ==========
 * 当前任务数量：6
 *
 * ========== 测试8：链表反转 ==========
 * 反转前：
 * ID: 6, 任务: 早起跑步, 优先级: 4
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 7, 任务: 整理笔记, 优先级: 3
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 5, 任务: 购买学习资料, 优先级: 2
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 * 反转后：
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 * ID: 5, 任务: 购买学习资料, 优先级: 2
 * ID: 2, 任务: 复习线性代数, 优先级: 4
 * ID: 7, 任务: 整理笔记, 优先级: 3
 * ID: 4, 任务: 锻炼身体, 优先级: 3
 * ID: 6, 任务: 早起跑步, 优先级: 4
 *
 * ========== 测试9：链表复制 ==========
 * 原链表：
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 * ...
 * 复制的链表：
 * ID: 3, 任务: 准备英语演讲, 优先级: 5
 * ...
 *
 * ========== 测试10：清空链表 ==========
 * 原链表清空后：
 * 任务列表为空
 * 链表长度：0
 * 复制链表也已清空
 *
 * ========== 所有测试完成 ==========
 * 程序正常退出，无内存泄漏。
 */
