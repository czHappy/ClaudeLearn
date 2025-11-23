/**
 * I/O 重定向实验 - 学生成绩管理系统
 * 标准答案
 *
 * 本程序展示了 C++ I/O 操作的核心知识点：
 * - 文件流（ifstream, ofstream, fstream）
 * - 文件打开模式（in, out, app, binary）
 * - 流状态检测（eof, fail, bad, good）
 * - 格式化输出（setw, setprecision, fixed）
 * - getline 与字符串输入
 * - 二进制文件读写
 * - 字符串流（stringstream）
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// 学生信息结构体
struct Student {
    int id;              // 学号
    char name[20];       // 姓名
    double score;        // 成绩
};

// 文件名常量
const char* TEXT_FILE = "scores.txt";
const char* BINARY_FILE = "students.dat";
const char* CSV_FILE = "students.csv";

// ============================================
// 任务 1：文本文件写入
// 功能：将学生成绩保存到文本文件
// ============================================
bool writeToTextFile(const Student students[], int count) {
    // 使用 ofstream 打开文件（默认为覆盖模式）
    ofstream file(TEXT_FILE);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "错误：无法创建文件 " << TEXT_FILE << endl;
        return false;
    }

    // 将每个学生的信息写入文件
    for (int i = 0; i < count; i++) {
        file << students[i].id << " "
             << students[i].name << " "
             << students[i].score << endl;
    }

    // 文件会在 ofstream 对象销毁时自动关闭
    // 但显式关闭是好习惯
    file.close();

    cout << "成功写入 " << count << " 条记录到 " << TEXT_FILE << endl;
    return true;
}

// ============================================
// 任务 2：文本文件读取
// 功能：从文本文件加载学生成绩
// ============================================
int readFromTextFile(Student students[], int maxCount) {
    // 使用 ifstream 打开文件
    ifstream file(TEXT_FILE);

    // 检查文件是否存在
    if (!file.is_open()) {
        cerr << "错误：文件 " << TEXT_FILE << " 不存在" << endl;
        return 0;
    }

    int count = 0;
    // 循环读取数据，直到文件末尾或达到最大容量
    while (count < maxCount && file >> students[count].id
                            >> students[count].name
                            >> students[count].score) {
        count++;
    }

    // 检测是否正常结束
    if (!file.eof() && count < maxCount) {
        cerr << "警告：文件读取可能未完成" << endl;
    }

    file.close();
    cout << "成功从 " << TEXT_FILE << " 读取 " << count << " 条记录" << endl;
    return count;
}

// ============================================
// 任务 3：追加模式写入
// 功能：向现有文件追加新的学生记录
// ============================================
bool appendToFile(const Student& student) {
    // 使用 ios::app 模式打开文件（追加模式）
    ofstream file(TEXT_FILE, ios::app);

    if (!file.is_open()) {
        cerr << "错误：无法打开文件 " << TEXT_FILE << endl;
        return false;
    }

    // 将学生信息追加到文件末尾
    file << student.id << " "
         << student.name << " "
         << student.score << endl;

    file.close();
    cout << "成功追加学生 " << student.name << " 的记录" << endl;
    return true;
}

// ============================================
// 任务 4：格式化输出
// 功能：以美观的表格形式输出成绩单
// ============================================
void displayFormatted(const Student students[], int count) {
    if (count == 0) {
        cout << "没有学生记录" << endl;
        return;
    }

    // 输出表头
    cout << "\n" << string(40, '=') << endl;
    cout << left << setw(10) << "学号"
         << setw(15) << "姓名"
         << right << setw(10) << "成绩" << endl;
    cout << string(40, '=') << endl;

    // 输出每个学生的信息
    // 使用 fixed 和 setprecision(1) 格式化浮点数
    cout << fixed << setprecision(1);
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << students[i].id
             << setw(15) << students[i].name
             << right << setw(10) << students[i].score << endl;
    }

    // 输出底部分隔线
    cout << string(40, '=') << endl;
    cout << "共 " << count << " 条记录" << endl;
}

// ============================================
// 任务 5：流状态检测
// 功能：安全地读取文件，包含错误处理
// ============================================
int safeReadFile(const char* filename, Student students[], int maxCount) {
    ifstream file(filename);

    // 检测文件是否成功打开
    if (!file.is_open()) {
        cerr << "错误：无法打开文件 " << filename << endl;
        return -1;
    }

    int count = 0;
    while (count < maxCount) {
        // 读取数据
        file >> students[count].id
             >> students[count].name
             >> students[count].score;

        // 检测文件末尾
        if (file.eof()) {
            break;
        }

        // 检测读取错误
        if (file.fail()) {
            cerr << "错误：数据格式错误（第 " << (count + 1) << " 行）" << endl;
            file.clear(); // 清除错误标志
            // 跳过当前行
            file.ignore(1000, '\n');
            continue;
        }

        // 检测严重错误
        if (file.bad()) {
            cerr << "严重错误：文件读取失败" << endl;
            file.close();
            return -1;
        }

        count++;
    }

    // 检测流状态
    if (file.good()) {
        cout << "文件读取完成，流状态正常" << endl;
    }

    file.close();
    return count;
}

// ============================================
// 任务 6：二进制文件写入
// 功能：使用二进制模式保存学生数据
// ============================================
bool writeToBinaryFile(const Student students[], int count) {
    // 使用 ios::binary 模式打开文件
    ofstream file(BINARY_FILE, ios::binary);

    if (!file.is_open()) {
        cerr << "错误：无法创建二进制文件 " << BINARY_FILE << endl;
        return false;
    }

    // 首先写入学生数量
    file.write(reinterpret_cast<const char*>(&count), sizeof(int));

    // 使用 write() 函数写入整个数组
    file.write(reinterpret_cast<const char*>(students), count * sizeof(Student));

    file.close();
    cout << "成功将 " << count << " 条记录保存到二进制文件 " << BINARY_FILE << endl;
    return true;
}

// ============================================
// 任务 6：二进制文件读取
// 功能：从二进制文件加载学生数据
// ============================================
int readFromBinaryFile(Student students[], int maxCount) {
    // 使用 ios::binary 模式打开文件
    ifstream file(BINARY_FILE, ios::binary);

    if (!file.is_open()) {
        cerr << "错误：无法打开二进制文件 " << BINARY_FILE << endl;
        return 0;
    }

    // 首先读取学生数量
    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));

    if (count > maxCount) {
        cerr << "警告：文件包含 " << count << " 条记录，但只能读取 " << maxCount << " 条" << endl;
        count = maxCount;
    }

    // 使用 read() 函数读取数据
    file.read(reinterpret_cast<char*>(students), count * sizeof(Student));

    // 验证读取的字节数
    streamsize bytesRead = file.gcount();
    int actualCount = bytesRead / sizeof(Student);

    if (actualCount != count) {
        cerr << "警告：实际读取 " << actualCount << " 条记录" << endl;
        count = actualCount;
    }

    file.close();
    cout << "成功从二进制文件 " << BINARY_FILE << " 读取 " << count << " 条记录" << endl;
    return count;
}

// ============================================
// 任务 7：字符串流解析
// 功能：解析 CSV 格式的学生数据
// ============================================
bool parseCSV(const string& line, Student& student) {
    // 创建 stringstream 对象
    stringstream ss(line);
    string field;

    // 解析学号
    if (!getline(ss, field, ',')) return false;
    student.id = stoi(field);

    // 解析姓名
    if (!getline(ss, field, ',')) return false;
    strncpy(student.name, field.c_str(), sizeof(student.name) - 1);
    student.name[sizeof(student.name) - 1] = '\0';

    // 解析成绩
    if (!getline(ss, field, ',')) return false;
    student.score = stod(field);

    return true;
}

// ============================================
// 任务 7：从 CSV 文件导入
// 功能：从 CSV 文件加载学生数据
// ============================================
int importFromCSV(Student students[], int maxCount) {
    ifstream file(CSV_FILE);

    if (!file.is_open()) {
        cerr << "错误：无法打开 CSV 文件 " << CSV_FILE << endl;
        return 0;
    }

    string line;
    int count = 0;

    // 跳过表头
    getline(file, line);

    // 逐行读取并解析
    while (count < maxCount && getline(file, line)) {
        if (parseCSV(line, students[count])) {
            count++;
        } else {
            cerr << "警告：无法解析行: " << line << endl;
        }
    }

    file.close();
    cout << "成功从 CSV 文件导入 " << count << " 条记录" << endl;
    return count;
}

// ============================================
// 任务 7：导出为 CSV 格式
// 功能：将学生数据导出为 CSV 文件
// ============================================
bool exportToCSV(const Student students[], int count) {
    ofstream file(CSV_FILE);

    if (!file.is_open()) {
        cerr << "错误：无法创建 CSV 文件 " << CSV_FILE << endl;
        return false;
    }

    // 写入 CSV 表头
    file << "学号,姓名,成绩" << endl;

    // 写入数据
    for (int i = 0; i < count; i++) {
        file << students[i].id << ","
             << students[i].name << ","
             << fixed << setprecision(1) << students[i].score << endl;
    }

    file.close();
    cout << "成功导出 " << count << " 条记录到 " << CSV_FILE << endl;
    return true;
}

// ============================================
// 任务 8：综合应用 - 添加学生
// ============================================
void addStudent(vector<Student>& students) {
    Student s;

    cout << "请输入学号：";
    cin >> s.id;

    cout << "请输入姓名：";
    cin >> s.name;

    cout << "请输入成绩：";
    cin >> s.score;

    // 添加到 vector
    students.push_back(s);

    // 追加到文件
    appendToFile(s);

    cout << "学生添加成功！" << endl;
}

// ============================================
// 任务 8：综合应用 - 显示所有成绩
// ============================================
void displayAll(const vector<Student>& students) {
    if (students.empty()) {
        cout << "没有学生记录" << endl;
        return;
    }
    displayFormatted(students.data(), students.size());
}

// ============================================
// 任务 8：综合应用 - 查找学生
// ============================================
void findStudent(const vector<Student>& students) {
    int searchId;
    cout << "请输入要查找的学号：";
    cin >> searchId;

    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "\n找到学生信息：" << endl;
            cout << "学号：" << s.id << endl;
            cout << "姓名：" << s.name << endl;
            cout << "成绩：" << fixed << setprecision(1) << s.score << endl;
            return;
        }
    }

    cout << "未找到学号为 " << searchId << " 的学生" << endl;
}

// ============================================
// 任务 8：综合应用 - 保存为二进制文件
// ============================================
void saveToBinary(const vector<Student>& students) {
    if (students.empty()) {
        cout << "没有数据可保存" << endl;
        return;
    }
    writeToBinaryFile(students.data(), students.size());
}

// ============================================
// 任务 8：综合应用 - 从二进制文件加载
// ============================================
void loadFromBinary(vector<Student>& students) {
    Student temp[100];
    int count = readFromBinaryFile(temp, 100);

    if (count > 0) {
        students.clear();
        for (int i = 0; i < count; i++) {
            students.push_back(temp[i]);
        }
        cout << "成功加载 " << count << " 条记录" << endl;
    }
}

// ============================================
// 任务 8：综合应用 - 导出 CSV
// ============================================
void exportCSV(const vector<Student>& students) {
    if (students.empty()) {
        cout << "没有数据可导出" << endl;
        return;
    }
    exportToCSV(students.data(), students.size());
}

// ============================================
// 任务 8：综合应用 - 统计平均分
// ============================================
void calculateAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "没有学生记录，无法计算平均分" << endl;
        return;
    }

    double sum = 0;
    double maxScore = students[0].score;
    double minScore = students[0].score;

    for (const auto& s : students) {
        sum += s.score;
        if (s.score > maxScore) maxScore = s.score;
        if (s.score < minScore) minScore = s.score;
    }

    double avg = sum / students.size();

    cout << "\n===== 成绩统计 =====" << endl;
    cout << fixed << setprecision(2);
    cout << "学生人数：" << students.size() << endl;
    cout << "平均分：  " << avg << endl;
    cout << "最高分：  " << maxScore << endl;
    cout << "最低分：  " << minScore << endl;
}

// ============================================
// 显示菜单
// ============================================
void showMenu() {
    cout << "\n===== 学生成绩管理系统 =====" << endl;
    cout << "1. 添加学生成绩" << endl;
    cout << "2. 显示所有成绩" << endl;
    cout << "3. 查找学生" << endl;
    cout << "4. 保存为二进制文件" << endl;
    cout << "5. 从二进制文件加载" << endl;
    cout << "6. 导出为CSV" << endl;
    cout << "7. 统计平均分" << endl;
    cout << "8. 从文本文件加载" << endl;
    cout << "9. 保存到文本文件" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择：";
}

// ============================================
// 演示函数 - 展示各任务的功能
// ============================================
void demonstrateTasks() {
    cout << "\n========== I/O 重定向功能演示 ==========" << endl;

    // 准备测试数据
    Student testData[] = {
        {1001, "张三", 95.5},
        {1002, "李四", 87.0},
        {1003, "王五", 92.5},
        {1004, "赵六", 78.5}
    };
    int testCount = 4;

    // 任务 1：文本文件写入
    cout << "\n----- 任务 1：文本文件写入 -----" << endl;
    writeToTextFile(testData, testCount);

    // 任务 2：文本文件读取
    cout << "\n----- 任务 2：文本文件读取 -----" << endl;
    Student readData[10];
    int readCount = readFromTextFile(readData, 10);

    // 任务 3：追加模式写入
    cout << "\n----- 任务 3：追加模式写入 -----" << endl;
    Student newStudent = {1005, "钱七", 88.0};
    appendToFile(newStudent);

    // 任务 4：格式化输出
    cout << "\n----- 任务 4：格式化输出 -----" << endl;
    // 重新读取包含新追加记录的数据
    readCount = readFromTextFile(readData, 10);
    displayFormatted(readData, readCount);

    // 任务 5：流状态检测
    cout << "\n----- 任务 5：流状态检测 -----" << endl;
    Student safeData[10];
    int safeCount = safeReadFile(TEXT_FILE, safeData, 10);
    if (safeCount > 0) {
        cout << "安全读取成功，共 " << safeCount << " 条记录" << endl;
    }

    // 任务 6：二进制文件操作
    cout << "\n----- 任务 6：二进制文件操作 -----" << endl;
    writeToBinaryFile(testData, testCount);

    Student binaryData[10];
    int binaryCount = readFromBinaryFile(binaryData, 10);
    if (binaryCount > 0) {
        cout << "从二进制文件读取的数据：" << endl;
        displayFormatted(binaryData, binaryCount);
    }

    // 任务 7：字符串流解析
    cout << "\n----- 任务 7：字符串流解析 -----" << endl;
    string csvLine = "1006,孙八,91.5";
    Student parsedStudent;
    if (parseCSV(csvLine, parsedStudent)) {
        cout << "CSV 解析成功：" << endl;
        cout << "学号：" << parsedStudent.id << endl;
        cout << "姓名：" << parsedStudent.name << endl;
        cout << "成绩：" << parsedStudent.score << endl;
    }

    // CSV 导出
    exportToCSV(testData, testCount);

    cout << "\n========== 演示完成 ==========" << endl;
}

// ============================================
// 主函数
// ============================================
int main() {
    vector<Student> students;
    int choice;

    // 首先运行演示
    cout << "是否运行功能演示？(1-是, 0-否): ";
    cin >> choice;
    if (choice == 1) {
        demonstrateTasks();
    }

    // 尝试从文本文件加载现有数据
    Student temp[100];
    int count = readFromTextFile(temp, 100);
    for (int i = 0; i < count; i++) {
        students.push_back(temp[i]);
    }

    // 主循环
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAll(students);
                break;
            case 3:
                findStudent(students);
                break;
            case 4:
                saveToBinary(students);
                break;
            case 5:
                loadFromBinary(students);
                break;
            case 6:
                exportCSV(students);
                break;
            case 7:
                calculateAverage(students);
                break;
            case 8: {
                // 从文本文件加载
                Student temp[100];
                int count = readFromTextFile(temp, 100);
                students.clear();
                for (int i = 0; i < count; i++) {
                    students.push_back(temp[i]);
                }
                break;
            }
            case 9:
                // 保存到文本文件
                if (!students.empty()) {
                    writeToTextFile(students.data(), students.size());
                } else {
                    cout << "没有数据可保存" << endl;
                }
                break;
            case 0:
                cout << "感谢使用，再见！" << endl;
                break;
            default:
                cout << "无效选择，请重试" << endl;
        }
    } while (choice != 0);

    return 0;
}
