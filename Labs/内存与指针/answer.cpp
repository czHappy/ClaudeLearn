/**
 * 实验：内存管理训练营
 * 主题：内存与指针
 *
 * 标准答案
 *
 * 编译命令：g++ -std=c++11 -Wall -o memory_lab answer.cpp
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
 * 演示：
 * - 指针的定义与初始化
 * - 取地址运算符 &
 * - 解引用运算符 *
 * - 通过指针修改变量
 */
void pointerBasics() {
    cout << "=== 任务1: 指针基础操作 ===" << endl;

    // 定义整型变量value，初始化为42
    int value = 42;

    // 定义指针ptr，指向value
    int* ptr = &value;

    // 输出value的值
    cout << "变量value的值: " << value << endl;

    // 输出value的地址（使用&运算符）
    cout << "变量value的地址: " << &value << endl;

    // 输出ptr的值（即它存储的地址）
    cout << "指针ptr的值(地址): " << ptr << endl;

    // 输出ptr指向的值（使用*运算符）
    cout << "指针ptr指向的值: " << *ptr << endl;

    // 通过指针修改value为100
    *ptr = 100;

    // 输出修改后的value值
    cout << "通过指针修改后，value的值: " << value << endl;
}

// ==================== 任务2：指针与数组遍历 ====================

/**
 * 任务2：指针与数组遍历（15分）
 *
 * 演示：
 * - 数组名作为指针
 * - 指针遍历数组
 * - 使用指针计算和查找
 */
void pointerArrayTraversal() {
    cout << "=== 任务2: 指针与数组遍历 ===" << endl;

    // 定义数组arr，包含5个元素
    int arr[5] = {10, 20, 30, 40, 50};

    // 输出数组元素
    cout << "数组元素: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 使用指针遍历数组
    cout << "使用指针遍历:" << endl;
    int index = 0;
    for (int* ptr = arr; ptr < arr + 5; ptr++) {
        cout << "  元素[" << index << "] = " << *ptr
             << ", 地址 = " << ptr << endl;
        index++;
    }

    // 计算数组元素之和
    int sum = 0;
    for (int* ptr = arr; ptr < arr + 5; ptr++) {
        sum += *ptr;
    }
    cout << "数组元素之和: " << sum << endl;

    // 找出最大值及其位置
    int maxVal = arr[0];
    int maxIndex = 0;
    int* maxPtr = arr;

    for (int* ptr = arr + 1; ptr < arr + 5; ptr++) {
        if (*ptr > *maxPtr) {
            maxPtr = ptr;
            maxVal = *ptr;
            maxIndex = ptr - arr;  // 计算索引
        }
    }
    cout << "最大值: " << maxVal << ", 位置: " << maxIndex << endl;
}

// ==================== 任务3：指针算术运算 ====================

/**
 * 任务3：指针算术运算（15分）
 *
 * 演示：
 * - 指针加减运算
 * - 指针自增自减
 * - 指针相减求距离
 * - 指针比较
 */
void pointerArithmetic() {
    cout << "=== 任务3: 指针算术运算 ===" << endl;

    int arr[5] = {10, 20, 30, 40, 50};

    // 获取数组首地址
    int* ptr = arr;

    // 输出数组首地址
    cout << "数组首地址: " << ptr << endl;

    // 演示指针加法，输出ptr+2指向的值
    cout << "ptr + 2 指向的值: " << *(ptr + 2) << endl;

    // 演示指针移动
    cout << "指针移动演示:" << endl;
    int* p = arr;
    p++;  // 移动到下一个元素
    cout << "  ptr++后指向: " << *p << endl;

    p += 2;  // 再移动2个位置
    cout << "  ptr+=2后指向: " << *p << endl;

    // 演示指针相减
    int* start = arr;
    int* end = arr + 5;
    ptrdiff_t distance = end - start;
    cout << "end - start = " << distance << " 个元素" << endl;

    // 使用指针比较遍历数组
    cout << "使用指针比较遍历: ";
    for (int* p = arr; p < arr + 5; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

// ==================== 任务4：多级指针操作 ====================

/**
 * 任务4：多级指针操作（10分）
 *
 * 演示：
 * - 一级指针
 * - 二级指针（指针的指针）
 * - 通过多级指针访问和修改值
 */
void multiLevelPointer() {
    cout << "=== 任务4: 多级指针操作 ===" << endl;

    // 定义变量value = 100
    int value = 100;

    // 定义一级指针ptr指向value
    int* ptr = &value;

    // 定义二级指针pptr指向ptr
    int** pptr = &ptr;

    // 输出value及其地址
    cout << "value = " << value << ", 地址 = " << &value << endl;

    // 输出ptr指向的地址和值
    cout << "ptr 指向 " << ptr << ", *ptr = " << *ptr << endl;

    // 输出pptr指向的地址和通过pptr访问的值
    cout << "pptr 指向 " << pptr << ", **pptr = " << **pptr << endl;

    // 通过**pptr修改value为200
    **pptr = 200;

    // 输出修改后的value
    cout << "通过**pptr修改后, value = " << value << endl;
}

// ==================== 任务5：动态内存管理 ====================

/**
 * 创建动态数组
 * @param size 数组大小
 * @return 指向新创建的DynamicArray的指针
 */
DynamicArray* createArray(int size) {
    // 使用new创建DynamicArray结构体
    DynamicArray* arr = new DynamicArray;

    // 为data成员分配size个int的空间
    arr->data = new int[size];

    // 设置size和capacity
    arr->size = size;
    arr->capacity = size;

    // 初始化为0
    for (int i = 0; i < size; i++) {
        arr->data[i] = 0;
    }

    return arr;
}

/**
 * 初始化数组
 * 将数组元素初始化为其索引值（0, 1, 2, ...）
 * @param arr 指向DynamicArray的指针
 */
void initArray(DynamicArray* arr) {
    // 检查arr是否为nullptr
    if (arr == nullptr || arr->data == nullptr) {
        return;
    }

    // 将每个元素初始化为其索引值
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = i;
    }
}

/**
 * 打印数组
 * 格式：[0, 1, 2, 3, 4]
 * @param arr 指向DynamicArray的常量指针
 */
void printArray(const DynamicArray* arr) {
    // 检查arr是否为nullptr
    if (arr == nullptr || arr->data == nullptr) {
        cout << "[空数组]";
        return;
    }

    // 按格式输出数组内容
    cout << "[";
    for (int i = 0; i < arr->size; i++) {
        cout << arr->data[i];
        if (i < arr->size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

/**
 * 调整数组大小
 * @param arr 指向DynamicArray的指针
 * @param newSize 新的大小
 */
void resizeArray(DynamicArray* arr, int newSize) {
    // 检查arr是否为nullptr
    if (arr == nullptr) {
        return;
    }

    // 分配新的内存空间
    int* newData = new int[newSize];

    // 复制原有数据（注意边界）
    int copySize = (newSize < arr->size) ? newSize : arr->size;
    for (int i = 0; i < copySize; i++) {
        newData[i] = arr->data[i];
    }

    // 如果newSize > 原size，多出的部分初始化为0
    for (int i = copySize; i < newSize; i++) {
        newData[i] = 0;
    }

    // 释放原有内存
    delete[] arr->data;

    // 更新arr的成员
    arr->data = newData;
    arr->size = newSize;
    arr->capacity = newSize;
}

/**
 * 销毁数组，释放内存
 * @param arr 指向DynamicArray的指针
 */
void destroyArray(DynamicArray* arr) {
    // 检查arr是否为nullptr
    if (arr == nullptr) {
        return;
    }

    // 释放data数组
    if (arr->data != nullptr) {
        delete[] arr->data;
        arr->data = nullptr;
    }

    // 释放DynamicArray结构体
    delete arr;
}

/**
 * 任务5：动态内存管理演示（20分）
 */
void dynamicMemoryDemo() {
    cout << "=== 任务5: 动态内存管理 ===" << endl;

    // 创建大小为5的动态数组
    cout << "创建大小为5的动态数组" << endl;
    DynamicArray* arr = createArray(5);

    // 初始化数组
    initArray(arr);

    // 打印数组
    cout << "数组内容: ";
    printArray(arr);
    cout << endl;

    // 调整大小为8
    cout << "调整大小为8" << endl;
    resizeArray(arr, 8);

    // 打印数组
    cout << "数组内容: ";
    printArray(arr);
    cout << endl;

    // 调整大小为3
    cout << "调整大小为3" << endl;
    resizeArray(arr, 3);

    // 打印数组
    cout << "数组内容: ";
    printArray(arr);
    cout << endl;

    // 释放内存
    destroyArray(arr);
    arr = nullptr;  // 防止悬空指针
    cout << "释放内存完成" << endl;
}

// ==================== 任务6：const指针详解 ====================

/**
 * 任务6：const指针详解（10分）
 *
 * 演示三种const与指针的组合：
 * 1. 指向常量的指针 (const int*)
 * 2. 常量指针 (int* const)
 * 3. 指向常量的常量指针 (const int* const)
 */
void constPointerDemo() {
    cout << "=== 任务6: const指针详解 ===" << endl;

    int a = 10, b = 20;
    int c = 30;
    int d = 50;

    // 1. 指向常量的指针
    cout << "\n1. 指向常量的指针 (const int* p):" << endl;
    const int* p1 = &a;
    cout << "   初始值: " << *p1 << endl;

    // 可以改变指向
    p1 = &b;
    cout << "   改变指向后: " << *p1 << endl;

    // 不能修改值: *p1 = 100; // 编译错误！
    cout << "   (不能通过指针修改值，但可以改变指向)" << endl;

    // 2. 常量指针
    cout << "\n2. 常量指针 (int* const p):" << endl;
    int* const p2 = &c;
    cout << "   初始值: " << *p2 << endl;

    // 可以修改值
    *p2 = 40;
    cout << "   修改值后: " << *p2 << endl;

    // 不能改变指向: p2 = &d; // 编译错误！
    cout << "   (可以修改值，但不能改变指向)" << endl;

    // 3. 指向常量的常量指针
    cout << "\n3. 指向常量的常量指针 (const int* const p):" << endl;
    const int* const p3 = &d;
    cout << "   值: " << *p3 << endl;

    // 既不能修改值，也不能改变指向
    // *p3 = 100;  // 编译错误！
    // p3 = &a;    // 编译错误！
    cout << "   (既不能修改值，也不能改变指向)" << endl;
}

// ==================== 任务7：内存安全检查 ====================

/**
 * 安全删除函数
 * 删除指针指向的内存并将指针置为nullptr
 * @param ptr 指针的引用（注意是引用，才能修改原指针）
 */
void safeDelete(int*& ptr) {
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}

/**
 * 安全删除数组函数
 * @param ptr 数组指针的引用
 */
void safeDeleteArray(int*& ptr) {
    if (ptr != nullptr) {
        delete[] ptr;
        ptr = nullptr;
    }
}

/**
 * 任务7：内存安全检查（15分）
 *
 * 演示：
 * - 正确的内存管理流程
 * - 避免悬空指针
 * - 安全删除函数的实现和使用
 */
void memorySafetyDemo() {
    cout << "=== 任务7: 内存安全检查 ===" << endl;

    // 演示正确的内存管理流程
    cout << "\n正确的内存管理流程:" << endl;

    // 步骤1 - 分配内存
    cout << "1. 分配内存: ptr = new int(42)" << endl;
    int* ptr = new int(42);

    // 步骤2 - 使用内存
    cout << "2. 使用内存: *ptr = " << *ptr << endl;

    // 步骤3 - 释放内存
    cout << "3. 释放内存: delete ptr" << endl;
    delete ptr;

    // 步骤4 - 置空指针
    cout << "4. 置空指针: ptr = nullptr" << endl;
    ptr = nullptr;

    // 测试安全删除函数
    cout << "\n安全删除函数测试:" << endl;

    // 创建新指针
    int* testPtr = new int(100);

    // 输出删除前状态
    cout << "删除前: " << (testPtr != nullptr ? "ptr != nullptr" : "ptr == nullptr") << endl;

    // 调用safeDelete
    safeDelete(testPtr);

    // 输出删除后状态
    cout << "安全删除后: " << (testPtr == nullptr ? "ptr == nullptr" : "ptr != nullptr") << endl;

    // 再次调用safeDelete（测试对nullptr的安全性）
    safeDelete(testPtr);
    cout << "再次安全删除: 安全（对nullptr无操作）" << endl;

    // 动态数组的安全管理
    cout << "\n动态数组安全管理:" << endl;

    // 分配数组
    cout << "分配: arr = new int[5]" << endl;
    int* arr = new int[5];

    // 初始化并输出
    cout << "初始化: ";
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;

    // 安全释放数组
    cout << "释放: delete[] arr" << endl;
    safeDeleteArray(arr);

    cout << "置空: arr = " << (arr == nullptr ? "nullptr" : "非空") << endl;
}
