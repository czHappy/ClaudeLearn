/*
 * 实验：运算符重载 - 分数类实现（标准答案）
 *
 * 完整实现一个支持各种运算符重载的分数类
 */

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;  // 分子
    int den;  // 分母

    // 辅助函数：求最大公约数（欧几里得算法）
    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // 辅助函数：约分
    void reduce() {
        if (den == 0) {
            throw invalid_argument("分母不能为0");
        }

        if (num == 0) {
            den = 1;
            return;
        }

        int g = gcd(num, den);
        num /= g;
        den /= g;

        // 确保分母为正
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    // 默认构造函数：初始化为0/1
    Fraction() : num(0), den(1) {}

    // 带参构造函数
    Fraction(int n, int d = 1) : num(n), den(d) {
        if (d == 0) {
            throw invalid_argument("分母不能为0");
        }
        reduce();
    }

    // 获取分子
    int getNumerator() const { return num; }

    // 获取分母
    int getDenominator() const { return den; }

    // ==================== 算术运算符重载 ====================

    // 加法运算符
    Fraction operator+(const Fraction& other) const {
        // a/b + c/d = (a*d + b*c)/(b*d)
        return Fraction(num * other.den + den * other.num, den * other.den);
    }

    // 减法运算符
    Fraction operator-(const Fraction& other) const {
        // a/b - c/d = (a*d - b*c)/(b*d)
        return Fraction(num * other.den - den * other.num, den * other.den);
    }

    // 乘法运算符
    Fraction operator*(const Fraction& other) const {
        // a/b * c/d = (a*c)/(b*d)
        return Fraction(num * other.num, den * other.den);
    }

    // 除法运算符
    Fraction operator/(const Fraction& other) const {
        // a/b / c/d = (a*d)/(b*c)
        if (other.num == 0) {
            throw invalid_argument("除数不能为0");
        }
        return Fraction(num * other.den, den * other.num);
    }

    // 复合赋值运算符 +=
    Fraction& operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    // 复合赋值运算符 -=
    Fraction& operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    // 复合赋值运算符 *=
    Fraction& operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    // 复合赋值运算符 /=
    Fraction& operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    // ==================== 关系运算符重载 ====================

    // 等于运算符
    bool operator==(const Fraction& other) const {
        // 由于已经约分，直接比较分子分母
        return num == other.num && den == other.den;
    }

    // 不等于运算符
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // 小于运算符
    bool operator<(const Fraction& other) const {
        // a/b < c/d 等价于 a*d < b*c（分母都为正）
        return num * other.den < den * other.num;
    }

    // 大于运算符
    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    // 小于等于运算符
    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    // 大于等于运算符
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // ==================== 赋值运算符重载 ====================

    // 拷贝赋值运算符
    Fraction& operator=(const Fraction& other) {
        // 自赋值检查
        if (this != &other) {
            num = other.num;
            den = other.den;
        }
        return *this;
    }

    // ==================== 自增自减运算符重载 ====================

    // 前置自增运算符：++f
    Fraction& operator++() {
        num += den;  // 分数加1：num/den + 1 = (num+den)/den
        reduce();
        return *this;
    }

    // 后置自增运算符：f++
    Fraction operator++(int) {
        Fraction temp = *this;  // 保存原值
        ++(*this);              // 调用前置++
        return temp;            // 返回原值
    }

    // 前置自减运算符：--f
    Fraction& operator--() {
        num -= den;  // 分数减1：num/den - 1 = (num-den)/den
        reduce();
        return *this;
    }

    // 后置自减运算符：f--
    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    // ==================== 流运算符重载 ====================

    // 输出运算符（友元函数）
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.num << "/" << f.den;
        return os;
    }

    // 输入运算符（友元函数）
    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.num >> slash >> f.den;

        if (slash != '/') {
            is.setstate(ios::failbit);  // 设置流状态为失败
            return is;
        }

        try {
            f.reduce();
        } catch (const invalid_argument& e) {
            is.setstate(ios::failbit);
        }

        return is;
    }

    // ==================== 函数调用运算符重载 ====================

    // 函数调用运算符：返回分数的小数值
    double operator()() const {
        return static_cast<double>(num) / den;
    }

    // 函数调用运算符（带参数）：计算分数的n次幂
    double operator()(int n) const {
        return pow(static_cast<double>(num) / den, n);
    }

    // ==================== 下标运算符重载 ====================

    // 下标运算符（非const版本）：可修改
    int& operator[](int index) {
        if (index == 0) return num;
        if (index == 1) return den;
        throw out_of_range("下标必须是0或1");
    }

    // 下标运算符（const版本）：只读
    const int& operator[](int index) const {
        if (index == 0) return num;
        if (index == 1) return den;
        throw out_of_range("下标必须是0或1");
    }

    // ==================== 类型转换运算符 ====================

    // 转换为double
    operator double() const {
        return static_cast<double>(num) / den;
    }

    // 转换为bool：判断分数是否为0
    explicit operator bool() const {
        return num != 0;
    }

    // ==================== 一元运算符 ====================

    // 一元负号运算符
    Fraction operator-() const {
        return Fraction(-num, den);
    }

    // 一元正号运算符
    Fraction operator+() const {
        return *this;
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
    cout << "f3 = " << f3 << " (约分测试，应为3/4)" << endl;

    cout << "\n========== 测试算术运算 ==========" << endl;
    cout << "f1 + f2 = " << f1 + f2 << endl;  // 5/4
    cout << "f1 - f2 = " << f1 - f2 << endl;  // -1/4
    cout << "f1 * f2 = " << f1 * f2 << endl;  // 3/8
    cout << "f1 / f2 = " << f1 / f2 << endl;  // 2/3

    cout << "\n========== 测试复合赋值 ==========" << endl;
    Fraction f4(1, 3);
    cout << "f4 = " << f4 << endl;
    f4 += Fraction(1, 6);
    cout << "f4 += 1/6, f4 = " << f4 << " (应为1/2)" << endl;
    f4 *= Fraction(2, 1);
    cout << "f4 *= 2, f4 = " << f4 << " (应为1/1)" << endl;

    cout << "\n========== 测试关系运算 ==========" << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "true" : "false") << " (应为true)" << endl;
    cout << "f1 > f2: " << (f1 > f2 ? "true" : "false") << " (应为false)" << endl;
    cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << " (应为false)" << endl;
    cout << "f2 == f3: " << (f2 == f3 ? "true" : "false") << " (应为true)" << endl;

    cout << "\n========== 测试自增自减 ==========" << endl;
    Fraction f5(1, 3);
    cout << "f5 = " << f5 << endl;
    cout << "++f5 = " << ++f5 << " (应为4/3)" << endl;
    cout << "f5 = " << f5 << " (应为4/3)" << endl;
    cout << "f5++ = " << f5++ << " (应为4/3)" << endl;
    cout << "f5 = " << f5 << " (应为7/3)" << endl;
    cout << "--f5 = " << --f5 << " (应为4/3)" << endl;
    cout << "f5 = " << f5 << " (应为4/3)" << endl;
    cout << "f5-- = " << f5-- << " (应为4/3)" << endl;
    cout << "f5 = " << f5 << " (应为1/3)" << endl;

    cout << "\n========== 测试下标运算符 ==========" << endl;
    cout << "f1[0] = " << f1[0] << ", f1[1] = " << f1[1] << endl;
    f1[0] = 2;  // 修改分子
    cout << "修改后 f1 = " << f1 << " (应为2/2，约分后为1/1)" << endl;

    cout << "\n========== 测试函数调用运算符 ==========" << endl;
    Fraction f7(3, 4);
    cout << "f7 = " << f7 << endl;
    cout << "f7() = " << f7() << " (应为0.75)" << endl;
    cout << "f7(2) = " << f7(2) << " (应为0.5625，即0.75的平方)" << endl;

    cout << "\n========== 测试类型转换 ==========" << endl;
    double d1 = static_cast<double>(f2);
    double d2 = f2;  // 隐式转换
    cout << "static_cast<double>(f2) = " << d1 << " (应为0.75)" << endl;
    cout << "f2隐式转换为double = " << d2 << " (应为0.75)" << endl;

    Fraction zero(0, 5);
    if (static_cast<bool>(zero)) {
        cout << "zero是非零值" << endl;
    } else {
        cout << "zero是零值 (正确)" << endl;
    }

    cout << "\n========== 测试一元运算符 ==========" << endl;
    Fraction f8(3, 4);
    cout << "f8 = " << f8 << endl;
    cout << "-f8 = " << -f8 << " (应为-3/4)" << endl;
    cout << "+f8 = " << +f8 << " (应为3/4)" << endl;

    cout << "\n========== 测试链式运算 ==========" << endl;
    Fraction result = f2 + f3 * Fraction(2, 3) - Fraction(1, 4);
    cout << "3/4 + 3/4 * 2/3 - 1/4 = " << result << " (应为1/1)" << endl;

    cout << "\n========== 测试边界情况 ==========" << endl;
    cout << "0/5 = " << zero << " (应为0/1)" << endl;

    Fraction negative(-3, 4);
    cout << "-3/4 = " << negative << endl;

    Fraction negative2(3, -4);
    cout << "3/-4 = " << negative2 << " (分母应转正，显示-3/4)" << endl;

    Fraction large(100, 150);
    cout << "100/150 = " << large << " (约分后应为2/3)" << endl;

    cout << "\n========== 测试异常处理 ==========" << endl;
    try {
        Fraction invalid(1, 0);
    } catch (const invalid_argument& e) {
        cout << "捕获异常：" << e.what() << endl;
    }

    try {
        Fraction f9(1, 2);
        Fraction f10(0, 1);
        Fraction result2 = f9 / f10;
    } catch (const invalid_argument& e) {
        cout << "捕获异常：" << e.what() << endl;
    }

    try {
        Fraction f11(1, 2);
        int x = f11[2];  // 下标越界
    } catch (const out_of_range& e) {
        cout << "捕获异常：" << e.what() << endl;
    }

    cout << "\n========== 测试输入运算符 ==========" << endl;
    cout << "请输入一个分数（格式：分子/分母）：";
    Fraction f6;
    // 取消下面的注释来测试输入
    // cin >> f6;
    // cout << "你输入的分数是：" << f6 << endl;
    // cout << "小数值为：" << f6() << endl;

    cout << "\n========== 综合测试 ==========" << endl;
    Fraction a(1, 2), b(1, 3), c(1, 6);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    Fraction sum = a + b + c;
    cout << "a + b + c = " << sum << " (应为1/1)" << endl;

    Fraction product = a * b * c;
    cout << "a * b * c = " << product << " (应为1/36)" << endl;

    bool comparison = (a > b) && (b > c);
    cout << "(a > b) && (b > c) = " << (comparison ? "true" : "false") << " (应为true)" << endl;

    cout << "\n========== 测试完成 ==========" << endl;

    return 0;
}
