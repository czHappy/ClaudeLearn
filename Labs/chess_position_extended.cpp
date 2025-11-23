/*
 * 思考题答案
 * 包含：1. 反向查询  2. Z字形填充  3. 螺旋填充（简化版）
 */

#include <iostream>
using namespace std;

// 基础题：给定k，求位置(r, c)
void forwardQuery(int n, int m, int k) {
    int row = (k - 1) / m + 1;
    int col = (k - 1) % m + 1;
    cout << "数字 " << k << " 在位置：(" << row << ", " << col << ")" << endl;
}

// 思考题1：给定位置(r, c)，求数字k
void reverseQuery(int n, int m, int r, int c) {
    int k = (r - 1) * m + c;
    cout << "位置 (" << r << ", " << c << ") 的数字是：" << k << endl;
}

// 思考题2：Z字形填充，给定k，求位置
void zigzagQuery(int n, int m, int k) {
    int row = (k - 1) / m + 1;
    int col_base = (k - 1) % m + 1;

    // 判断当前行是奇数行还是偶数行
    int col;
    if (row % 2 == 1) {
        // 奇数行：从左往右
        col = col_base;
    } else {
        // 偶数行：从右往左（需要镜像）
        col = m - col_base + 1;
    }

    cout << "Z字形填充，数字 " << k << " 在位置：(" << row << ", " << col << ")" << endl;
}

// 思考题3：螺旋填充（仅演示4×4的情况）
void spiralExample() {
    cout << "\n4×4 螺旋填充示例：\n";
    int spiral[4][4] = {
        {1,  2,  3,  4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9,  8,  7}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout.width(3);
            cout << spiral[i][j] << " ";
        }
        cout << endl;
    }
    cout << "(螺旋填充的通用算法较复杂，这里仅展示示例)\n";
}

int main() {
    int choice;
    cout << "=== 棋盘定位问题 - 思考题演示 ===\n";
    cout << "1. 基础题（正向查询）\n";
    cout << "2. 思考题1（反向查询）\n";
    cout << "3. 思考题2（Z字形填充）\n";
    cout << "4. 思考题3（螺旋填充示例）\n";
    cout << "请选择 (1-4): ";
    cin >> choice;

    if (choice == 1) {
        int n, m, k;
        cout << "输入 n m k: ";
        cin >> n >> m >> k;
        forwardQuery(n, m, k);
    }
    else if (choice == 2) {
        int n, m, r, c;
        cout << "输入 n m r c: ";
        cin >> n >> m >> r >> c;
        reverseQuery(n, m, r, c);

        // 验证：反向查询后再正向查询
        int k = (r - 1) * m + c;
        cout << "验证：";
        forwardQuery(n, m, k);
    }
    else if (choice == 3) {
        int n, m, k;
        cout << "输入 n m k: ";
        cin >> n >> m >> k;

        // 先展示普通填充
        cout << "\n普通填充：\n";
        forwardQuery(n, m, k);

        // 再展示Z字形填充
        zigzagQuery(n, m, k);

        // 画图说明
        cout << "\n示例：4×3 Z字形填充\n";
        cout << "→ → →\n";
        cout << "1  2  3\n";
        cout << "← ← ←\n";
        cout << "6  5  4\n";
        cout << "→ → →\n";
        cout << "7  8  9\n";
        cout << "← ← ←\n";
        cout << "12 11 10\n";
    }
    else if (choice == 4) {
        spiralExample();
    }

    return 0;
}

/*
 * 思考题解析：
 *
 * 【思考题1：反向查询】
 * 已知：位置 (r, c)
 * 求：数字 k
 *
 * 公式：k = (r-1) * m + c
 *
 * 推理：
 * - 第r行之前有 (r-1) 个完整的行
 * - 每行有 m 个数字
 * - 所以前面有 (r-1) * m 个数字
 * - 当前行的第 c 个，就是第 k 个数字
 *
 * 【思考题2：Z字形填充】
 * 关键：判断当前行的方向
 * - 奇数行：从左往右（col不变）
 * - 偶数行：从右往左（col需要镜像）
 *
 * 镜像公式：col_new = m - col_old + 1
 * 例如：m=4, col_old=1 → col_new=4
 *       m=4, col_old=2 → col_new=3
 *
 * 【思考题3：螺旋填充】
 * 螺旋填充较复杂，需要：
 * 1. 维护四个边界：上、下、左、右
 * 2. 按顺序填充：右→下→左→上
 * 3. 每完成一轮，缩小边界
 *
 * 通用算法超出本题范围，这里仅提供示例
 */
