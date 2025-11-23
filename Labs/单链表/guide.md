# 单链表实验指导书

## 实验主题：待办事项管理器

### 一、实验目的

1. 掌握单链表的基本概念和节点结构定义
2. 理解并实现链表的创建与初始化
3. 掌握头插法和尾插法建立链表
4. 实现链表的遍历、查找、插入和删除操作
5. 掌握链表反转算法
6. 学习正确的内存管理，防止内存泄漏

### 二、实验背景

待办事项管理是日常工作学习中的重要工具。本实验将实现一个基于单链表的任务管理系统，每个任务包含任务ID、任务描述和优先级信息。通过链表的动态特性，可以灵活地添加、删除和管理任务。

### 三、知识点详解

#### 3.1 节点结构定义

单链表由一系列节点组成，每个节点包含两部分：
- **数据域**：存储实际数据
- **指针域**：存储指向下一个节点的指针

```cpp
struct Node {
    int id;              // 任务ID
    string task;         // 任务描述
    int priority;        // 优先级（1-5）
    Node* next;          // 指向下一个节点的指针
};
```

#### 3.2 链表的创建与初始化

创建链表时需要：
1. 定义头指针（head），初始化为nullptr
2. 创建新节点时使用`new`运算符动态分配内存
3. 正确设置节点的数据域和指针域

```cpp
Node* head = nullptr;  // 空链表

// 创建新节点
Node* newNode = new Node;
newNode->id = 1;
newNode->task = "学习数据结构";
newNode->priority = 5;
newNode->next = nullptr;
```

#### 3.3 头插法与尾插法

**头插法**：新节点插入到链表头部
- 优点：插入效率高O(1)
- 缺点：插入顺序与输入顺序相反

```cpp
void insertAtHead(Node*& head, int id, string task, int priority) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->task = task;
    newNode->priority = priority;
    newNode->next = head;
    head = newNode;
}
```

**尾插法**：新节点插入到链表尾部
- 优点：保持输入顺序
- 缺点：需要遍历到尾部，效率O(n)

```cpp
void insertAtTail(Node*& head, int id, string task, int priority) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->task = task;
    newNode->priority = priority;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
```

#### 3.4 链表遍历

遍历链表需要从头节点开始，依次访问每个节点直到nullptr。

```cpp
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", 任务: " << temp->task
             << ", 优先级: " << temp->priority << endl;
        temp = temp->next;
    }
}
```

#### 3.5 节点查找

按照指定条件（如ID）查找节点，返回找到的节点指针。

```cpp
Node* findById(Node* head, int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;  // 未找到
}
```

#### 3.6 节点插入

根据不同位置有三种插入方式：

**1. 头部插入**：已在3.3节介绍

**2. 尾部插入**：已在3.3节介绍

**3. 中间插入**：在指定位置或节点后插入
```cpp
bool insertAfter(Node* prevNode, int id, string task, int priority) {
    if (prevNode == nullptr) {
        return false;
    }
    Node* newNode = new Node;
    newNode->id = id;
    newNode->task = task;
    newNode->priority = priority;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return true;
}
```

#### 3.7 节点删除

删除节点时需要注意：
1. 找到待删除节点的前驱节点
2. 修改前驱节点的next指针
3. 释放被删除节点的内存

```cpp
bool deleteNode(Node*& head, int id) {
    if (head == nullptr) return false;

    // 删除头节点
    if (head->id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // 删除其他节点
    Node* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        return false;  // 未找到
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return true;
}
```

#### 3.8 链表反转

反转链表是经典算法题，有迭代和递归两种方法。

**迭代法**：
```cpp
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // 保存下一个节点
        current->next = prev;  // 反转当前节点的指针
        prev = current;        // prev向后移动
        current = next;        // current向后移动
    }

    head = prev;  // 更新头指针
}
```

#### 3.9 内存管理与内存泄漏防范

动态分配的内存必须手动释放，否则会造成内存泄漏。

**正确的清理方法**：
```cpp
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```

**注意事项**：
- 每个`new`必须对应一个`delete`
- 删除单个节点后要记得释放内存
- 程序结束前清空整个链表
- 可以使用智能指针（如`shared_ptr`）自动管理内存

### 四、实验任务

#### 任务1：定义节点结构体（10分）
定义包含任务ID、任务描述、优先级和next指针的Node结构体。

#### 任务2：实现头插法建表（10分）
实现`insertAtHead`函数，在链表头部插入新任务。

#### 任务3：实现尾插法建表（10分）
实现`insertAtTail`函数，在链表尾部插入新任务。

#### 任务4：实现遍历打印（10分）
实现`printList`函数，输出所有任务的详细信息。

#### 任务5：实现查找功能（15分）
实现`findById`函数，根据任务ID查找并返回节点。

#### 任务6：实现插入操作（15分）
实现在指定节点后插入新任务的功能。

#### 任务7：实现删除操作（15分）
实现`deleteNode`函数，删除指定ID的任务并正确释放内存。

#### 任务8：实现链表反转（10分）
实现`reverseList`函数，反转整个任务链表。

#### 任务9：实现内存管理（5分）
实现`clearList`函数，清空整个链表并释放所有内存。

### 五、测试用例

#### 测试1：基本插入和遍历
```
操作序列：
1. 尾插法插入：ID=1, Task="完成数据结构作业", Priority=5
2. 尾插法插入：ID=2, Task="复习线性代数", Priority=4
3. 头插法插入：ID=3, Task="准备英语演讲", Priority=5
4. 遍历打印

预期输出：
ID: 3, 任务: 准备英语演讲, 优先级: 5
ID: 1, 任务: 完成数据结构作业, 优先级: 5
ID: 2, 任务: 复习线性代数, 优先级: 4
```

#### 测试2：查找功能
```
操作序列：
1. 在测试1的基础上查找ID=2的任务

预期输出：
找到任务：ID=2, 任务: 复习线性代数, 优先级: 4
```

#### 测试3：删除操作
```
操作序列：
1. 在测试1的基础上删除ID=1的任务
2. 遍历打印

预期输出：
删除成功
ID: 3, 任务: 准备英语演讲, 优先级: 5
ID: 2, 任务: 复习线性代数, 优先级: 4
```

#### 测试4：链表反转
```
操作序列：
1. 在测试3的基础上反转链表
2. 遍历打印

预期输出：
ID: 2, 任务: 复习线性代数, 优先级: 4
ID: 3, 任务: 准备英语演讲, 优先级: 5
```

#### 测试5：内存管理
```
操作序列：
1. 创建包含10个节点的链表
2. 清空链表
3. 验证head为nullptr

预期结果：
无内存泄漏，链表正确清空
```

### 六、提交要求

1. 完成`submit.cpp`中所有TODO标记的函数
2. 确保代码能够编译通过
3. 通过所有测试用例
4. 代码风格规范，有适当注释
5. 无内存泄漏（可使用valgrind等工具检测）

### 七、评分标准

| 项目 | 分值 | 说明 |
|------|------|------|
| 节点结构定义 | 10分 | 正确定义Node结构体 |
| 头插法 | 10分 | 正确实现头部插入 |
| 尾插法 | 10分 | 正确实现尾部插入 |
| 遍历打印 | 10分 | 正确遍历并格式化输出 |
| 查找功能 | 15分 | 正确实现ID查找 |
| 插入操作 | 15分 | 正确实现中间插入 |
| 删除操作 | 15分 | 正确删除节点并释放内存 |
| 链表反转 | 10分 | 正确实现链表反转 |
| 内存管理 | 5分 | 无内存泄漏 |
| **总分** | **100分** | |

### 八、常见错误与调试技巧

#### 常见错误：

1. **空指针解引用**
   ```cpp
   // 错误示例
   head->next = newNode;  // 如果head是nullptr会崩溃

   // 正确做法
   if (head != nullptr) {
       head->next = newNode;
   }
   ```

2. **内存泄漏**
   ```cpp
   // 错误示例
   head = newNode;  // 原来的链表丢失，造成内存泄漏

   // 正确做法
   clearList(head);  // 先清空
   head = newNode;
   ```

3. **删除节点后使用**
   ```cpp
   // 错误示例
   delete temp;
   cout << temp->data;  // 使用已删除的内存

   // 正确做法
   int data = temp->data;
   delete temp;
   cout << data;
   ```

#### 调试技巧：

1. **打印调试信息**
   ```cpp
   cout << "当前节点地址: " << temp << ", 值: " << temp->id << endl;
   ```

2. **检查边界条件**
   - 空链表
   - 单节点链表
   - 操作头节点
   - 操作尾节点

3. **使用断言**
   ```cpp
   assert(head != nullptr);  // 确保链表非空
   ```

### 九、扩展思考

1. 如何实现双向链表？
2. 如何实现循环链表？
3. 如何使用智能指针管理链表内存？
4. 如何实现链表的排序（按优先级）？
5. 如何合并两个有序链表？

### 十、参考资料

1. 《数据结构与算法分析》- Mark Allen Weiss
2. 《算法导论》- Thomas H. Cormen
3. C++ Reference: https://en.cppreference.com/
4. LeetCode链表专题：https://leetcode.com/tag/linked-list/

---

**祝你实验顺利！**
