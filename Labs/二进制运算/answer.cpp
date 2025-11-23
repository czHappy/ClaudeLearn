/**
 * 实验：位运算魔法师 - 标准答案
 *
 * 本文件包含所有任务的完整实现
 */

#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

// ==================== 任务1：进制转换 ====================

/**
 * 将十进制正整数转换为二进制字符串
 */
string toBinary(int n) {
    if (n == 0) return "0";

    string result = "";
    while (n > 0) {
        result = (char)('0' + (n % 2)) + result;
        n /= 2;
    }
    return result;
}

/**
 * 将十进制正整数转换为八进制字符串
 */
string toOctal(int n) {
    if (n == 0) return "0";

    string result = "";
    while (n > 0) {
        result = (char)('0' + (n % 8)) + result;
        n /= 8;
    }
    return result;
}

/**
 * 将十进制正整数转换为十六进制字符串
 */
string toHexadecimal(int n) {
    if (n == 0) return "0";

    const char hexDigits[] = "0123456789ABCDEF";
    string result = "";
    while (n > 0) {
        result = hexDigits[n % 16] + result;
        n /= 16;
    }
    return result;
}

// ==================== 任务2：基本位运算演示 ====================

/**
 * 将整数转换为指定位数的二进制字符串
 */
string toBinaryFixed(int n, int bits) {
    string result = "";
    for (int i = bits - 1; i >= 0; i--) {
        result += ((n >> i) & 1) ? '1' : '0';
    }
    return result;
}

/**
 * 演示两个8位整数的所有位运算
 */
void demonstrateBitOperations(int a, int b) {
    cout << "===== 位运算演示 =====" << endl;
    cout << "a = " << a << ", 二进制: " << toBinaryFixed(a, 8) << endl;
    cout << "b = " << b << ", 二进制: " << toBinaryFixed(b, 8) << endl;
    cout << "----------------------" << endl;

    // 按位与
    int andResult = a & b;
    cout << "a & b  = " << andResult << ", 二进制: " << toBinaryFixed(andResult, 8) << endl;

    // 按位或
    int orResult = a | b;
    cout << "a | b  = " << orResult << ", 二进制: " << toBinaryFixed(orResult, 8) << endl;

    // 按位异或
    int xorResult = a ^ b;
    cout << "a ^ b  = " << xorResult << ", 二进制: " << toBinaryFixed(xorResult, 8) << endl;

    // 按位取反（只显示低8位）
    int notResult = ~a & 0xFF;
    cout << "~a     = " << notResult << ", 二进制: " << toBinaryFixed(notResult, 8)
         << " (低8位)" << endl;

    // 左移
    int leftShift = a << 2;
    cout << "a << 2 = " << leftShift << ", 二进制: " << toBinaryFixed(leftShift, 8) << endl;

    // 右移
    int rightShift = a >> 2;
    cout << "a >> 2 = " << rightShift << ", 二进制: " << toBinaryFixed(rightShift, 8) << endl;
}

// ==================== 任务3：位运算技巧 ====================

/**
 * 使用位运算判断一个数是否为奇数
 */
bool isOdd(int n) {
    return n & 1;  // 最低位为1则是奇数
}

/**
 * 使用异或运算交换两个数
 */
void swapWithXor(int& a, int& b) {
    if (&a == &b) return;  // 防止自交换
    a ^= b;
    b ^= a;
    a ^= b;
}

/**
 * 判断一个正整数是否是2的幂
 */
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

/**
 * 统计整数二进制表示中1的个数
 */
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // 清除最低位的1
        count++;
    }
    return count;
}

/**
 * 获取最低位的1
 */
int getLowestSetBit(int n) {
    return n & (-n);
}

// ==================== 任务4：权限管理系统 ====================

// 权限常量定义
const int PERM_READ    = 1;   // 0001
const int PERM_WRITE   = 2;   // 0010
const int PERM_EXECUTE = 4;   // 0100
const int PERM_DELETE  = 8;   // 1000

/**
 * 检查是否拥有某个权限
 */
bool hasPermission(int permission, int check) {
    return (permission & check) == check;
}

/**
 * 添加权限
 */
int addPermission(int permission, int add) {
    return permission | add;
}

/**
 * 移除权限
 */
int removePermission(int permission, int remove) {
    return permission & (~remove);
}

/**
 * 将权限值转换为可读字符串
 */
string permissionToString(int permission) {
    string result = "";
    result += (permission & PERM_READ)    ? 'r' : '-';
    result += (permission & PERM_WRITE)   ? 'w' : '-';
    result += (permission & PERM_EXECUTE) ? 'x' : '-';
    result += (permission & PERM_DELETE)  ? 'd' : '-';
    return result;
}

// ==================== 任务5：位运算实现算术 ====================

/**
 * 使用位运算实现加法
 */
int bitwiseAdd(int a, int b) {
    while (b != 0) {
        // 计算进位（两个位都为1时产生进位）
        int carry = (a & b) << 1;
        // 计算不考虑进位的和
        a = a ^ b;
        // 进位作为新的加数
        b = carry;
    }
    return a;
}

/**
 * 使用位运算实现乘法（正整数）
 */
int bitwiseMultiply(int a, int b) {
    int result = 0;
    while (b > 0) {
        // 如果b的最低位是1，加上当前的a
        if (b & 1) {
            result = bitwiseAdd(result, a);  // 使用位运算加法
        }
        // a左移相当于乘2
        a <<= 1;
        // b右移检查下一位
        b >>= 1;
    }
    return result;
}

// ==================== 任务6：紧凑日期存储 ====================

/**
 * 紧凑日期结构体 - 使用位域
 * 使用 uint16_t 确保结构体只占2字节
 */
#pragma pack(push, 1)  // 设置1字节对齐
struct CompactDate {
    uint16_t year  : 7;   // 7位，0-127（表示2000-2127）
    uint16_t month : 4;   // 4位，1-12
    uint16_t day   : 5;   // 5位，1-31
};  // 总共16位 = 2字节
#pragma pack(pop)      // 恢复默认对齐

/**
 * 设置紧凑日期
 */
void setCompactDate(CompactDate& date, int year, int month, int day) {
    date.year = year - 2000;  // 存储相对于2000年的偏移
    date.month = month;
    date.day = day;
}

/**
 * 获取紧凑日期的年份
 */
int getYear(const CompactDate& date) {
    return date.year + 2000;
}

/**
 * 将紧凑日期格式化为字符串
 */
string formatDate(const CompactDate& date) {
    int year = date.year + 2000;
    int month = date.month;
    int day = date.day;

    string result = to_string(year) + "-";
    if (month < 10) result += "0";
    result += to_string(month) + "-";
    if (day < 10) result += "0";
    result += to_string(day);

    return result;
}

// ==================== 补充演示：补码表示 ====================

/**
 * 演示补码表示
 */
void demonstrateComplement() {
    cout << "\n===== 补码表示演示 =====" << endl;

    int8_t positive = 5;
    int8_t negative = -5;

    cout << "+5 的8位二进制: " << toBinaryFixed(positive & 0xFF, 8) << endl;
    cout << "-5 的8位二进制: " << toBinaryFixed(negative & 0xFF, 8) << endl;

    cout << "\n计算 -5 的补码过程：" << endl;
    cout << "+5 原码:        " << toBinaryFixed(5, 8) << endl;
    cout << "按位取反:       " << toBinaryFixed(~5 & 0xFF, 8) << endl;
    cout << "加1得补码:      " << toBinaryFixed((~5 + 1) & 0xFF, 8) << endl;

    // 验证 5 + (-5) = 0
    cout << "\n验证: 5 + (-5) = " << (int)(positive + negative) << endl;
}

/**
 * 演示更多位运算技巧
 */
void demonstrateMoreTricks() {
    cout << "\n===== 更多位运算技巧 =====" << endl;

    int n = 52;  // 二进制: 110100
    cout << "n = " << n << ", 二进制: " << toBinary(n) << endl;

    // 获取第k位
    int k = 4;
    int kthBit = (n >> k) & 1;
    cout << "第" << k << "位的值: " << kthBit << endl;

    // 设置第k位为1
    int setKth = n | (1 << k);
    cout << "设置第" << k << "位为1: " << setKth << " (" << toBinary(setKth) << ")" << endl;

    // 清除第k位
    k = 2;
    int clearKth = n & ~(1 << k);
    cout << "清除第" << k << "位: " << clearKth << " (" << toBinary(clearKth) << ")" << endl;

    // 切换第k位
    int toggleKth = n ^ (1 << k);
    cout << "切换第" << k << "位: " << toggleKth << " (" << toBinary(toggleKth) << ")" << endl;

    // 清除最低位的1
    int clearLowest = n & (n - 1);
    cout << "清除最低位的1: " << clearLowest << " (" << toBinary(clearLowest) << ")" << endl;

    // 获取最低位的1
    int lowestBit = n & (-n);
    cout << "获取最低位的1: " << lowestBit << " (" << toBinary(lowestBit) << ")" << endl;

    // 快速求2^n
    int power = 1 << 10;
    cout << "2^10 = " << power << endl;

    // 快速除以2^n
    int divide = 100 >> 2;  // 100 / 4
    cout << "100 / 4 = " << divide << endl;

    // 取模 2^n
    int mod = 100 & ((1 << 3) - 1);  // 100 % 8
    cout << "100 % 8 = " << mod << endl;
}

// ==================== 测试代码 ====================

void testTask1() {
    cout << "\n========== 任务1测试：进制转换 ==========" << endl;

    int testCases[] = {0, 1, 10, 255, 1024};
    for (int n : testCases) {
        cout << "十进制: " << n << endl;
        cout << "  二进制: " << toBinary(n) << endl;
        cout << "  八进制: " << toOctal(n) << endl;
        cout << "  十六进制: " << toHexadecimal(n) << endl;
    }
}

void testTask2() {
    cout << "\n========== 任务2测试：基本位运算 ==========" << endl;
    demonstrateBitOperations(12, 10);
}

void testTask3() {
    cout << "\n========== 任务3测试：位运算技巧 ==========" << endl;

    // 测试判断奇偶
    cout << "判断奇偶：" << endl;
    cout << "  isOdd(7) = " << (isOdd(7) ? "true" : "false") << endl;
    cout << "  isOdd(8) = " << (isOdd(8) ? "true" : "false") << endl;

    // 测试异或交换
    cout << "异或交换：" << endl;
    int a = 5, b = 10;
    cout << "  交换前: a=" << a << ", b=" << b << endl;
    swapWithXor(a, b);
    cout << "  交换后: a=" << a << ", b=" << b << endl;

    // 测试2的幂判断
    cout << "判断2的幂：" << endl;
    int powers[] = {1, 2, 3, 4, 8, 15, 16, 100, 128};
    for (int p : powers) {
        cout << "  isPowerOfTwo(" << p << ") = "
             << (isPowerOfTwo(p) ? "true" : "false") << endl;
    }

    // 测试统计1的个数
    cout << "统计1的个数：" << endl;
    cout << "  countSetBits(7) = " << countSetBits(7) << " (111有3个1)" << endl;
    cout << "  countSetBits(15) = " << countSetBits(15) << " (1111有4个1)" << endl;
    cout << "  countSetBits(255) = " << countSetBits(255) << " (11111111有8个1)" << endl;

    // 测试获取最低位的1
    cout << "获取最低位的1：" << endl;
    cout << "  getLowestSetBit(12) = " << getLowestSetBit(12)
         << " (1100的最低位1是100=4)" << endl;
    cout << "  getLowestSetBit(10) = " << getLowestSetBit(10)
         << " (1010的最低位1是10=2)" << endl;
    cout << "  getLowestSetBit(8) = " << getLowestSetBit(8)
         << " (1000的最低位1是1000=8)" << endl;
}

void testTask4() {
    cout << "\n========== 任务4测试：权限管理 ==========" << endl;

    int perm = 0;
    cout << "初始权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;

    perm = addPermission(perm, PERM_READ);
    cout << "添加读权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;

    perm = addPermission(perm, PERM_WRITE);
    cout << "添加写权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;

    perm = addPermission(perm, PERM_EXECUTE);
    cout << "添加执行权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;

    perm = addPermission(perm, PERM_DELETE);
    cout << "添加删除权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;

    cout << "\n检查权限：" << endl;
    cout << "  有读权限? " << (hasPermission(perm, PERM_READ) ? "是" : "否") << endl;
    cout << "  有写权限? " << (hasPermission(perm, PERM_WRITE) ? "是" : "否") << endl;
    cout << "  有读写权限? " << (hasPermission(perm, PERM_READ | PERM_WRITE) ? "是" : "否") << endl;

    perm = removePermission(perm, PERM_WRITE);
    cout << "\n移除写权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;

    perm = removePermission(perm, PERM_DELETE);
    cout << "移除删除权限: " << permissionToString(perm) << " (值:" << perm << ")" << endl;
}

void testTask5() {
    cout << "\n========== 任务5测试：位运算算术 ==========" << endl;

    // 测试加法
    cout << "位运算加法：" << endl;
    cout << "  bitwiseAdd(5, 3) = " << bitwiseAdd(5, 3) << " (期望: 8)" << endl;
    cout << "  bitwiseAdd(15, 27) = " << bitwiseAdd(15, 27) << " (期望: 42)" << endl;
    cout << "  bitwiseAdd(0, 100) = " << bitwiseAdd(0, 100) << " (期望: 100)" << endl;
    cout << "  bitwiseAdd(255, 1) = " << bitwiseAdd(255, 1) << " (期望: 256)" << endl;

    // 测试乘法
    cout << "位运算乘法：" << endl;
    cout << "  bitwiseMultiply(6, 7) = " << bitwiseMultiply(6, 7) << " (期望: 42)" << endl;
    cout << "  bitwiseMultiply(12, 5) = " << bitwiseMultiply(12, 5) << " (期望: 60)" << endl;
    cout << "  bitwiseMultiply(0, 100) = " << bitwiseMultiply(0, 100) << " (期望: 0)" << endl;
    cout << "  bitwiseMultiply(1, 100) = " << bitwiseMultiply(1, 100) << " (期望: 100)" << endl;
    cout << "  bitwiseMultiply(15, 15) = " << bitwiseMultiply(15, 15) << " (期望: 225)" << endl;
}

void testTask6() {
    cout << "\n========== 任务6测试：紧凑日期 ==========" << endl;

    cout << "CompactDate结构体大小: " << sizeof(CompactDate) << " 字节" << endl;

    CompactDate date;
    setCompactDate(date, 2024, 3, 15);
    cout << "\n设置日期: 2024-3-15" << endl;
    cout << "内部存储 - year: " << date.year << ", month: " << date.month
         << ", day: " << date.day << endl;
    cout << "读取年份: " << getYear(date) << endl;
    cout << "格式化输出: " << formatDate(date) << endl;

    // 测试边界值
    cout << "\n边界值测试：" << endl;
    setCompactDate(date, 2000, 1, 1);
    cout << "最小日期: " << formatDate(date) << endl;

    setCompactDate(date, 2127, 12, 31);
    cout << "最大日期: " << formatDate(date) << endl;

    // 测试更多日期
    setCompactDate(date, 2050, 6, 20);
    cout << "测试日期: " << formatDate(date) << endl;
}

int main() {
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║    位运算魔法师 - 标准答案测试         ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    testTask1();
    testTask2();
    testTask3();
    testTask4();
    testTask5();
    testTask6();

    // 补充演示
    demonstrateComplement();
    demonstrateMoreTricks();

    cout << "\n========== 所有测试完成 ==========" << endl;

    return 0;
}
