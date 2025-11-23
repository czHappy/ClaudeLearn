/**
 * 实验: 数据交换中心
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
 * TODO: 实现值传递函数
 * 功能: 尝试通过值传递修改参数
 * 参数: int x - 使用值传递
 * 说明: 函数内修改x，观察是否影响原变量
 */
void tryModifyByValue(int x) {
    // TODO: 将x的值加1

    cout << "函数内部: " << x << endl;
}

// ==================== 任务2: 引用传递 - swap函数 ====================
/**
 * TODO: 实现引用传递的交换函数
 * 功能: 交换两个整数的值
 * 参数: int& a, int& b - 使用引用传递
 */
void swapByReference(int& a, int& b) {
    // TODO: 交换a和b的值
    // 提示: 需要一个临时变量

}

// ==================== 任务3: 指针传递 - swap函数 ====================
/**
 * TODO: 实现指针传递的交换函数
 * 功能: 交换两个整数的值
 * 参数: int* a, int* b - 使用指针传递
 * 注意: 需要检查指针是否为空
 */
void swapByPointer(int* a, int* b) {
    // TODO: 检查指针是否为nullptr


    // TODO: 交换*a和*b的值

}

// ==================== 任务4: 数组参数传递 ====================
/**
 * TODO: 实现数组求和函数
 * 功能: 计算数组所有元素的和
 * 参数: int arr[] - 数组（实际上是指针）
 *       int size - 数组大小
 * 返回: 数组元素的总和
 */
int arraySum(int arr[], int size) {
    // TODO: 遍历数组，计算总和

    return 0;
}

/**
 * TODO: 实现数组反转函数
 * 功能: 原地反转数组元素
 * 参数: int arr[] - 数组
 *       int size - 数组大小
 */
void arrayReverse(int arr[], int size) {
    // TODO: 使用双指针法反转数组
    // 提示: 左指针从0开始，右指针从size-1开始

}

/**
 * TODO: 实现数组排序函数
 * 功能: 对数组进行升序排序
 * 参数: int arr[] - 数组
 *       int size - 数组大小
 * 提示: 可以使用std::sort(arr, arr + size)
 */
void arraySort(int arr[], int size) {
    // TODO: 对数组进行排序

}

// ==================== 任务5: 三种方式对比 ====================
/**
 * TODO: 值传递版本的增量函数
 * 功能: 尝试将参数加1
 * 参数: int x - 值传递
 */
void incrementByValue(int x) {
    // TODO: x加1

}

/**
 * TODO: 引用传递版本的增量函数
 * 功能: 将参数加1
 * 参数: int& x - 引用传递
 */
void incrementByReference(int& x) {
    // TODO: x加1

}

/**
 * TODO: 指针传递版本的增量函数
 * 功能: 将参数加1
 * 参数: int* x - 指针传递
 */
void incrementByPointer(int* x) {
    // TODO: 检查指针有效性，然后*x加1

}

// ==================== 任务6: 大对象传递策略 ====================
/**
 * 定义一个大型数据块结构体
 */
struct DataBlock {
    int data[1000];  // 大数组

    // 构造函数
    DataBlock() {
        cout << "  [DataBlock构造函数被调用]" << endl;
        for (int i = 0; i < 1000; i++) {
            data[i] = i;
        }
    }

    // 拷贝构造函数
    DataBlock(const DataBlock& other) {
        cout << "  [DataBlock拷贝构造函数被调用 - 发生了拷贝!]" << endl;
        for (int i = 0; i < 1000; i++) {
            data[i] = other.data[i];
        }
    }
};

/**
 * TODO: 值传递处理大对象
 * 参数: DataBlock block - 值传递（会发生拷贝）
 * 返回: 第一个元素的值
 */
int processDataByValue(DataBlock block) {
    // TODO: 返回block.data[0]
    return 0;
}

/**
 * TODO: 引用传递处理大对象
 * 参数: DataBlock& block - 引用传递（不拷贝，可修改）
 * 返回: 第一个元素的值
 */
int processDataByReference(DataBlock& block) {
    // TODO: 返回block.data[0]
    return 0;
}

/**
 * TODO: 常量引用传递处理大对象
 * 参数: const DataBlock& block - 常量引用（不拷贝，只读）
 * 返回: 第一个元素的值
 */
int processDataByConstReference(const DataBlock& block) {
    // TODO: 返回block.data[0]
    return 0;
}

// ==================== 任务7: 引用与指针的选择 ====================
/**
 * TODO: 查找数组最大值（使用引用返回）
 * 参数: int arr[] - 数组
 *       int size - 数组大小
 * 返回: 最大值的引用
 * 说明: 返回引用可以直接修改数组中的最大值
 */
int& findMax(int arr[], int size) {
    // TODO: 找到最大值的下标
    // 提示: 遍历数组，记录最大值的索引

    // TODO: 返回对应元素的引用
    return arr[0];  // 临时返回，需要修改
}

/**
 * TODO: 查找指定元素（使用指针返回）
 * 参数: int arr[] - 数组
 *       int size - 数组大小
 *       int target - 要查找的值
 * 返回: 找到返回元素的指针，找不到返回nullptr
 * 说明: 指针可以表示"找不到"的情况
 */
int* findElement(int arr[], int size, int target) {
    // TODO: 遍历数组查找target


    // TODO: 找不到返回nullptr
    return nullptr;
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

    return 0;
}
