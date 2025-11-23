/**
 * 实验：自定义排序
 * 主题：考试成绩排序系统
 *
 * 标准答案
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

    // 创建整数数组
    vector<int> scores = {85, 92, 78, 95, 88, 76, 90};

    // 升序排序
    sort(scores.begin(), scores.end());

    // 输出升序结果
    cout << "升序: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;

    // 降序排序
    sort(scores.begin(), scores.end(), greater<int>());

    // 输出降序结果
    cout << "降序: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl << endl;
}

// ==================== 任务2：函数比较器 ====================

// 比较函数：按总分降序排序
bool compareByScore(const Student& a, const Student& b) {
    return a.total > b.total;  // 总分高的排前面
}

void sortByFunction() {
    cout << "===== 任务2：函数比较器 =====" << endl;

    // 创建学生数组
    vector<Student> students = {
        Student(1001, "张三", 95, 90),   // 总分185
        Student(1002, "李四", 85, 90),   // 总分175
        Student(1003, "王五", 98, 97)    // 总分195
    };

    // 使用函数比较器排序
    sort(students.begin(), students.end(), compareByScore);

    // 输出排序后的结果
    for (const auto& s : students) {
        cout << "学号: " << s.id << ", 姓名: " << s.name << ", 总分: " << s.total << endl;
    }
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

    // 使用 Lambda 表达式按数学成绩降序排序
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.math > b.math;
    });

    // 输出结果
    for (const auto& s : students) {
        cout << "学号: " << s.id << ", 数学: " << s.math << endl;
    }
    cout << endl;

    // ----- 3.2 按英语成绩升序 -----
    cout << "按英语成绩升序:" << endl;

    // 使用 Lambda 表达式按英语成绩升序排序
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.english < b.english;
    });

    // 输出结果
    for (const auto& s : students) {
        cout << "学号: " << s.id << ", 英语: " << s.english << endl;
    }
    cout << endl;

    // ----- 3.3 按姓名字典序 -----
    cout << "按姓名字典序:" << endl;

    // 使用 Lambda 表达式按姓名字典序排序
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
    });

    // 输出结果
    for (const auto& s : students) {
        cout << "姓名: " << s.name << endl;
    }
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

    // 多关键字排序：先按总分降序，总分相同按学号升序
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.total != b.total) {
            return a.total > b.total;  // 总分降序
        }
        return a.id < b.id;  // 学号升序
    });

    // 输出排名结果
    for (size_t i = 0; i < students.size(); i++) {
        cout << "排名" << (i + 1) << ": 学号" << students[i].id
             << ", 总分" << students[i].total << endl;
    }
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

    // 排行榜排序规则
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // 1. 总分高的排前面
        if (a.total != b.total) {
            return a.total > b.total;
        }
        // 2. 总分相同时，数学成绩高的排前面
        if (a.math != b.math) {
            return a.math > b.math;
        }
        // 3. 数学成绩也相同时，学号小的排前面
        return a.id < b.id;
    });

    // 输出排行榜
    cout << "=== 成绩排行榜 ===" << endl;
    cout << "排名  学号    姓名    数学  英语  总分" << endl;

    // 遍历输出每个学生的排名信息
    for (size_t i = 0; i < students.size(); i++) {
        const auto& s = students[i];
        cout << left << setw(6) << (i + 1)          // 排名
             << setw(8) << s.id                     // 学号
             << setw(8) << s.name                   // 姓名
             << setw(6) << s.math                   // 数学
             << setw(6) << s.english                // 英语
             << setw(6) << s.total << endl;         // 总分
    }
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
