/**
 * 实验：内存管理训练营
 * 主题：内存与指针
 *
 * 学生姓名：___________
 * 学号：_______________
 * 完成日期：___________
 *
 * 实验说明：
 * 本实验旨在帮助你深入理解C++中的指针和内存管理。
 * 请按照TODO注释的提示完成各个任务函数。
 *
 * 编译命令：g++ -std=c++11 -Wall -o memory_lab submit.cpp
 */

#include <iostream>
#include <iomanip>
using namespace std;

// ==================== 任务5所需的结构体 ====================

/**
 * 动态数组结构体
 * 用于管理动态分配的整型数组
 */
struct DynamicArray {
    int* data;      // 指向动态分配的数组
    int size;       // 数组当前大小
    int capacity;   // 数组容量
};

// ==================== 函数声明 ====================

// 任务函数
void pointerBasics();           // 任务1
void pointerArrayTraversal();   // 任务2
void pointerArithmetic();       // 任务3
void multiLevelPointer();       // 任务4
void dynamicMemoryDemo();       // 任务5
void constPointerDemo();        // 任务6
void memorySafetyDemo();        // 任务7

// 任务5辅助函数
DynamicArray* createArray(int size);
void initArray(DynamicArray* arr);
void printArray(const DynamicArray* arr);
void resizeArray(DynamicArray* arr, int newSize);
void destroyArray(DynamicArray* arr);

// 任务7辅助函数
void safeDelete(int*& ptr);
void safeDeleteArray(int*& ptr);

// ==================== 主函数 ====================

int main() {
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║       内存管理训练营 - 实验报告        ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << endl;

    // 执行各任务
    pointerBasics();
    cout << endl;

    pointerArrayTraversal();
    cout << endl;

    pointerArithmetic();
    cout << endl;

    multiLevelPointer();
    cout << endl;

    dynamicMemoryDemo();
    cout << endl;

    constPointerDemo();
    cout << endl;

    memorySafetyDemo();
    cout << endl;

    cout << "════════════════════════════════════════" << endl;
    cout << "所有任务执行完毕！" << endl;
    cout << "════════════════════════════════════════" << endl;

    return 0;
}

// ==================== 任务1：指针基础操作 ====================

/**
 * 任务1：指针基础操作（15分）
 *
 * 要求：
 * 1. 定义一个整型变量value并初始化为42
 * 2. 定义一个指针ptr指向value
 * 3. 输出value的值和地址
 * 4. 通过指针输出地址和值
 * 5. 通过指针将value修改为100
 * 6. 验证修改结果
 */
void pointerBasics() {
    cout << "=== 任务1: 指针基础操作 ===" << endl;

    // TODO: 定义整型变量value，初始化为42


    // TODO: 定义指针ptr，指向value


    // TODO: 输出value的值
    // cout << "变量value的值: " << ... << endl;

    // TODO: 输出value的地址（使用&运算符）
    // cout << "变量value的地址: " << ... << endl;

    // TODO: 输出ptr的值（即它存储的地址）
    // cout << "指针ptr的值(地址): " << ... << endl;

    // TODO: 输出ptr指向的值（使用*运算符）
    // cout << "指针ptr指向的值: " << ... << endl;

    // TODO: 通过指针修改value为100


    // TODO: 输出修改后的value值
    // cout << "通过指针修改后，value的值: " << ... << endl;
}

// ==================== 任务2：指针与数组遍历 ====================

/**
 * 任务2：指针与数组遍历（15分）
 *
 * 要求：
 * 1. 创建包含{10, 20, 30, 40, 50}的数组
 * 2. 使用指针遍历数组，输出每个元素的值和地址
 * 3. 计算所有元素的和
 * 4. 找出最大值及其索引
 */
void pointerArrayTraversal() {
    cout << "=== 任务2: 指针与数组遍历 ===" << endl;

    // TODO: 定义数组arr，包含5个元素: 10, 20, 30, 40, 50
    int arr[5] = {10, 20, 30, 40, 50};

    // 输出数组元素
    cout << "数组元素: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // TODO: 使用指针遍历数组
    cout << "使用指针遍历:" << endl;
    // 提示：定义指针ptr = arr，然后遍历
    // for (int* ptr = ...; ptr < ...; ptr++) {
    //     输出元素索引、值和地址
    // }


    // TODO: 计算数组元素之和
    int sum = 0;
    // 提示：使用指针遍历并累加


    cout << "数组元素之和: " << sum << endl;

    // TODO: 找出最大值及其位置
    int maxVal = arr[0];
    int maxIndex = 0;
    // 提示：使用指针遍历比较


    cout << "最大值: " << maxVal << ", 位置: " << maxIndex << endl;
}

// ==================== 任务3：指针算术运算 ====================

/**
 * 任务3：指针算术运算（15分）
 *
 * 要求：
 * 1. 创建数组并获取首地址
 * 2. 演示指针加法（ptr + n）
 * 3. 演示指针自增（ptr++, ++ptr）
 * 4. 演示指针相减（计算元素距离）
 * 5. 使用指针比较遍历数组
 */
void pointerArithmetic() {
    cout << "=== 任务3: 指针算术运算 ===" << endl;

    int arr[5] = {10, 20, 30, 40, 50};

    // TODO: 获取数组首地址
    // int* ptr = ...;

    // TODO: 输出数组首地址
    // cout << "数组首地址: " << ... << endl;

    // TODO: 演示指针加法，输出ptr+2指向的值
    // cout << "ptr + 2 指向的值: " << ... << endl;

    // TODO: 演示指针移动
    cout << "指针移动演示:" << endl;
    // 创建一个新指针用于演示
    // int* p = arr;
    // p++后指向什么？
    // p+=2后指向什么？


    // TODO: 演示指针相减
    // int* start = arr;
    // int* end = arr + 5;
    // 计算end - start


    // TODO: 使用指针比较遍历数组
    cout << "使用指针比较遍历: ";
    // for (int* p = arr; p < arr + 5; p++) { ... }

    cout << endl;
}

// ==================== 任务4：多级指针操作 ====================

/**
 * 任务4：多级指针操作（10分）
 *
 * 要求：
 * 1. 创建变量value = 100
 * 2. 创建指针ptr指向value
 * 3. 创建二级指针pptr指向ptr
 * 4. 输出各级指针的地址和值
 * 5. 通过二级指针修改value
 */
void multiLevelPointer() {
    cout << "=== 任务4: 多级指针操作 ===" << endl;

    // TODO: 定义变量value = 100


    // TODO: 定义一级指针ptr指向value


    // TODO: 定义二级指针pptr指向ptr


    // TODO: 输出value及其地址
    // cout << "value = " << value << ", 地址 = " << &value << endl;

    // TODO: 输出ptr指向的地址和值
    // cout << "ptr 指向 " << ptr << ", *ptr = " << *ptr << endl;

    // TODO: 输出pptr指向的地址和通过pptr访问的值
    // cout << "pptr 指向 " << pptr << ", **pptr = " << **pptr << endl;

    // TODO: 通过**pptr修改value为200
    // **pptr = 200;

    // TODO: 输出修改后的value
    // cout << "通过**pptr修改后, value = " << value << endl;
}

// ==================== 任务5：动态内存管理 ====================

/**
 * 创建动态数组
 * @param size 数组大小
 * @return 指向新创建的DynamicArray的指针
 */
DynamicArray* createArray(int size) {
    // TODO: 使用new创建DynamicArray结构体


    // TODO: 为data成员分配size个int的空间


    // TODO: 设置size和capacity


    // TODO: 返回创建的数组
    return nullptr;  // 修改这里
}

/**
 * 初始化数组
 * 将数组元素初始化为其索引值（0, 1, 2, ...）
 * @param arr 指向DynamicArray的指针
 */
void initArray(DynamicArray* arr) {
    // TODO: 检查arr是否为nullptr


    // TODO: 将每个元素初始化为其索引值
    // arr->data[i] = i;

}

/**
 * 打印数组
 * 格式：[0, 1, 2, 3, 4]
 * @param arr 指向DynamicArray的常量指针
 */
void printArray(const DynamicArray* arr) {
    // TODO: 检查arr是否为nullptr


    // TODO: 按格式输出数组内容
    // 格式: [元素1, 元素2, ...]

}

/**
 * 调整数组大小
 * @param arr 指向DynamicArray的指针
 * @param newSize 新的大小
 */
void resizeArray(DynamicArray* arr, int newSize) {
    // TODO: 检查arr是否为nullptr


    // TODO: 分配新的内存空间


    // TODO: 复制原有数据（注意边界）
    // 如果newSize > 原size，多出的部分初始化为0
    // 如果newSize < 原size，只复制newSize个元素


    // TODO: 释放原有内存


    // TODO: 更新arr的成员

}

/**
 * 销毁数组，释放内存
 * @param arr 指向DynamicArray的指针
 */
void destroyArray(DynamicArray* arr) {
    // TODO: 检查arr是否为nullptr


    // TODO: 释放data数组


    // TODO: 释放DynamicArray结构体

}

/**
 * 任务5：动态内存管理演示（20分）
 */
void dynamicMemoryDemo() {
    cout << "=== 任务5: 动态内存管理 ===" << endl;

    // TODO: 创建大小为5的动态数组
    cout << "创建大小为5的动态数组" << endl;


    // TODO: 初始化数组


    // TODO: 打印数组
    cout << "数组内容: ";

    cout << endl;

    // TODO: 调整大小为8
    cout << "调整大小为8" << endl;


    // TODO: 打印数组
    cout << "数组内容: ";

    cout << endl;

    // TODO: 调整大小为3
    cout << "调整大小为3" << endl;


    // TODO: 打印数组
    cout << "数组内容: ";

    cout << endl;

    // TODO: 释放内存
    cout << "释放内存完成" << endl;

}

// ==================== 任务6：const指针详解 ====================

/**
 * 任务6：const指针详解（10分）
 *
 * 要求：
 * 1. 演示指向常量的指针 (const int*)
 * 2. 演示常量指针 (int* const)
 * 3. 演示指向常量的常量指针 (const int* const)
 */
void constPointerDemo() {
    cout << "=== 任务6: const指针详解 ===" << endl;

    int a = 10, b = 20;
    int c = 30;
    int d = 50;

    // 1. 指向常量的指针
    cout << "\n1. 指向常量的指针 (const int* p):" << endl;
    // TODO: 定义 const int* p1 指向a
    // const int* p1 = ...;

    // TODO: 输出初始值
    // cout << "   初始值: " << *p1 << endl;

    // TODO: 改变p1的指向，让它指向b
    // p1 = &b;

    // TODO: 输出改变指向后的值
    // cout << "   改变指向后: " << *p1 << endl;

    cout << "   (不能通过指针修改值，但可以改变指向)" << endl;

    // 2. 常量指针
    cout << "\n2. 常量指针 (int* const p):" << endl;
    // TODO: 定义 int* const p2 指向c
    // int* const p2 = ...;

    // TODO: 输出初始值
    // cout << "   初始值: " << *p2 << endl;

    // TODO: 通过p2修改c的值为40
    // *p2 = 40;

    // TODO: 输出修改后的值
    // cout << "   修改值后: " << *p2 << endl;

    cout << "   (可以修改值，但不能改变指向)" << endl;

    // 3. 指向常量的常量指针
    cout << "\n3. 指向常量的常量指针 (const int* const p):" << endl;
    // TODO: 定义 const int* const p3 指向d
    // const int* const p3 = ...;

    // TODO: 输出值
    // cout << "   值: " << *p3 << endl;

    cout << "   (既不能修改值，也不能改变指向)" << endl;
}

// ==================== 任务7：内存安全检查 ====================

/**
 * 安全删除函数
 * 删除指针指向的内存并将指针置为nullptr
 * @param ptr 指针的引用（注意是引用，才能修改原指针）
 */
void safeDelete(int*& ptr) {
    // TODO: 实现安全删除
    // 1. 检查ptr是否为nullptr
    // 2. 如果不是，delete ptr
    // 3. 将ptr设为nullptr

}

/**
 * 安全删除数组函数
 * @param ptr 数组指针的引用
 */
void safeDeleteArray(int*& ptr) {
    // TODO: 实现安全删除数组
    // 1. 检查ptr是否为nullptr
    // 2. 如果不是，delete[] ptr
    // 3. 将ptr设为nullptr

}

/**
 * 任务7：内存安全检查（15分）
 */
void memorySafetyDemo() {
    cout << "=== 任务7: 内存安全检查 ===" << endl;

    // 演示正确的内存管理流程
    cout << "\n正确的内存管理流程:" << endl;

    // TODO: 步骤1 - 分配内存
    cout << "1. 分配内存: ptr = new int(42)" << endl;
    // int* ptr = new int(42);

    // TODO: 步骤2 - 使用内存
    cout << "2. 使用内存: *ptr = " << /* *ptr */ 42 << endl;

    // TODO: 步骤3 - 释放内存
    cout << "3. 释放内存: delete ptr" << endl;
    // delete ptr;

    // TODO: 步骤4 - 置空指针
    cout << "4. 置空指针: ptr = nullptr" << endl;
    // ptr = nullptr;

    // 测试安全删除函数
    cout << "\n安全删除函数测试:" << endl;

    // TODO: 创建新指针
    // int* testPtr = new int(100);

    // TODO: 输出删除前状态
    // cout << "删除前: " << (testPtr != nullptr ? "ptr != nullptr" : "ptr == nullptr") << endl;

    // TODO: 调用safeDelete
    // safeDelete(testPtr);

    // TODO: 输出删除后状态
    // cout << "安全删除后: " << (testPtr == nullptr ? "ptr == nullptr" : "ptr != nullptr") << endl;

    // TODO: 再次调用safeDelete（测试对nullptr的安全性）
    // safeDelete(testPtr);
    // cout << "再次安全删除: 安全（对nullptr无操作）" << endl;

    // 动态数组的安全管理
    cout << "\n动态数组安全管理:" << endl;

    // TODO: 分配数组
    cout << "分配: arr = new int[5]" << endl;
    // int* arr = new int[5];

    // TODO: 初始化并输出
    cout << "初始化: ";
    // for (int i = 0; i < 5; i++) {
    //     arr[i] = i;
    //     cout << arr[i] << " ";
    // }
    cout << "0 1 2 3 4" << endl;  // 临时输出，完成TODO后删除

    // TODO: 安全释放数组
    cout << "释放: delete[] arr" << endl;
    // safeDeleteArray(arr);

    cout << "置空: arr = nullptr" << endl;
}
