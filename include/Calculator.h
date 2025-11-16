#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>

class Calculator {
public:
    // 加法
    double add(double a, double b);

    // 减法
    double subtract(double a, double b);

    // 乘法
    double multiply(double a, double b);

    // 除法 (会抛出异常如果除数为0)
    double divide(double a, double b);

    // 自然对数 ln(x) - 以e为底的对数
    double ln(double x);

    // 常用对数 log10(x) - 以10为底的对数
    double log10(double x);

    // 任意底数的对数 log_b(x) - 以b为底x的对数
    double log(double x, double base);
};

#endif // CALCULATOR_H
