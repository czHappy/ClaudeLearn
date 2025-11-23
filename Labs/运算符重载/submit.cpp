/*
 * 实验：运算符重载 - 分数类实现
 *
 * 任务：实现一个完整的分数类Fraction，支持各种运算符重载
 *
 * 要求：
 * 1. 实现基本的分数运算（加减乘除）
 * 2. 实现关系运算符（比较大小）
 * 3. 实现自增自减运算符
 * 4. 实现流运算符（输入输出）
 * 5. 实现下标运算符
 * 6. 实现函数调用运算符
 * 7. 实现类型转换运算符
 */

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;  // 分子
    int den;  // 分母

    // TODO: 实现辅助函数：求最大公约数
    // 提示：使用欧几里得算法
    int gcd(int a, int b) {
        // TODO: 实现gcd算法

    }

    // TODO: 实现辅助函数：约分
    // 提示：使用gcd简化分数，并确保分母为正
    void reduce() {
        // TODO: 约分实现

    }

public:
    // TODO: 实现默认构造函数
    // 提示：初始化为0/1
    Fraction() {
        // TODO

    }

    // TODO: 实现带参构造函数
    // 提示：检查分母不为0，并自动约分
    Fraction(int n, int d = 1) {
        // TODO

    }

    // 获取分子
    int getNumerator() const { return num; }

    // 获取分母
    int getDenominator() const { return den; }

    // ==================== 任务2：算术运算符重载 ====================

    // TODO: 重载加法运算符 +
    // 提示：a/b + c/d = (a*d + b*c)/(b*d)，结果需要约分
    Fraction operator+(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载减法运算符 -
    // 提示：a/b - c/d = (a*d - b*c)/(b*d)
    Fraction operator-(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载乘法运算符 *
    // 提示：a/b * c/d = (a*c)/(b*d)
    Fraction operator*(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载除法运算符 /
    // 提示：a/b / c/d = (a*d)/(b*c)，注意检查除数分子不为0
    Fraction operator/(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载复合赋值运算符 +=
    // 提示：可以利用已实现的+运算符
    Fraction& operator+=(const Fraction& other) {
        // TODO

    }

    // TODO: 重载复合赋值运算符 -=
    Fraction& operator-=(const Fraction& other) {
        // TODO

    }

    // TODO: 重载复合赋值运算符 *=
    Fraction& operator*=(const Fraction& other) {
        // TODO

    }

    // TODO: 重载复合赋值运算符 /=
    Fraction& operator/=(const Fraction& other) {
        // TODO

    }

    // ==================== 任务3：关系运算符重载 ====================

    // TODO: 重载等于运算符 ==
    // 提示：约分后比较分子分母是否相等
    bool operator==(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载不等于运算符 !=
    // 提示：可以利用==的结果取反
    bool operator!=(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载小于运算符 <
    // 提示：a/b < c/d 等价于 a*d < b*c（假设分母为正）
    bool operator<(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载大于运算符 >
    // 提示：利用<运算符
    bool operator>(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载小于等于运算符 <=
    // 提示：!(a > b)
    bool operator<=(const Fraction& other) const {
        // TODO

    }

    // TODO: 重载大于等于运算符 >=
    // 提示：!(a < b)
    bool operator>=(const Fraction& other) const {
        // TODO

    }

    // ==================== 任务4：赋值运算符重载 ====================

    // TODO: 重载赋值运算符 =
    // 提示：检查自赋值，返回*this的引用
    Fraction& operator=(const Fraction& other) {
        // TODO

    }

    // ==================== 任务5：自增自减运算符重载 ====================

    // TODO: 重载前置自增运算符 ++
    // 提示：分数加1，即num += den，返回引用
    Fraction& operator++() {
        // TODO

    }

    // TODO: 重载后置自增运算符 ++
    // 提示：参数int是哑元，保存原值，调用前置++，返回原值
    Fraction operator++(int) {
        // TODO

    }

    // TODO: 重载前置自减运算符 --
    // 提示：分数减1，即num -= den
    Fraction& operator--() {
        // TODO

    }

    // TODO: 重载后置自减运算符 --
    Fraction operator--(int) {
        // TODO

    }

    // ==================== 任务6：流运算符重载 ====================

    // TODO: 重载输出运算符 <<
    // 提示：必须声明为友元函数，输出格式为"分子/分母"
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        // TODO

    }

    // TODO: 重载输入运算符 >>
    // 提示：必须声明为友元函数，读取格式为"分子/分母"
    friend istream& operator>>(istream& is, Fraction& f) {
        // TODO

    }

    // ==================== 任务7：函数调用运算符重载 ====================

    // TODO: 重载函数调用运算符 ()
    // 提示：返回分数的小数值(double类型)
    double operator()() const {
        // TODO

    }

    // ==================== 任务8：下标运算符重载 ====================

    // TODO: 重载下标运算符 []（非const版本）
    // 提示：index为0返回分子的引用，1返回分母的引用，其他抛出异常
    int& operator[](int index) {
        // TODO

    }

    // TODO: 重载下标运算符 []（const版本）
    // 提示：只读访问，返回const引用
    const int& operator[](int index) const {
        // TODO

    }

    // ==================== 任务9：类型转换运算符 ====================

    // TODO: 重载类型转换运算符 double
    // 提示：返回分数的小数值
    operator double() const {
        // TODO

    }
};

// ==================== 测试代码 ====================

int main() {
    cout << "========== 测试构造和输出 ==========" << endl;
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(6, 8);  // 应该自动约分为3/4
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << " (约分测试)" << endl;

    cout << "\n========== 测试算术运算 ==========" << endl;
    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;
    cout << "f1 / f2 = " << f1 / f2 << endl;

    cout << "\n========== 测试复合赋值 ==========" << endl;
    Fraction f4(1, 3);
    cout << "f4 = " << f4 << endl;
    f4 += Fraction(1, 6);
    cout << "f4 += 1/6, f4 = " << f4 << endl;

    cout << "\n========== 测试关系运算 ==========" << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "true" : "false") << endl;
    cout << "f1 > f2: " << (f1 > f2 ? "true" : "false") << endl;
    cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << endl;
    cout << "f2 == f3: " << (f2 == f3 ? "true" : "false") << endl;

    cout << "\n========== 测试自增自减 ==========" << endl;
    Fraction f5(1, 3);
    cout << "f5 = " << f5 << endl;
    cout << "++f5 = " << ++f5 << endl;
    cout << "f5 = " << f5 << endl;
    cout << "f5++ = " << f5++ << endl;
    cout << "f5 = " << f5 << endl;
    cout << "--f5 = " << --f5 << endl;
    cout << "f5 = " << f5 << endl;

    cout << "\n========== 测试下标运算符 ==========" << endl;
    cout << "f1[0] = " << f1[0] << ", f1[1] = " << f1[1] << endl;
    f1[0] = 2;  // 修改分子
    cout << "修改后 f1 = " << f1 << endl;

    cout << "\n========== 测试函数调用运算符 ==========" << endl;
    cout << "f2() = " << f2() << endl;
    cout << "f1() = " << f1() << endl;

    cout << "\n========== 测试类型转换 ==========" << endl;
    double d1 = static_cast<double>(f2);
    double d2 = f2;  // 隐式转换
    cout << "static_cast<double>(f2) = " << d1 << endl;
    cout << "f2隐式转换为double = " << d2 << endl;

    cout << "\n========== 测试输入运算符 ==========" << endl;
    cout << "请输入一个分数（格式：分子/分母）：";
    Fraction f6;
    // 取消下面的注释来测试输入
    // cin >> f6;
    // cout << "你输入的分数是：" << f6 << endl;
    // cout << "小数值为：" << f6() << endl;

    cout << "\n========== 测试链式运算 ==========" << endl;
    Fraction result = f1 + f2 * f3 - Fraction(1, 4);
    cout << "f1 + f2 * f3 - 1/4 = " << result << endl;

    cout << "\n========== 测试边界情况 ==========" << endl;
    Fraction zero(0, 5);
    cout << "0/5 = " << zero << endl;
    Fraction negative(-3, 4);
    cout << "-3/4 = " << negative << endl;
    Fraction negative2(3, -4);
    cout << "3/-4 = " << negative2 << " (分母应转正)" << endl;

    return 0;
}
