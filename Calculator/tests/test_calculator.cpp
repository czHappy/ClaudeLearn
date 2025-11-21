#include "Calculator.h"
#include <iostream>
#include <cassert>
#include <cmath>

// 浮点数比较辅助函数
bool almostEqual(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

void testAddition() {
    Calculator calc;

    // 测试用例1: 正数相加
    assert(almostEqual(calc.add(5.0, 3.0), 8.0));

    // 测试用例2: 负数相加
    assert(almostEqual(calc.add(-5.0, -3.0), -8.0));

    // 测试用例3: 正负数相加
    assert(almostEqual(calc.add(5.0, -3.0), 2.0));

    // 测试用例4: 零相加
    assert(almostEqual(calc.add(0.0, 5.0), 5.0));

    std::cout << "✓ Addition tests passed" << std::endl;
}

void testSubtraction() {
    Calculator calc;

    // 测试用例1: 正数相减
    assert(almostEqual(calc.subtract(10.0, 3.0), 7.0));

    // 测试用例2: 负数相减
    assert(almostEqual(calc.subtract(-5.0, -3.0), -2.0));

    // 测试用例3: 正负数相减
    assert(almostEqual(calc.subtract(5.0, -3.0), 8.0));

    // 测试用例4: 零相减
    assert(almostEqual(calc.subtract(0.0, 5.0), -5.0));

    std::cout << "✓ Subtraction tests passed" << std::endl;
}

void testMultiplication() {
    Calculator calc;

    // 测试用例1: 正数相乘
    assert(almostEqual(calc.multiply(5.0, 3.0), 15.0));

    // 测试用例2: 负数相乘
    assert(almostEqual(calc.multiply(-5.0, -3.0), 15.0));

    // 测试用例3: 正负数相乘
    assert(almostEqual(calc.multiply(5.0, -3.0), -15.0));

    // 测试用例4: 零相乘
    assert(almostEqual(calc.multiply(0.0, 5.0), 0.0));

    std::cout << "✓ Multiplication tests passed" << std::endl;
}

void testDivision() {
    Calculator calc;

    // 测试用例1: 正数相除
    assert(almostEqual(calc.divide(10.0, 2.0), 5.0));

    // 测试用例2: 负数相除
    assert(almostEqual(calc.divide(-10.0, -2.0), 5.0));

    // 测试用例3: 正负数相除
    assert(almostEqual(calc.divide(10.0, -2.0), -5.0));

    // 测试用例4: 除以零应该抛出异常
    try {
        calc.divide(10.0, 0.0);
        assert(false && "Should have thrown exception for division by zero");
    } catch (const std::invalid_argument& e) {
        std::cout << "  Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "✓ Division tests passed" << std::endl;
}

int main() {
    std::cout << "Running Calculator Unit Tests..." << std::endl;
    std::cout << "================================" << std::endl;

    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();

    std::cout << "================================" << std::endl;
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
