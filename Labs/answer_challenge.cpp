/*
 * 拓展挑战答案
 */

#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "选择题目：1-基础题 2-倒序梯形 3-数字金字塔\n";
    cin >> choice;

    int n;
    cout << "请输入 n: ";
    cin >> n;

    if (choice == 1) {
        // 基础题：正序梯形
        cout << "\n正序梯形：\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 2) {
        // 挑战1：倒序梯形
        cout << "\n倒序梯形：\n";
        for (int i = n; i >= 1; i--) {  // i 从 n 递减到 1
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 3) {
        // 挑战2：数字金字塔
        cout << "\n数字金字塔：\n";
        for (int i = 1; i <= n; i++) {
            // 先输出空格（n-i 个）
            for (int k = 1; k <= n - i; k++) {
                cout << " ";
            }
            // 再输出数字
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/*
 * 挑战1思路：
 * - 外层循环从 n 递减到 1（i--）
 * - 内层循环仍然是 1 到 i
 *
 * 挑战2思路：
 * - 第 i 行需要先输出 (n-i) 个空格
 * - 然后输出 i 个数字
 * - 这样数字就会居中对齐
 */
