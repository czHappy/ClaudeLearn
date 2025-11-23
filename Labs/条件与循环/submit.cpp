#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// 任务2：猜数字游戏
void guessNumberGame() {
    cout << "\n=== 猜数字游戏 ===" << endl;
    cout << "我想了一个1-100之间的数字，你有10次机会猜！\n" << endl;

    // TODO: 生成1-100之间的随机数
    // 提示：使用 rand() % 100 + 1


    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 10;
    bool guessed = false;

    // TODO: 使用 while 循环，条件是：attempts < MAX_ATTEMPTS && !guessed
    while (/* 你的代码 */) {
        attempts++;
        cout << "第" << attempts << "次猜测: ";
        cin >> guess;

        // TODO: 使用嵌套的 if-else 判断猜测结果
        // 如果 guess == target，设置 guessed = true 并输出"恭喜你猜对了！"
        // 如果 guess > target，输出"太大了！"
        // 如果 guess < target，输出"太小了！"


    }

    if (guessed) {
        // TODO: 使用三元运算符判断评价等级
        // attempts <= 3 为"优秀"，attempts <= 6 为"良好"，否则为"及格"
        string level = /* 你的代码 */;
        cout << "你用了" << attempts << "次机会，评价: " << level << "！" << endl;
    } else {
        cout << "很遗憾，机会用完了！答案是: " << /* 目标数字 */ << endl;
    }
}

// 任务3：质数判断器
void primeChecker() {
    cout << "\n=== 质数判断器 ===" << endl;
    int n;
    cout << "请输入一个正整数: ";
    cin >> n;

    // TODO: 特殊情况处理
    // 如果 n <= 1，输出"不是质数"并返回
    // 如果 n == 2，输出"是质数"并返回


    bool isPrime = true;

    // TODO: 使用 for 循环从 2 到 sqrt(n) 检查是否有因数
    // 如果发现因数（n % i == 0），设置 isPrime = false 并使用 break 跳出循环


    if (isPrime) {
        cout << n << " 是质数！" << endl;
    } else {
        cout << n << " 不是质数！" << endl;
    }
}

// 任务4：打印图形
void printPatterns() {
    cout << "\n=== 打印图形 ===" << endl;
    cout << "请选择图形类型：" << endl;
    cout << "1. 直角三角形" << endl;
    cout << "2. 等腰三角形" << endl;
    cout << "3. 金字塔" << endl;
    cout << "4. 菱形" << endl;

    int choice, height;
    cout << "请选择: ";
    cin >> choice;
    cout << "请输入高度: ";
    cin >> height;

    // TODO: 使用 switch-case 处理不同的图形选择
    switch (choice) {
        case 1:
            // 直角三角形
            // TODO: 外层循环 i 从 1 到 height
            // 内层循环 j 从 1 到 i，打印数字 i

            break;

        case 2:
            // 等腰三角形
            // TODO: 外层循环 i 从 1 到 height
            // 第一个内层循环：打印 (height - i) 个空格
            // 第二个内层循环：打印 (2*i - 1) 个数字 i

            break;

        case 3:
            // 金字塔（数字递增）
            // TODO: 类似等腰三角形，但每行数字从1递增

            break;

        case 4:
            // 菱形
            // TODO: 上半部分（包括中间）：类似等腰三角形
            // 下半部分：倒置的等腰三角形

            break;

        default:
            cout << "无效的选择！" << endl;
    }
}

// 任务5：数字分析器
void numberAnalyzer() {
    cout << "\n=== 数字分析器 ===" << endl;
    int num;
    cout << "请输入一个整数: ";
    cin >> num;

    int original = abs(num);  // 使用绝对值
    int temp = original;

    // 1. 计算各位数字之和
    int sum = 0;
    temp = original;
    // TODO: 使用 while 循环，每次取最后一位（temp % 10），累加到 sum
    // 然后 temp /= 10，直到 temp == 0


    // 2. 判断是否为回文数
    int reversed = 0;
    temp = original;
    // TODO: 使用 while 循环反转数字
    // reversed = reversed * 10 + (temp % 10)
    // temp /= 10


    bool isPalindrome = (original == reversed);

    // 3. 判断是否为完全平方数
    int sqrtNum = static_cast<int>(sqrt(original));
    bool isPerfectSquare = (sqrtNum * sqrtNum == original);

    // 4. 统计奇数和偶数位个数
    int oddCount = 0, evenCount = 0;
    temp = original;
    // TODO: 使用 while 循环统计每一位数字
    // 如果数字为0，使用 continue 跳过
    // 根据 digit % 2 判断奇偶性


    // 5. 找出最大和最小数字位
    int maxDigit = 0, minDigit = 9;
    temp = original;
    // TODO: 使用 while 循环遍历每一位
    // 更新 maxDigit 和 minDigit


    // 输出结果
    cout << "\n分析结果：" << endl;
    cout << "- 各位数字之和: " << sum << endl;
    cout << "- 是否为回文数: " << (isPalindrome ? "是" : "否") << endl;
    cout << "- 是否为完全平方数: " << (isPerfectSquare ? "是" : "否");
    if (isPerfectSquare) {
        cout << " (" << sqrtNum << "^2 = " << original << ")";
    }
    cout << endl;
    cout << "- 奇数位个数: " << oddCount << ", 偶数位个数: " << evenCount << endl;
    cout << "- 最大数字位: " << maxDigit << ", 最小数字位: " << minDigit << endl;
}

// 任务6：范围for循环应用
void arrayAnalysis() {
    cout << "\n=== 数组分析 ===" << endl;
    int arr[] = {12, 45, 7, 23, 56, 89, 34, 1, 67, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "数组元素: ";
    // TODO: 使用范围for循环遍历并输出数组元素


    // TODO: 使用范围for循环计算总和
    int sum = 0;


    cout << "\n总和: " << sum << endl;
    cout << "平均值: " << static_cast<double>(sum) / size << endl;

    // TODO: 使用范围for循环找出最大值和最小值
    int maxVal = arr[0], minVal = arr[0];


    cout << "最大值: " << maxVal << endl;
    cout << "最小值: " << minVal << endl;
}

// 任务1：主菜单
int main() {
    srand(time(0));  // 初始化随机数种子

    int choice;

    // TODO: 使用 do-while 循环显示菜单，直到用户选择退出
    do {
        cout << "\n======= 数字游戏大师 =======" << endl;
        cout << "1. 猜数字游戏" << endl;
        cout << "2. 质数判断器" << endl;
        cout << "3. 打印图形" << endl;
        cout << "4. 数字分析器" << endl;
        cout << "5. 数组分析" << endl;
        cout << "0. 退出程序" << endl;
        cout << "============================" << endl;
        cout << "请选择功能 (0-5): ";
        cin >> choice;

        // TODO: 使用 switch-case 调用相应的函数


    } while (/* 你的代码 */);

    cout << "\n感谢使用数字游戏大师！再见！" << endl;
    return 0;
}
