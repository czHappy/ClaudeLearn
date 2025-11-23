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

    cout << setw(20) << "char" << setw(15) << sizeof(char) << endl;
    cout << setw(20) << "bool" << setw(15) << sizeof(bool) << endl;
    cout << setw(20) << "short" << setw(15) << sizeof(short) << endl;
    cout << setw(20) << "int" << setw(15) << sizeof(int) << endl;
    cout << setw(20) << "long" << setw(15) << sizeof(long) << endl;
    cout << setw(20) << "long long" << setw(15) << sizeof(long long) << endl;
    cout << setw(20) << "float" << setw(15) << sizeof(float) << endl;
    cout << setw(20) << "double" << setw(15) << sizeof(double) << endl;
    cout << setw(20) << "long double" << setw(15) << sizeof(long double) << endl;
    cout << setw(20) << "unsigned int" << setw(15) << sizeof(unsigned int) << endl;
    cout << setw(20) << "unsigned long long" << setw(15) << sizeof(unsigned long long) << endl;
}

// 任务2：整型边界探索
void integerBoundary() {
    cout << "\n=== 整型边界探索 ===" << endl;

    cout << "char: " << static_cast<int>(CHAR_MIN) << " ~ " << static_cast<int>(CHAR_MAX) << endl;
    cout << "short: " << SHRT_MIN << " ~ " << SHRT_MAX << endl;
    cout << "int: " << INT_MIN << " ~ " << INT_MAX << endl;
    cout << "long long: " << LLONG_MIN << " ~ " << LLONG_MAX << endl;
    cout << "unsigned int: 0 ~ " << UINT_MAX << endl;
    cout << "unsigned long long: 0 ~ " << ULLONG_MAX << endl;

    cout << "\n手动计算验证 (int, 32位):" << endl;
    long long calculated_max = static_cast<long long>(pow(2, 31)) - 1;
    cout << "计算的 INT_MAX: " << calculated_max << endl;
    cout << "实际的 INT_MAX: " << INT_MAX << endl;
    cout << "一致性: " << (calculated_max == INT_MAX ? "是" : "否") << endl;
}

// 任务3：整数溢出实验
void integerOverflow() {
    cout << "\n=== 整数溢出实验 ===" << endl;

    int maxInt = INT_MAX;
    cout << "INT_MAX = " << maxInt << endl;
    int overflow = maxInt + 1;
    cout << "INT_MAX + 1 = " << overflow << " (溢出！有符号整数溢出是未定义行为)" << endl;

    unsigned int maxUint = UINT_MAX;
    cout << "\nUINT_MAX = " << maxUint << endl;
    unsigned int wrapAround = maxUint + 1;
    cout << "UINT_MAX + 1 = " << wrapAround << " (回绕！无符号整数回绕是定义良好的)" << endl;

    unsigned int zero = 0;
    unsigned int underflow = zero - 1;
    cout << "0u - 1 = " << underflow << " (回绕到最大值)" << endl;
}

// 任务4：浮点精度陷阱
void floatingPointPrecision() {
    cout << "\n=== 浮点精度陷阱 ===" << endl;
    cout << fixed << setprecision(17);

    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    double sum = a + b;

    cout << "0.1 + 0.2 = " << sum << endl;
    cout << "0.3 = " << c << endl;
    cout << "0.1 + 0.2 == 0.3? " << (sum == c ? "是" : "否！") << endl;

    cout << "\n--- float vs double ---" << endl;
    cout << setprecision(10);
    float f = 1234567.0f;
    double d = 1234567.0;

    cout << "float: 1234567.0 + 0.1 = " << (f + 0.1f) << endl;
    cout << "double: 1234567.0 + 0.1 = " << (d + 0.1) << endl;

    cout << "\n--- 安全的浮点数比较 ---" << endl;
    double epsilon = 1e-9;
    bool isEqual = fabs(sum - c) < epsilon;
    cout << "使用epsilon比较: 0.1+0.2 ≈ 0.3? " << (isEqual ? "是" : "否") << endl;
}

// 任务5：类型转换探险
void typeConversion() {
    cout << "\n=== 类型转换探险 ===" << endl;

    cout << "--- 隐式转换 ---" << endl;
    int i = 65;
    char ch = i;
    cout << "int 65 转为 char: " << ch << " (ASCII码)" << endl;

    char c1 = 10, c2 = 20;
    auto result = c1 + c2;
    cout << "char(10) + char(20) 的结果类型: " << typeid(result).name() << " (提升为int)" << endl;

    cout << "\n--- 有符号/无符号混合 ---" << endl;
    int negative = -1;
    unsigned int positive = 1;

    cout << "-1 < 1u ? " << (negative < positive ? "是" : "否！（陷阱！）") << endl;
    cout << "-1 转为 unsigned int: " << static_cast<unsigned int>(negative) << endl;

    cout << "\n--- 浮点到整型 ---" << endl;
    double d1 = 3.9;
    double d2 = -3.9;

    cout << "3.9 转为 int: " << static_cast<int>(d1) << " (截断)" << endl;
    cout << "-3.9 转为 int: " << static_cast<int>(d2) << " (向零截断)" << endl;

    cout << "\n--- 显式转换 ---" << endl;
    int x = 10, y = 3;
    cout << "10/3 (整数除法) = " << x / y << endl;
    cout << "10/3 (浮点除法) = " << static_cast<double>(x) / y << endl;
}

// 任务6：有符号与无符号的陷阱
void signedUnsignedTraps() {
    cout << "\n=== 有符号与无符号的陷阱 ===" << endl;

    cout << "--- 循环计数器陷阱 ---" << endl;
    cout << "以下循环会出问题（概念演示）:" << endl;
    cout << "for (unsigned int i = 10; i >= 0; i--) // 永远不会结束！" << endl;

    unsigned int u = 0;
    cout << "原因：0u - 1 = " << (u - 1) << " (回绕到最大值)" << endl;

    cout << "\n--- 数组大小比较陷阱 ---" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int index = -1;

    size_t size = sizeof(arr) / sizeof(arr[0]);
    cout << "index = " << index << ", size = " << size << endl;
    cout << "index < size ? " << (index < size ? "是（错误！）" : "否") << endl;
    cout << "原因：index被转换为unsigned，-1变成很大的数" << endl;

    cout << "\n--- 混合运算陷阱 ---" << endl;
    int a = -5;
    unsigned int b = 10;
    auto sum = a + b;
    cout << "int(-5) + unsigned(10) = " << sum << endl;
    cout << "结果类型: unsigned int (隐式转换导致错误结果)" << endl;
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
