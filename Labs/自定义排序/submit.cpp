/**
 * 实验：自定义排序
 * 主题：考试成绩排序系统
 *
 * 请完成下方所有 TODO 部分
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// 学生结构体
struct Student {
    int id;          // 学号
    string name;     // 姓名
    int math;        // 数学成绩
    int english;     // 英语成绩
    int total;       // 总分

    // 构造函数
    Student(int _id, string _name, int _math, int _english)
        : id(_id), name(_name), math(_math), english(_english) {
        total = math + english;
    }
};

// ==================== 任务1：基本排序 ====================
void sortBasic() {
    cout << "===== 任务1：基本排序 =====" << endl;

    // TODO: 创建整数数组 {85, 92, 78, 95, 88, 76, 90}
    vector<int> scores;

    // TODO: 使用 std::sort 升序排序

    // TODO: 输出升序结果，格式："升序: 76 78 85 88 90 92 95"
    cout << "升序: ";

    cout << endl;

    // TODO: 使用 std::sort 和 std::greater<int>() 降序排序

    // TODO: 输出降序结果，格式："降序: 95 92 90 88 85 78 76"
    cout << "降序: ";

    cout << endl << endl;
}

// ==================== 任务2：函数比较器 ====================

// TODO: 实现比较函数，按总分降序排序
// 函数签名：bool compareByScore(const Student& a, const Student& b)


void sortByFunction() {
    cout << "===== 任务2：函数比较器 =====" << endl;

    // TODO: 创建学生数组（至少3个学生）
    vector<Student> students;

    // TODO: 使用 compareByScore 函数排序

    // TODO: 输出排序后的结果
    // 格式：学号: 1003, 姓名: 王五, 总分: 195

    cout << endl;
}

// ==================== 任务3：Lambda 比较器 ====================
void sortByLambda() {
    cout << "===== 任务3：Lambda比较器 =====" << endl;

    // 创建测试数据
    vector<Student> students = {
        Student(1001, "张三", 95, 90),
        Student(1002, "李四", 85, 90),
        Student(1003, "王五", 98, 97)
    };

    // ----- 3.1 按数学成绩降序 -----
    cout << "按数学成绩降序:" << endl;

    // TODO: 使用 Lambda 表达式按数学成绩降序排序

    // TODO: 输出结果，格式：学号: 1003, 数学: 98

    cout << endl;

    // ----- 3.2 按英语成绩升序 -----
    cout << "按英语成绩升序:" << endl;

    // TODO: 使用 Lambda 表达式按英语成绩升序排序

    // TODO: 输出结果，格式：学号: 1002, 英语: 90

    cout << endl;

    // ----- 3.3 按姓名字典序 -----
    cout << "按姓名字典序:" << endl;

    // TODO: 使用 Lambda 表达式按姓名字典序排序

    // TODO: 输出结果，格式：姓名: 李四

    cout << endl;
}

// ==================== 任务4：多关键字排序 ====================
void sortMultiKey() {
    cout << "===== 任务4：多关键字排序 =====" << endl;

    // 创建测试数据
    vector<Student> students = {
        Student(1001, "张三", 95, 90),   // 总分185
        Student(1002, "李四", 85, 90),   // 总分175
        Student(1003, "王五", 98, 97),   // 总分195
        Student(1004, "赵六", 85, 100)   // 总分185
    };

    // TODO: 使用 Lambda 实现多关键字排序
    // 规则：先按总分降序，总分相同按学号升序

    // TODO: 输出排名结果
    // 格式：排名1: 学号1003, 总分195

    cout << endl;
}

// ==================== 任务5：综合应用 - 排行榜系统 ====================
void rankingSystem() {
    cout << "===== 任务5：排行榜系统 =====" << endl;

    // 创建测试数据
    vector<Student> students = {
        Student(1001, "张三", 95, 90),   // 总分185
        Student(1002, "李四", 85, 90),   // 总分175
        Student(1003, "王五", 98, 97),   // 总分195
        Student(1004, "赵六", 85, 95),   // 总分180
        Student(1005, "钱七", 90, 90)    // 总分180
    };

    // TODO: 实现排行榜排序规则
    // 1. 总分高的排前面
    // 2. 总分相同时，数学成绩高的排前面
    // 3. 数学成绩也相同时，学号小的排前面

    // TODO: 输出排行榜
    cout << "=== 成绩排行榜 ===" << endl;
    cout << "排名  学号    姓名    数学  英语  总分" << endl;

    // TODO: 遍历输出每个学生的排名信息
    // 使用 setw 进行格式化输出

    cout << endl;
}

// ==================== 主函数 ====================
int main() {
    // 运行所有任务
    sortBasic();
    sortByFunction();
    sortByLambda();
    sortMultiKey();
    rankingSystem();

    return 0;
}
