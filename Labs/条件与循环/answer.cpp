#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// 任务2：猜数字游戏
void guessNumberGame() {
    cout << "\n=== 猜数字游戏 ===" << endl;
    cout << "我想了一个1-100之间的数字，你有10次机会猜！\n" << endl;

    int target = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 10;
    bool guessed = false;

    while (attempts < MAX_ATTEMPTS && !guessed) {
        attempts++;
        cout << "第" << attempts << "次猜测: ";
        cin >> guess;

        if (guess == target) {
            guessed = true;
            cout << "恭喜你猜对了！" << endl;
        } else if (guess > target) {
            cout << "太大了！" << endl;
        } else {
            cout << "太小了！" << endl;
        }
    }

    if (guessed) {
        string level = attempts <= 3 ? "优秀" : (attempts <= 6 ? "良好" : "及格");
        cout << "你用了" << attempts << "次机会，评价: " << level << "！" << endl;
    } else {
        cout << "很遗憾，机会用完了！答案是: " << target << endl;
    }
}

// 任务3：质数判断器
void primeChecker() {
    cout << "\n=== 质数判断器 ===" << endl;
    int n;
    cout << "请输入一个正整数: ";
    cin >> n;

    if (n <= 1) {
        cout << n << " 不是质数！" << endl;
        return;
    }

    if (n == 2) {
        cout << n << " 是质数！" << endl;
        return;
    }

    bool isPrime = true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

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

    switch (choice) {
        case 1:
            // 直角三角形
            cout << endl;
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << i;
                }
                cout << endl;
            }
            break;

        case 2:
            // 等腰三角形
            cout << endl;
            for (int i = 1; i <= height; i++) {
                // 打印空格
                for (int j = 1; j <= height - i; j++) {
                    cout << " ";
                }
                // 打印数字
                for (int j = 1; j <= 2 * i - 1; j++) {
                    cout << i;
                }
                cout << endl;
            }
            break;

        case 3:
            // 金字塔（数字递增）
            cout << endl;
            for (int i = 1; i <= height; i++) {
                // 打印空格
                for (int j = 1; j <= height - i; j++) {
                    cout << " ";
                }
                // 打印递增数字
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            // 菱形
            cout << endl;
            // 上半部分（包括中间）
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= height - i; j++) {
                    cout << " ";
                }
                for (int j = 1; j <= 2 * i - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
            // 下半部分
            for (int i = height - 1; i >= 1; i--) {
                for (int j = 1; j <= height - i; j++) {
                    cout << " ";
                }
                for (int j = 1; j <= 2 * i - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
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

    int original = abs(num);
    int temp = original;

    // 1. 计算各位数字之和
    int sum = 0;
    temp = original;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    // 2. 判断是否为回文数
    int reversed = 0;
    temp = original;
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    bool isPalindrome = (original == reversed);

    // 3. 判断是否为完全平方数
    int sqrtNum = static_cast<int>(sqrt(original));
    bool isPerfectSquare = (sqrtNum * sqrtNum == original);

    // 4. 统计奇数和偶数位个数
    int oddCount = 0, evenCount = 0;
    temp = original;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == 0) {
            temp /= 10;
            continue;
        }
        if (digit % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        temp /= 10;
    }

    // 5. 找出最大和最小数字位
    int maxDigit = 0, minDigit = 9;
    temp = original;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit > maxDigit) maxDigit = digit;
        if (digit < minDigit) minDigit = digit;
        temp /= 10;
    }

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
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int sum = 0;
    for (int num : arr) {
        sum += num;
    }

    cout << "总和: " << sum << endl;
    cout << "平均值: " << static_cast<double>(sum) / size << endl;

    int maxVal = arr[0], minVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }

    cout << "最大值: " << maxVal << endl;
    cout << "最小值: " << minVal << endl;
}

// 任务1：主菜单
int main() {
    srand(time(0));

    int choice;

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

        switch (choice) {
            case 1:
                guessNumberGame();
                break;
            case 2:
                primeChecker();
                break;
            case 3:
                printPatterns();
                break;
            case 4:
                numberAnalyzer();
                break;
            case 5:
                arrayAnalysis();
                break;
            case 0:
                cout << "\n感谢使用数字游戏大师！再见！" << endl;
                break;
            default:
                cout << "无效的选择，请重新输入！" << endl;
        }
    } while (choice != 0);

    return 0;
}
