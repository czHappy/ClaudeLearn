/**
 * 实验：结构体 - 学生信息管理系统
 *
 * 学生姓名：________________
 * 学号：________________
 * 完成日期：________________
 *
 * 实验说明：
 * 请完成所有标记 TODO 的代码部分
 * 不要修改已有的函数签名和结构
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ==================== 任务 1：定义 Student 结构体 ====================
// TODO: 定义 Student 结构体
// 成员：id (int), name (string), age (int), gender (char), gpa (double)
struct Student {
    // 在这里填写成员变量

};

// ==================== 任务 2：定义 Course 结构体 ====================
// TODO: 定义 Course 结构体
// 成员：courseId (string), courseName (string), credits (int), hours (int)
struct Course {
    // 在这里填写成员变量

};

// ==================== 任务 3：定义 Enrollment 结构体（结构体嵌套）====================
// TODO: 定义 Enrollment 结构体
// 成员：student (Student), course (Course), score (double)
struct Enrollment {
    // 在这里填写成员变量（使用结构体嵌套）

};

// ==================== 任务 8：内存对齐测试结构体 ====================
// 这两个结构体已经定义好，用于观察内存对齐
struct AlignTest1 {
    char a;
    int b;
    char c;
    double d;
};

struct AlignTest2 {
    double d;
    int b;
    char a;
    char c;
};

// ==================== 任务 5：实现 printStudent 函数 ====================
// TODO: 实现打印学生信息的函数
// 使用 const 引用传递参数
// 输出格式：学号: xxx, 姓名: xxx, 年龄: xxx, 性别: x, GPA: x.xx
void printStudent(const Student& s) {
    // 在这里实现函数

}

// ==================== 任务 6：实现 updateStudentAge 函数 ====================
// TODO: 实现修改学生年龄的函数
// 使用引用传递以便修改原数据
void updateStudentAge(Student& s, int newAge) {
    // 在这里实现函数

}

// ==================== 任务 7：实现 findStudentById 函数 ====================
// TODO: 实现根据学号查找学生的函数
// 找到返回指向该学生的指针，未找到返回 nullptr
Student* findStudentById(Student students[], int size, int id) {
    // 在这里实现函数

    return nullptr;  // 未找到
}

// ==================== 主函数 ====================
int main() {
    cout << "========== 学生信息管理系统 ==========" << endl << endl;

    // ==================== 任务 4：创建并初始化结构体数组 ====================
    // TODO: 创建包含 5 个学生的数组，使用聚合初始化
    // 示例数据：
    // 1001, "张三", 20, 'M', 3.85
    // 1002, "李四", 21, 'F', 3.72
    // 1003, "王五", 19, 'M', 3.90
    // 1004, "赵六", 22, 'F', 3.65
    // 1005, "钱七", 20, 'M', 3.78

    Student students[5] = {
        // 在这里初始化 5 个学生

    };

    // 输出所有学生信息
    cout << "--- 所有学生信息 ---" << endl;
    // TODO: 遍历数组，使用 printStudent 函数输出每个学生信息


    cout << endl;

    // ==================== 测试任务 6：修改学生年龄 ====================
    cout << "--- 修改学生年龄测试 ---" << endl;
    cout << "修改前: ";
    printStudent(students[0]);

    // TODO: 调用 updateStudentAge 将第一个学生年龄改为 21


    cout << "修改后: ";
    printStudent(students[0]);
    cout << endl;

    // ==================== 测试任务 7：查找学生 ====================
    cout << "--- 查找学生测试 ---" << endl;

    // TODO: 使用 findStudentById 查找学号为 1003 的学生
    // 如果找到，使用 -> 运算符输出学生姓名
    // 如果未找到，输出 "未找到该学生"


    // TODO: 查找一个不存在的学号（如 9999）


    cout << endl;

    // ==================== 测试任务 3：结构体嵌套 ====================
    cout << "--- 结构体嵌套测试 ---" << endl;

    // TODO: 创建一个 Enrollment 记录
    // 学生：使用 students[0]
    // 课程：{"CS101", "程序设计", 4, 64}
    // 成绩：92.5
    Enrollment enrollment;
    // 在这里初始化 enrollment


    // TODO: 输出选课信息
    // 格式：学生 xxx 选修了 xxx 课程，成绩：xx.x


    cout << endl;

    // ==================== 测试任务 8：内存对齐 ====================
    cout << "--- 内存对齐测试 ---" << endl;

    // TODO: 输出两个测试结构体的大小
    cout << "AlignTest1 大小: " << sizeof(AlignTest1) << " 字节" << endl;
    cout << "AlignTest2 大小: " << sizeof(AlignTest2) << " 字节" << endl;

    // TODO: 在下面的注释中分析为什么两个结构体大小不同
    /*
     * 内存对齐分析：
     *
     * AlignTest1 的内存布局：
     * （在这里填写你的分析）
     *
     * AlignTest2 的内存布局：
     * （在这里填写你的分析）
     *
     * 结论：
     * （在这里填写你的结论）
     */

    cout << endl;

    // ==================== 附加：使用指针访问成员 ====================
    cout << "--- 指针访问成员演示 ---" << endl;

    Student* pStudent = &students[1];
    // TODO: 使用 -> 运算符输出该学生的姓名和 GPA
    // 格式：通过指针访问: 姓名=xxx, GPA=x.xx


    cout << endl;
    cout << "========== 程序结束 ==========" << endl;

    return 0;
}
