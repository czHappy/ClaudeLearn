cmake_minimum_required(VERSION 3.10)
project(CalculatorProject VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 创建Calculator库
add_library(calculator_lib
    src/Calculator.cpp
)

# 创建测试可执行文件
add_executable(test_calculator
    tests/test_calculator.cpp
)

# 链接库到测试可执行文件
target_link_libraries(test_calculator calculator_lib)

# 启用测试
enable_testing()

# 添加测试
add_test(NAME CalculatorTest COMMAND test_calculator)
