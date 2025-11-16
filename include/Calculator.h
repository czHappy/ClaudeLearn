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
};

#endif // CALCULATOR_H
