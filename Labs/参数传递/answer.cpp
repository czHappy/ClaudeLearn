/**
 * 实验: 数据交换中心 - 标准答案
 * 主题: 参数传递 (Pass by Value/Reference/Pointer)
 *
 * 学习目标:
 * 1. 理解值传递、引用传递、指针传递的区别
 * 2. 掌握数组作为参数的传递方式
 * 3. 学会根据需求选择合适的参数传递方式
 * 4. 理解大对象传递的性能考虑
 */

#include <iostream>
#include <algorithm>  // for std::sort
using namespace std;

// ==================== 任务1: 值传递演示 ====================
/**
 * 值传递函数 - 演示无法修改原变量
 * 参数: int x - 使用值传递（传递的是副本）
 * 说明: 函数内修改x，不影响原变量
 */
void tryModifyByValue(int x) {
    x++;  // 只修改副本，不影响原变量
    cout << "函数内部: " << x << endl;
}

// ==================== 任务2: 引用传递 - swap函数 ====================
/**
 * 引用传递的交换函数
 * 参数: int& a, int& b - 使用引用传递（直接操作原变量）
 * 优点: 语法简洁，效率高，安全
 */
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ==================== 任务3: 指针传递 - swap函数 ====================
/**
 * 指针传递的交换函数
 * 参数: int* a, int* b - 使用指针传递（传递地址）
 * 注意: 需要检查指针有效性
 */
void swapByPointer(int* a, int* b) {
    // 检查指针是否为空
    if (a == nullptr || b == nullptr) {
        cout << "错误: 指针为空!" << endl;
        return;
    }

    // 通过解引用交换值
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ==================== 任务4: 数组参数传递 ====================
/**
 * 数组求和函数
 * 参数: int arr[] - 数组（实际是指针）
 *       int size - 数组大小（必须额外传递）
 * 返回: 数组元素的总和
 * 说明: 数组名退化为指针，大小信息丢失
 */
int arraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

/**
 * 数组反转函数
 * 参数: int arr[] - 数组
 *       int size - 数组大小
 * 方法: 双指针法，原地反转
 */
void arrayReverse(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        // 交换两端元素
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // 指针向中间移动
        left++;
        right--;
    }
}

/**
 * 数组排序函数
 * 参数: int arr[] - 数组
 *       int size - 数组大小
 * 方法: 使用STL的sort函数（快速排序）
 */
void arraySort(int arr[], int size) {
    // sort需要首尾迭代器
    // arr是首地址，arr + size是尾地址
    sort(arr, arr + size);
}

// ==================== 任务5: 三种方式对比 ====================
/**
 * 值传递版本 - 无法修改原变量
 */
void incrementByValue(int x) {
    x++;
    // 修改的只是副本，原变量不变
}

/**
 * 引用传递版本 - 可以修改原变量
 */
void incrementByReference(int& x) {
    x++;
    // 直接修改原变量
}

/**
 * 指针传递版本 - 可以修改原变量
 */
void incrementByPointer(int* x) {
    if (x != nullptr) {
        (*x)++;  // 通过解引用修改原变量
    }
}

// ==================== 任务6: 大对象传递策略 ====================
/**
 * 大型数据块结构体
 * 用于演示不同传递方式的性能差异
 */
struct DataBlock {
    int data[1000];  // 大数组，约4KB

    // 构造函数
    DataBlock() {
        cout << "  [DataBlock构造函数被调用]" << endl;
        for (int i = 0; i < 1000; i++) {
            data[i] = i;
        }
    }

    // 拷贝构造函数 - 用于追踪拷贝行为
    DataBlock(const DataBlock& other) {
        cout << "  [DataBlock拷贝构造函数被调用 - 发生了拷贝!]" << endl;
        for (int i = 0; i < 1000; i++) {
            data[i] = other.data[i];
        }
    }
};

/**
 * 值传递处理大对象 - 会发生拷贝（低效）
 * 缺点: 拷贝4KB数据，开销大
 */
int processDataByValue(DataBlock block) {
    return block.data[0];
}

/**
 * 引用传递处理大对象 - 不拷贝（高效）
 * 优点: 无拷贝开销，可以修改
 */
int processDataByReference(DataBlock& block) {
    return block.data[0];
}

/**
 * 常量引用传递处理大对象 - 不拷贝且只读（推荐）
 * 优点: 无拷贝开销，保证不修改，安全且高效
 * 最佳实践: 传递大对象时优先使用const引用
 */
int processDataByConstReference(const DataBlock& block) {
    // 只能读取，不能修改
    // block.data[0] = 100;  // 编译错误
    return block.data[0];
}

// ==================== 任务7: 引用与指针的选择 ====================
/**
 * 查找数组最大值 - 使用引用返回
 * 返回: 最大值的引用
 * 优点: 可以直接修改数组中的最大值
 * 使用场景: 确定有返回值时
 */
int& findMax(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return arr[maxIndex];  // 返回引用
}

/**
 * 查找指定元素 - 使用指针返回
 * 返回: 找到返回指针，找不到返回nullptr
 * 优点: 可以表示"未找到"的情况
 * 使用场景: 可能无返回值时
 */
int* findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return &arr[i];  // 找到，返回地址
        }
    }
    return nullptr;  // 未找到
}

// ==================== 辅助函数 ====================
/**
 * 打印数组
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

// ==================== 主函数 ====================
int main() {
    cout << "=== 数据交换中心系统 ===" << endl << endl;

    // ========== 任务1测试: 值传递演示 ==========
    cout << "--- 任务1: 值传递演示 ---" << endl;
    int value1 = 10;
    cout << "修改前: " << value1 << endl;
    tryModifyByValue(value1);
    cout << "修改后: " << value1 << " (";
    if (value1 == 10) {
        cout << "未改变)";
    } else {
        cout << "已改变)";
    }
    cout << endl << endl;

    // ========== 任务2测试: 引用传递swap ==========
    cout << "--- 任务2: 引用传递 swap ---" << endl;
    int a2 = 3, b2 = 7;
    cout << "交换前: a=" << a2 << ", b=" << b2 << endl;
    swapByReference(a2, b2);
    cout << "交换后: a=" << a2 << ", b=" << b2 << endl << endl;

    // ========== 任务3测试: 指针传递swap ==========
    cout << "--- 任务3: 指针传递 swap ---" << endl;
    int a3 = 15, b3 = 25;
    cout << "交换前: a=" << a3 << ", b=" << b3 << endl;
    swapByPointer(&a3, &b3);
    cout << "交换后: a=" << a3 << ", b=" << b3 << endl << endl;

    // ========== 任务4测试: 数组参数传递 ==========
    cout << "--- 任务4: 数组参数传递 ---" << endl;
    int arr[] = {5, 2, 8, 1, 9};
    int arrSize = 5;

    cout << "原始数组: ";
    printArray(arr, arrSize);

    int sum = arraySum(arr, arrSize);
    cout << "数组总和: " << sum << endl;

    arrayReverse(arr, arrSize);
    cout << "反转后: ";
    printArray(arr, arrSize);

    arraySort(arr, arrSize);
    cout << "排序后: ";
    printArray(arr, arrSize);
    cout << endl;

    // ========== 任务5测试: 三种方式对比 ==========
    cout << "--- 任务5: 三种方式对比 ---" << endl;

    int val1 = 100;
    cout << "值传递: 原值=" << val1;
    incrementByValue(val1);
    cout << ", 处理后=" << val1 << endl;

    int val2 = 100;
    cout << "引用传递: 原值=" << val2;
    incrementByReference(val2);
    cout << ", 处理后=" << val2 << endl;

    int val3 = 100;
    cout << "指针传递: 原值=" << val3;
    incrementByPointer(&val3);
    cout << ", 处理后=" << val3 << endl << endl;

    // ========== 任务6测试: 大对象传递 ==========
    cout << "--- 任务6: 大对象传递 ---" << endl;

    cout << "创建DataBlock对象:" << endl;
    DataBlock bigData;
    cout << endl;

    cout << "值传递 (观察是否发生拷贝):" << endl;
    processDataByValue(bigData);
    cout << endl;

    cout << "引用传递 (无拷贝):" << endl;
    processDataByReference(bigData);
    cout << endl;

    cout << "常量引用传递 (无拷贝，只读):" << endl;
    processDataByConstReference(bigData);
    cout << endl;

    // ========== 任务7测试: 引用与指针选择 ==========
    cout << "--- 任务7: 引用与指针选择 ---" << endl;
    int arr7[] = {3, 7, 2, 9, 5};
    int size7 = 5;

    int& maxRef = findMax(arr7, size7);
    cout << "数组最大值: " << maxRef << endl;

    int* found5 = findElement(arr7, size7, 5);
    if (found5 != nullptr) {
        cout << "查找5: 找到，值为 " << *found5 << endl;
    } else {
        cout << "查找5: 未找到" << endl;
    }

    int* found100 = findElement(arr7, size7, 100);
    if (found100 != nullptr) {
        cout << "查找100: 找到，值为 " << *found100 << endl;
    } else {
        cout << "查找100: 未找到" << endl;
    }

    cout << endl;
    cout << "=== 实验完成 ===" << endl;
    cout << endl;

    // ========== 知识点总结 ==========
    cout << "=== 参数传递总结 ===" << endl;
    cout << "1. 值传递: 传递副本，不能修改原数据，小对象适用" << endl;
    cout << "2. 引用传递: 直接操作原数据，语法简洁，效率高" << endl;
    cout << "3. 指针传递: 通过地址操作，可表示nullptr，更灵活" << endl;
    cout << "4. 数组参数: 退化为指针，需额外传递大小" << endl;
    cout << "5. 选择原则: 小对象值传递，大对象const引用，需修改用引用或指针" << endl;

    return 0;
}

/*
=== 运行结果示例 ===

=== 数据交换中心系统 ===

--- 任务1: 值传递演示 ---
修改前: 10
函数内部: 11
修改后: 10 (未改变)

--- 任务2: 引用传递 swap ---
交换前: a=3, b=7
交换后: a=7, b=3

--- 任务3: 指针传递 swap ---
交换前: a=15, b=25
交换后: a=25, b=15

--- 任务4: 数组参数传递 ---
原始数组: 5 2 8 1 9
数组总和: 25
反转后: 9 1 8 2 5
排序后: 1 2 5 8 9

--- 任务5: 三种方式对比 ---
值传递: 原值=100, 处理后=100
引用传递: 原值=100, 处理后=101
指针传递: 原值=100, 处理后=101

--- 任务6: 大对象传递 ---
创建DataBlock对象:
  [DataBlock构造函数被调用]

值传递 (观察是否发生拷贝):
  [DataBlock拷贝构造函数被调用 - 发生了拷贝!]

引用传递 (无拷贝):

常量引用传递 (无拷贝，只读):

--- 任务7: 引用与指针选择 ---
数组最大值: 9
查找5: 找到，值为 5
查找100: 未找到

=== 实验完成 ===

=== 参数传递总结 ===
1. 值传递: 传递副本，不能修改原数据，小对象适用
2. 引用传递: 直接操作原数据，语法简洁，效率高
3. 指针传递: 通过地址操作，可表示nullptr，更灵活
4. 数组参数: 退化为指针，需额外传递大小
5. 选择原则: 小对象值传递，大对象const引用，需修改用引用或指针

=== 知识点详解 ===

1. 值传递 vs 引用传递 vs 指针传递
   - 值传递: 安全但可能低效（大对象拷贝开销）
   - 引用传递: 高效且语法简洁，C++推荐
   - 指针传递: 灵活（可nullptr），但需手动解引用

2. 数组参数的特殊性
   - 数组名退化为指针
   - 无法获取数组大小，需额外参数
   - 可以修改数组元素

3. 何时使用const引用
   - 传递大对象但不需修改
   - 既保证效率又保证安全
   - Effective C++推荐做法

4. 引用与指针的选择
   - 引用: 确定有值，不需重新绑定
   - 指针: 可能为空，或需要指针算术

5. 性能优化建议
   - 基本类型: 值传递
   - 大对象只读: const引用
   - 需要修改: 引用（首选）或指针
   - 数组: 指针+大小，或使用vector

*/
