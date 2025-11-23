/**
 * 实验：结构体 - 学生信息管理系统
 * 标准答案
 *
 * 本文件包含所有任务的完整实现
 * 编译命令: g++ -std=c++11 -o answer answer.cpp
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ==================== 任务 1：定义 Student 结构体 ====================
// 学生基本信息结构体
struct Student {
    int id;           // 学号
    string name;      // 姓名
    int age;          // 年龄
    char gender;      // 性别：'M' 男，'F' 女
    double gpa;       // 平均绩点
};

// ==================== 任务 2：定义 Course 结构体 ====================
// 课程信息结构体
struct Course {
    string courseId;    // 课程编号
    string courseName;  // 课程名称
    int credits;        // 学分
    int hours;          // 课时
};

// ==================== 任务 3：定义 Enrollment 结构体（结构体嵌套）====================
// 选课信息结构体（嵌套了 Student 和 Course）
struct Enrollment {
    Student student;    // 学生信息（结构体嵌套）
    Course course;      // 课程信息（结构体嵌套）
    double score;       // 成绩
};

// ==================== 任务 8：内存对齐测试结构体 ====================
// 内存对齐测试结构体 1（成员排列未优化）
struct AlignTest1 {
    char a;      // 1 字节，偏移 0
    // 填充 3 字节（使 int 对齐到 4 字节边界）
    int b;       // 4 字节，偏移 4
    char c;      // 1 字节，偏移 8
    // 填充 7 字节（使 double 对齐到 8 字节边界）
    double d;    // 8 字节，偏移 16
    // 总大小：24 字节
};

// 内存对齐测试结构体 2（成员排列已优化）
struct AlignTest2 {
    double d;    // 8 字节，偏移 0
    int b;       // 4 字节，偏移 8
    char a;      // 1 字节，偏移 12
    char c;      // 1 字节，偏移 13
    // 填充 2 字节（使总大小为 8 的倍数）
    // 总大小：16 字节
};

// ==================== 任务 5：实现 printStudent 函数 ====================
// 使用 const 引用传递，高效且安全
// const 保证不会修改原数据，引用避免复制开销
void printStudent(const Student& s) {
    cout << "学号: " << s.id
         << ", 姓名: " << s.name
         << ", 年龄: " << s.age
         << ", 性别: " << s.gender
         << ", GPA: " << fixed << setprecision(2) << s.gpa
         << endl;
}

// ==================== 任务 6：实现 updateStudentAge 函数 ====================
// 使用非 const 引用，可以修改原数据
void updateStudentAge(Student& s, int newAge) {
    s.age = newAge;  // 直接修改原结构体的成员
}

// ==================== 任务 7：实现 findStudentById 函数 ====================
// 返回指针，找到返回指向该元素的指针，未找到返回 nullptr
Student* findStudentById(Student students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            return &students[i];  // 返回指向找到的学生的指针
        }
    }
    return nullptr;  // 未找到返回空指针
}

// 附加函数：打印课程信息
void printCourse(const Course& c) {
    cout << "课程编号: " << c.courseId
         << ", 课程名: " << c.courseName
         << ", 学分: " << c.credits
         << ", 课时: " << c.hours
         << endl;
}

// 附加函数：打印选课信息
void printEnrollment(const Enrollment& e) {
    cout << "学生 " << e.student.name
         << " 选修了 " << e.course.courseName
         << " 课程，成绩：" << fixed << setprecision(1) << e.score
         << endl;
}

// ==================== 主函数 ====================
int main() {
    cout << "========== 学生信息管理系统 ==========" << endl << endl;

    // ==================== 任务 4：创建并初始化结构体数组 ====================
    // 使用聚合初始化创建学生数组
    Student students[5] = {
        {1001, "张三", 20, 'M', 3.85},
        {1002, "李四", 21, 'F', 3.72},
        {1003, "王五", 19, 'M', 3.90},
        {1004, "赵六", 22, 'F', 3.65},
        {1005, "钱七", 20, 'M', 3.78}
    };

    // 遍历输出所有学生信息
    cout << "--- 所有学生信息 ---" << endl;
    for (int i = 0; i < 5; i++) {
        printStudent(students[i]);
    }
    cout << endl;

    // ==================== 测试任务 6：修改学生年龄 ====================
    cout << "--- 修改学生年龄测试 ---" << endl;
    cout << "修改前: ";
    printStudent(students[0]);

    updateStudentAge(students[0], 21);  // 修改年龄

    cout << "修改后: ";
    printStudent(students[0]);
    cout << endl;

    // ==================== 测试任务 7：查找学生 ====================
    cout << "--- 查找学生测试 ---" << endl;

    // 查找存在的学生
    Student* found = findStudentById(students, 5, 1003);
    if (found != nullptr) {
        cout << "查找学号 1003: 找到学生 - " << found->name << endl;
        // 演示使用 -> 运算符访问成员
        cout << "  使用指针访问: ID=" << found->id
             << ", GPA=" << found->gpa << endl;
    } else {
        cout << "查找学号 1003: 未找到该学生" << endl;
    }

    // 查找不存在的学生
    Student* notFound = findStudentById(students, 5, 9999);
    if (notFound != nullptr) {
        cout << "查找学号 9999: 找到学生 - " << notFound->name << endl;
    } else {
        cout << "查找学号 9999: 未找到该学生" << endl;
    }
    cout << endl;

    // ==================== 测试任务 3：结构体嵌套 ====================
    cout << "--- 结构体嵌套测试 ---" << endl;

    // 创建课程
    Course cs101 = {"CS101", "程序设计", 4, 64};

    // 创建选课记录（使用结构体嵌套）
    Enrollment enrollment = {
        students[0],   // 嵌套的 Student 结构体
        cs101,         // 嵌套的 Course 结构体
        92.5           // 成绩
    };

    // 输出选课信息
    printEnrollment(enrollment);

    // 演示访问嵌套结构体的成员
    cout << "访问嵌套成员: " << endl;
    cout << "  学生学号: " << enrollment.student.id << endl;
    cout << "  学生姓名: " << enrollment.student.name << endl;
    cout << "  课程名称: " << enrollment.course.courseName << endl;
    cout << "  课程学分: " << enrollment.course.credits << endl;
    cout << endl;

    // ==================== 测试任务 8：内存对齐 ====================
    cout << "--- 内存对齐测试 ---" << endl;

    cout << "AlignTest1 大小: " << sizeof(AlignTest1) << " 字节" << endl;
    cout << "AlignTest2 大小: " << sizeof(AlignTest2) << " 字节" << endl;
    cout << endl;

    /*
     * 内存对齐分析：
     *
     * AlignTest1 的内存布局（24 字节）：
     * +----+---+---+---+----+----+----+----+----+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+
     * | a  | P | P | P |   b (4字节)       | c  | P | P | P | P | P | P | P |       d (8字节)                       |
     * +----+---+---+---+----+----+----+----+----+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+
     * 偏移: 0    1   2   3    4    5    6    7    8   9  10  11  12  13  14  15   16   17   18   19   20   21   22   23
     *
     * - char a: 1 字节，偏移 0
     * - padding: 3 字节（int 需要 4 字节对齐）
     * - int b: 4 字节，偏移 4
     * - char c: 1 字节，偏移 8
     * - padding: 7 字节（double 需要 8 字节对齐）
     * - double d: 8 字节，偏移 16
     * - 总计：24 字节
     *
     * AlignTest2 的内存布局（16 字节）：
     * +----+----+----+----+----+----+----+----+----+----+----+----+----+----+---+---+
     * |       d (8字节)                       |   b (4字节)       | a  | c  | P | P |
     * +----+----+----+----+----+----+----+----+----+----+----+----+----+----+---+---+
     * 偏移: 0    1    2    3    4    5    6    7    8    9   10   11   12   13  14  15
     *
     * - double d: 8 字节，偏移 0
     * - int b: 4 字节，偏移 8
     * - char a: 1 字节，偏移 12
     * - char c: 1 字节，偏移 13
     * - padding: 2 字节（结构体总大小需要是最大成员 double 的倍数，即 8 的倍数）
     * - 总计：16 字节
     *
     * 结论：
     * 通过按照成员大小从大到小排列（double -> int -> char），
     * 可以有效减少填充字节，从而减小结构体的总大小。
     * AlignTest2 比 AlignTest1 节省了 8 字节（33%）。
     */

    // 输出详细的内存布局分析
    cout << "--- 内存布局详细分析 ---" << endl;
    cout << "AlignTest1:" << endl;
    cout << "  char a    : 1 字节 (偏移 0)" << endl;
    cout << "  padding   : 3 字节" << endl;
    cout << "  int b     : 4 字节 (偏移 4)" << endl;
    cout << "  char c    : 1 字节 (偏移 8)" << endl;
    cout << "  padding   : 7 字节" << endl;
    cout << "  double d  : 8 字节 (偏移 16)" << endl;
    cout << "  总计      : 24 字节" << endl;
    cout << endl;
    cout << "AlignTest2:" << endl;
    cout << "  double d  : 8 字节 (偏移 0)" << endl;
    cout << "  int b     : 4 字节 (偏移 8)" << endl;
    cout << "  char a    : 1 字节 (偏移 12)" << endl;
    cout << "  char c    : 1 字节 (偏移 13)" << endl;
    cout << "  padding   : 2 字节" << endl;
    cout << "  总计      : 16 字节" << endl;
    cout << endl;

    // ==================== 附加：使用指针访问成员 ====================
    cout << "--- 指针访问成员演示 ---" << endl;

    Student* pStudent = &students[1];

    // 使用 -> 运算符访问成员
    cout << "通过指针访问: 姓名=" << pStudent->name
         << ", GPA=" << pStudent->gpa << endl;

    // -> 运算符等价于 (*ptr).member
    cout << "等价写法: 姓名=" << (*pStudent).name
         << ", GPA=" << (*pStudent).gpa << endl;

    cout << endl;

    // ==================== 附加演示：各种初始化方式 ====================
    cout << "--- 结构体初始化方式演示 ---" << endl;

    // 方式 1：逐个成员赋值
    Student s1;
    s1.id = 2001;
    s1.name = "初始化方式1";
    s1.age = 25;
    s1.gender = 'M';
    s1.gpa = 3.50;
    cout << "方式1（逐个赋值）: ";
    printStudent(s1);

    // 方式 2：聚合初始化
    Student s2 = {2002, "初始化方式2", 26, 'F', 3.60};
    cout << "方式2（聚合初始化）: ";
    printStudent(s2);

    // 方式 3：C++11 统一初始化
    Student s3{2003, "初始化方式3", 27, 'M', 3.70};
    cout << "方式3（统一初始化）: ";
    printStudent(s3);

    cout << endl;

    // ==================== 附加演示：结构体大小 ====================
    cout << "--- 各结构体大小 ---" << endl;
    cout << "sizeof(Student)    : " << sizeof(Student) << " 字节" << endl;
    cout << "sizeof(Course)     : " << sizeof(Course) << " 字节" << endl;
    cout << "sizeof(Enrollment) : " << sizeof(Enrollment) << " 字节" << endl;

    cout << endl;
    cout << "========== 程序结束 ==========" << endl;

    return 0;
}
