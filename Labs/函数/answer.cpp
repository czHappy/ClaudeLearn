#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ========== 函数声明 ==========
int add(int a, int b);
double add(double a, double b);
int factorial(int n);

int abs(int x);
double abs(double x);
long long abs(long long x);

int max(int a, int b);
int max(int a, int b, int c);
double max(double a, double b);

void print(int x);
void print(double x);
void print(const char* str);

double power(double base, int exp = 2);
void format(double value, int precision = 2, bool showSign = false);
void printRange(int start, int end, int step = 1);

int fibonacci(int n);
int gcd(int a, int b);
int sumDigits(int n);
void printBinary(int n);

// ========== 内联函数 ==========
inline int square(int x) { return x * x; }
inline int cube(int x) { return x * x * x; }
inline bool isEven(int x) { return x % 2 == 0; }
inline bool isOdd(int x) { return x % 2 != 0; }
inline int min(int a, int b) { return a < b ? a : b; }

// ========== 主函数 ==========
int main() {
    cout << "======= 计算器工厂 =======\n" << endl;

    cout << "=== 函数重载演示 ===" << endl;
    cout << "abs(-5) = " << abs(-5) << endl;
    cout << "abs(-3.14) = " << abs(-3.14) << endl;
    cout << "abs(-1000000000LL) = " << abs(-1000000000LL) << endl;

    cout << "\nmax(3, 7) = " << max(3, 7) << endl;
    cout << "max(3, 7, 5) = " << max(3, 7, 5) << endl;
    cout << "max(3.14, 2.72) = " << max(3.14, 2.72) << endl;

    cout << "\nprint(42)   -> ";
    print(42);
    cout << "print(3.14) -> ";
    print(3.14);
    cout << "print(\"Hi\")  -> ";
    print("Hi");

    cout << "\n=== 默认参数演示 ===" << endl;
    cout << "power(3) = " << power(3) << "        // 默认计算平方" << endl;
    cout << "power(2, 10) = " << power(2, 10) << " // 指定指数" << endl;

    cout << "\nformat(3.14159)           -> ";
    format(3.14159);
    cout << "format(3.14159, 4)        -> ";
    format(3.14159, 4);
    cout << "format(3.14159, 2, true)  -> ";
    format(3.14159, 2, true);

    cout << "\nprintRange(1, 5)    -> ";
    printRange(1, 5);
    cout << "printRange(0, 10, 2) -> ";
    printRange(0, 10, 2);

    cout << "\n=== 内联函数演示 ===" << endl;
    cout << "square(5) = " << square(5) << endl;
    cout << "cube(3) = " << cube(3) << endl;
    cout << "isEven(4) = " << (isEven(4) ? "true" : "false") << endl;
    cout << "isOdd(4) = " << (isOdd(4) ? "true" : "false") << endl;
    cout << "min(10, 20) = " << min(10, 20) << endl;

    cout << "\n=== 递归函数演示 ===" << endl;
    cout << "fibonacci(10) = " << fibonacci(10) << endl;
    cout << "gcd(48, 18) = " << gcd(48, 18) << endl;
    cout << "sumDigits(12345) = " << sumDigits(12345) << endl;
    cout << "printBinary(13) -> ";
    printBinary(13);
    cout << endl;

    return 0;
}

// ========== 基本函数实现 ==========
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// ========== 函数重载实现 ==========
int abs(int x) {
    return x < 0 ? -x : x;
}

double abs(double x) {
    return x < 0 ? -x : x;
}

long long abs(long long x) {
    return x < 0 ? -x : x;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

double max(double a, double b) {
    return a > b ? a : b;
}

void print(int x) {
    cout << "整数: " << x << endl;
}

void print(double x) {
    cout << "浮点数: " << x << endl;
}

void print(const char* str) {
    cout << "字符串: " << str << endl;
}

// ========== 默认参数函数实现 ==========
double power(double base, int exp) {
    double result = 1.0;
    int absExp = abs(exp);
    for (int i = 0; i < absExp; i++) {
        result *= base;
    }
    return exp < 0 ? 1.0 / result : result;
}

void format(double value, int precision, bool showSign) {
    cout << fixed << setprecision(precision);
    if (showSign && value >= 0) {
        cout << "+";
    }
    cout << value << endl;
}

void printRange(int start, int end, int step) {
    for (int i = start; i <= end; i += step) {
        cout << i;
        if (i + step <= end) cout << " ";
    }
    cout << endl;
}

// ========== 递归函数实现 ==========
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int sumDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}

void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    cout << n % 2;
}
