#include "Calculator.h"
#include <cmath>

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return a / b;
}

double Calculator::ln(double x) {
    if (x <= 0.0) {
        throw std::invalid_argument("Logarithm of non-positive number is undefined");
    }
    return std::log(x);
}

double Calculator::log10(double x) {
    if (x <= 0.0) {
        throw std::invalid_argument("Logarithm of non-positive number is undefined");
    }
    return std::log10(x);
}

double Calculator::log(double x, double base) {
    if (x <= 0.0) {
        throw std::invalid_argument("Logarithm of non-positive number is undefined");
    }
    if (base <= 0.0 || base == 1.0) {
        throw std::invalid_argument("Logarithm base must be positive and not equal to 1");
    }
    return std::log(x) / std::log(base);
}
