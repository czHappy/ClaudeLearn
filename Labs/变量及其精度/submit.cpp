#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cmath>
using namespace std;

// 任务1：类型大小探测器
void typeSizeDetector() {
    cout << "\n=== 数据类型大小探测 ===" << endl;
    cout << left << setw(20) << "类型" << setw(15) << "大小(字节)" << endl;
    cout << string(35, '-') << endl;

    // TODO: 使用 sizeof 运算符输出各种类型的大小
    // 基本类型
    cout << setw(20) << "char" << setw(15) << /* sizeof(char) */ << endl;
    cout << setw(20) << "bool" << setw(15) << /* sizeof(bool) */ << endl;
    cout << setw(20) << "short" << setw(15) << /* sizeof(short) */ << endl;
    cout << setw(20) << "int" << setw(15) << /* sizeof(int) */ << endl;
    cout << setw(20) << "long" << setw(15) << /* sizeof(long) */ << endl;
    cout << setw(20) << "long long" << setw(15) << /* sizeof(long long) */ << endl;

    // TODO: 浮点类型
    cout << setw(20) << "float" << setw(15) << /* 你的代码 */ << endl;
    cout << setw(20) << "double" << setw(15) << /* 你的代码 */ << endl;
    cout << setw(20) << "long double" << setw(15) << /* 你的代码 */ << endl;

    // TODO: 无符号类型
    cout << setw(20) << "unsigned int" << setw(15) << /* 你的代码 */ << endl;
    cout << setw(20) << "unsigned long long" << setw(15) << /* 你的代码 */ << endl;
}

// 任务2：整型边界探索
void integerBoundary() {
    cout << "\n=== 整型边界探索 ===" << endl;

    // TODO: 使用 <climits> 中的常量输出各类型范围
    cout << "char: " << CHAR_MIN << " ~ " << CHAR_MAX << endl;
    cout << "short: " << SHRT_MIN << " ~ " << SHRT_MAX << endl;
    cout << "int: " << /* INT_MIN */ << " ~ " << /* INT_MAX */ << endl;
    cout << "long long: " << /* LLONG_MIN */ << " ~ " << /* LLONG_MAX */ << endl;

    // TODO: 输出无符号类型的最大值
    cout << "unsigned int: 0 ~ " << /* UINT_MAX */ << endl;
    cout << "unsigned long long: 0 ~ " << /* ULLONG_MAX */ << endl;

    // 手动计算验证
    cout << "\n手动计算验证 (int, 32位):" << endl;
    // TODO: 计算 2^31 - 1 作为 int 的最大值
    // 提示：可以使用位运算或 pow 函数

}

// 任务3：整数溢出实验
void integerOverflow() {
    cout << "\n=== 整数溢出实验 ===" << endl;

    // 有符号整数溢出
    int maxInt = INT_MAX;
    cout << "INT_MAX = " << maxInt << endl;

    // TODO: 演示 INT_MAX + 1 的结果（注意：这是未定义行为）
    // int overflow = maxInt + 1;
    // cout << "INT_MAX + 1 = " << overflow << " (溢出！)" << endl;


    // 无符号整数回绕
    unsigned int maxUint = UINT_MAX;
    cout << "\nUINT_MAX = " << maxUint << endl;

    // TODO: 演示 UINT_MAX + 1 的结果（这是定义良好的回绕行为）


    // TODO: 演示无符号整数减法回绕
    // unsigned int zero = 0;
    // unsigned int underflow = zero - 1;

}

// 任务4：浮点精度陷阱
void floatingPointPrecision() {
    cout << "\n=== 浮点精度陷阱 ===" << endl;
    cout << fixed << setprecision(17);

    // 经典的 0.1 + 0.2 问题
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    double sum = a + b;

    cout << "0.1 + 0.2 = " << sum << endl;
    cout << "0.3 = " << c << endl;

    // TODO: 直接比较 sum == c
    // cout << "0.1 + 0.2 == 0.3? " << (/* 比较结果 */ ? "是" : "否") << endl;


    // float 与 double 精度对比
    cout << "\n--- float vs double ---" << endl;
    float f = 1234567.0f;
    double d = 1234567.0;

    // TODO: 演示 float 精度丢失
    // cout << "float: 1234567.0 + 0.1 = " << (f + 0.1f) << endl;
    // cout << "double: 1234567.0 + 0.1 = " << (d + 0.1) << endl;


    // 安全的浮点数比较
    cout << "\n--- 安全的浮点数比较 ---" << endl;
    // TODO: 实现使用 epsilon 的安全比较
    // double epsilon = 1e-9;
    // bool isEqual = fabs(sum - c) < epsilon;
    // cout << "使用epsilon比较: 0.1+0.2 ≈ 0.3? " << (isEqual ? "是" : "否") << endl;

}

// 任务5：类型转换探险
void typeConversion() {
    cout << "\n=== 类型转换探险 ===" << endl;

    // 隐式转换示例
    cout << "--- 隐式转换 ---" << endl;
    int i = 65;
    char ch = i;  // int 到 char
    cout << "int 65 转为 char: " << ch << endl;

    // TODO: 演示整型提升
    // char c1 = 10, c2 = 20;
    // 注意：c1 + c2 的类型是 int，不是 char


    // 有符号与无符号混合
    cout << "\n--- 有符号/无符号混合 ---" << endl;
    int negative = -1;
    unsigned int positive = 1;

    // TODO: 演示比较 negative < positive 的陷阱
    // cout << "-1 < 1u ? " << (/* 比较 */ ? "是" : "否") << endl;
    // cout << "-1 转为 unsigned int: " << (unsigned int)negative << endl;


    // 浮点到整型
    cout << "\n--- 浮点到整型 ---" << endl;
    double d1 = 3.9;
    double d2 = -3.9;

    // TODO: 演示截断行为
    // cout << "3.9 转为 int: " << (int)d1 << endl;
    // cout << "-3.9 转为 int: " << (int)d2 << endl;


    // 显式转换
    cout << "\n--- 显式转换 ---" << endl;
    // TODO: 使用 static_cast 进行类型转换
    // int x = 10, y = 3;
    // cout << "10/3 (整数除法) = " << x/y << endl;
    // cout << "10/3 (浮点除法) = " << static_cast<double>(x)/y << endl;

}

// 任务6：有符号与无符号的陷阱
void signedUnsignedTraps() {
    cout << "\n=== 有符号与无符号的陷阱 ===" << endl;

    // 陷阱1：循环计数器
    cout << "--- 循环计数器陷阱 ---" << endl;
    cout << "以下循环会出问题（概念演示，不实际运行）:" << endl;
    cout << "for (unsigned int i = 10; i >= 0; i--) // 永远不会结束！" << endl;

    // TODO: 演示为什么这个循环有问题
    // unsigned int u = 0;
    // cout << "0u - 1 = " << (u - 1) << " (回绕到最大值)" << endl;


    // 陷阱2：数组大小比较
    cout << "\n--- 数组大小比较陷阱 ---" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int index = -1;

    // TODO: 演示与 sizeof 结果比较的陷阱
    // size_t size = sizeof(arr) / sizeof(arr[0]);
    // cout << "index = " << index << ", size = " << size << endl;
    // cout << "index < size ? " << (index < size ? "是" : "否") << endl;
    // 注意：这可能给出错误结果！


    // 陷阱3：混合运算
    cout << "\n--- 混合运算陷阱 ---" << endl;
    // TODO: 演示混合运算中的隐式转换
    // int a = -5;
    // unsigned int b = 10;
    // cout << "a + b = " << (a + b) << " (类型是unsigned int!)" << endl;

}

int main() {
    cout << "========== 数据侦探 ==========" << endl;

    typeSizeDetector();
    integerBoundary();
    integerOverflow();
    floatingPointPrecision();
    typeConversion();
    signedUnsignedTraps();

    cout << "\n========== 调查完毕 ==========" << endl;
    return 0;
}
