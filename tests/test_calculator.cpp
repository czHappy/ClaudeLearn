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

void testLogarithm() {
    Calculator calc;

    // 测试用例1: 自然对数 ln(e) = 1
    assert(almostEqual(calc.ln(M_E), 1.0));

    // 测试用例2: 自然对数 ln(1) = 0
    assert(almostEqual(calc.ln(1.0), 0.0));

    // 测试用例3: 自然对数 ln(e^2) ≈ 2
    assert(almostEqual(calc.ln(M_E * M_E), 2.0));

    // 测试用例4: 常用对数 log10(10) = 1
    assert(almostEqual(calc.log10(10.0), 1.0));

    // 测试用例5: 常用对数 log10(100) = 2
    assert(almostEqual(calc.log10(100.0), 2.0));

    // 测试用例6: 常用对数 log10(1) = 0
    assert(almostEqual(calc.log10(1.0), 0.0));

    // 测试用例7: 任意底数对数 log_2(8) = 3
    assert(almostEqual(calc.log(8.0, 2.0), 3.0));

    // 测试用例8: 任意底数对数 log_2(16) = 4
    assert(almostEqual(calc.log(16.0, 2.0), 4.0));

    // 测试用例9: 任意底数对数 log_3(27) = 3
    assert(almostEqual(calc.log(27.0, 3.0), 3.0));

    // 测试用例10: ln(负数) 应该抛出异常
    try {
        calc.ln(-1.0);
        assert(false && "Should have thrown exception for ln of negative number");
    } catch (const std::invalid_argument& e) {
        std::cout << "  Caught expected exception: " << e.what() << std::endl;
    }

    // 测试用例11: ln(0) 应该抛出异常
    try {
        calc.ln(0.0);
        assert(false && "Should have thrown exception for ln of zero");
    } catch (const std::invalid_argument& e) {
        std::cout << "  Caught expected exception: " << e.what() << std::endl;
    }

    // 测试用例12: log(x, 1) 应该抛出异常
    try {
        calc.log(10.0, 1.0);
        assert(false && "Should have thrown exception for base = 1");
    } catch (const std::invalid_argument& e) {
        std::cout << "  Caught expected exception: " << e.what() << std::endl;
    }

    // 测试用例13: log(x, 负数) 应该抛出异常
    try {
        calc.log(10.0, -2.0);
        assert(false && "Should have thrown exception for negative base");
    } catch (const std::invalid_argument& e) {
        std::cout << "  Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "✓ Logarithm tests passed" << std::endl;
}

int main() {
    std::cout << "Running Calculator Unit Tests..." << std::endl;
    std::cout << "================================" << std::endl;

    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    testLogarithm();

    std::cout << "================================" << std::endl;
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
