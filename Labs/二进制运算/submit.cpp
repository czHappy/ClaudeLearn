/**
 * 实验：位运算魔法师
 *
 * 学号：_________________
 * 姓名：_________________
 *
 * 实验目的：
 * 1. 掌握二进制表示与进制转换
 * 2. 熟练使用位运算符（&, |, ^, ~, <<, >>）
 * 3. 理解位掩码技术及其应用
 * 4. 学会用位运算实现算术运算
 * 5. 掌握位运算常见技巧
 * 6. 了解位域的使用
 */

#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

// ==================== 任务1：进制转换 ====================

/**
 * 将十进制正整数转换为二进制字符串
 * @param n 十进制正整数
 * @return 二进制字符串（不含前缀）
 */
string toBinary(int n) {
    // TODO: 实现十进制转二进制
    // 提示：除2取余，逆序排列
    // 注意处理 n=0 的情况

    return "";
}

/**
 * 将十进制正整数转换为八进制字符串
 * @param n 十进制正整数
 * @return 八进制字符串（不含前缀）
 */
string toOctal(int n) {
    // TODO: 实现十进制转八进制
    // 提示：除8取余，逆序排列

    return "";
}

/**
 * 将十进制正整数转换为十六进制字符串
 * @param n 十进制正整数
 * @return 十六进制字符串（不含前缀，使用大写字母）
 */
string toHexadecimal(int n) {
    // TODO: 实现十进制转十六进制
    // 提示：除16取余，余数10-15对应A-F

    return "";
}

// ==================== 任务2：基本位运算演示 ====================

/**
 * 将整数转换为指定位数的二进制字符串
 * @param n 整数
 * @param bits 位数
 * @return 固定位数的二进制字符串
 */
string toBinaryFixed(int n, int bits) {
    // TODO: 转换为固定位数的二进制字符串
    // 提示：从高位到低位依次检查每一位

    return "";
}

/**
 * 演示两个8位整数的所有位运算
 * @param a 第一个操作数
 * @param b 第二个操作数
 */
void demonstrateBitOperations(int a, int b) {
    cout << "===== 位运算演示 =====" << endl;
    cout << "a = " << a << ", 二进制: " << toBinaryFixed(a, 8) << endl;
    cout << "b = " << b << ", 二进制: " << toBinaryFixed(b, 8) << endl;
    cout << "----------------------" << endl;

    // TODO: 演示以下位运算并输出结果
    // 1. 按位与 a & b
    // 2. 按位或 a | b
    // 3. 按位异或 a ^ b
    // 4. 按位取反 ~a
    // 5. 左移 a << 2
    // 6. 右移 a >> 2

}

// ==================== 任务3：位运算技巧 ====================

/**
 * 使用位运算判断一个数是否为奇数
 * @param n 整数
 * @return true如果是奇数
 */
bool isOdd(int n) {
    // TODO: 使用位运算判断奇偶
    // 提示：检查最低位

    return false;
}

/**
 * 使用异或运算交换两个数
 * @param a 第一个数的引用
 * @param b 第二个数的引用
 */
void swapWithXor(int& a, int& b) {
    // TODO: 使用三次异或交换两个数
    // 提示：a^=b; b^=a; a^=b;

}

/**
 * 判断一个正整数是否是2的幂
 * @param n 正整数
 * @return true如果是2的幂
 */
bool isPowerOfTwo(int n) {
    // TODO: 使用位运算判断是否为2的幂
    // 提示：2的幂的二进制只有一个1
    // n & (n-1) 可以清除最低位的1

    return false;
}

/**
 * 统计整数二进制表示中1的个数
 * @param n 整数
 * @return 1的个数
 */
int countSetBits(int n) {
    // TODO: 统计二进制中1的个数
    // 提示：循环使用 n & (n-1) 清除最低位的1

    return 0;
}

/**
 * 获取最低位的1（返回只有该位为1的数）
 * @param n 整数
 * @return 最低位1对应的值
 */
int getLowestSetBit(int n) {
    // TODO: 获取最低位的1
    // 提示：n & (-n)

    return 0;
}

// ==================== 任务4：权限管理系统 ====================

// TODO: 定义权限常量
// READ    = 1  (0001)
// WRITE   = 2  (0010)
// EXECUTE = 4  (0100)
// DELETE  = 8  (1000)

const int PERM_READ    = 0;  // TODO: 修改为正确的值
const int PERM_WRITE   = 0;  // TODO: 修改为正确的值
const int PERM_EXECUTE = 0;  // TODO: 修改为正确的值
const int PERM_DELETE  = 0;  // TODO: 修改为正确的值

/**
 * 检查是否拥有某个权限
 * @param permission 当前权限值
 * @param check 要检查的权限
 * @return true如果拥有该权限
 */
bool hasPermission(int permission, int check) {
    // TODO: 使用位运算检查权限

    return false;
}

/**
 * 添加权限
 * @param permission 当前权限值
 * @param add 要添加的权限
 * @return 添加后的权限值
 */
int addPermission(int permission, int add) {
    // TODO: 使用位运算添加权限

    return permission;
}

/**
 * 移除权限
 * @param permission 当前权限值
 * @param remove 要移除的权限
 * @return 移除后的权限值
 */
int removePermission(int permission, int remove) {
    // TODO: 使用位运算移除权限

    return permission;
}

/**
 * 将权限值转换为可读字符串
 * @param permission 权限值
 * @return 形如 "rwxd" 或 "r---" 的字符串
 */
string permissionToString(int permission) {
    // TODO: 将权限转换为字符串表示
    // r-读, w-写, x-执行, d-删除
    // 有权限显示字母，无权限显示 -

    string result = "----";

    return result;
}

// ==================== 任务5：位运算实现算术 ====================

/**
 * 使用位运算实现加法（不使用+、-运算符）
 * @param a 加数
 * @param b 加数
 * @return a + b
 */
int bitwiseAdd(int a, int b) {
    // TODO: 使用位运算实现加法
    // 提示：
    // 1. a ^ b 得到不进位的和
    // 2. (a & b) << 1 得到进位
    // 3. 循环直到没有进位

    return 0;
}

/**
 * 使用位运算实现乘法（正整数）
 * @param a 乘数
 * @param b 乘数
 * @return a * b
 */
int bitwiseMultiply(int a, int b) {
    // TODO: 使用位运算实现乘法
    // 提示：
    // 1. 检查b的每一位，如果为1则加上相应的a
    // 2. 每次a左移1位，b右移1位

    return 0;
}

// ==================== 任务6：紧凑日期存储 ====================

/**
 * 紧凑日期结构体 - 使用位域
 * 要求总大小为2字节（16位）
 * 年：7位（0-127，表示2000-2127）
 * 月：4位（1-12）
 * 日：5位（1-31）
 */
#pragma pack(push, 1)  // 设置1字节对齐，确保结构体紧凑
struct CompactDate {
    // TODO: 使用位域定义结构体成员
    // 格式：uint16_t 成员名 : 位数;
    // 提示：使用 uint16_t 类型确保总大小为2字节

    uint16_t year : 1;   // TODO: 修改为正确的位数 (7位)
    uint16_t month : 1;  // TODO: 修改为正确的位数 (4位)
    uint16_t day : 1;    // TODO: 修改为正确的位数 (5位)
};
#pragma pack(pop)      // 恢复默认对齐

/**
 * 设置紧凑日期
 * @param date 日期结构体引用
 * @param year 年份（2000-2127）
 * @param month 月份（1-12）
 * @param day 日期（1-31）
 */
void setCompactDate(CompactDate& date, int year, int month, int day) {
    // TODO: 设置日期各字段
    // 注意：year需要减去2000后存储

}

/**
 * 获取紧凑日期的年份
 * @param date 日期结构体
 * @return 实际年份（2000-2127）
 */
int getYear(const CompactDate& date) {
    // TODO: 返回实际年份

    return 0;
}

/**
 * 将紧凑日期格式化为字符串
 * @param date 日期结构体
 * @return 格式如 "2024-03-15"
 */
string formatDate(const CompactDate& date) {
    // TODO: 格式化日期为字符串
    // 提示：使用 to_string() 函数

    return "";
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

    // 测试获取最低位的1
    cout << "获取最低位的1：" << endl;
    cout << "  getLowestSetBit(12) = " << getLowestSetBit(12)
         << " (1100的最低位1是100=4)" << endl;
    cout << "  getLowestSetBit(10) = " << getLowestSetBit(10)
         << " (1010的最低位1是10=2)" << endl;
}

void testTask4() {
    cout << "\n========== 任务4测试：权限管理 ==========" << endl;

    int perm = 0;
    cout << "初始权限: " << permissionToString(perm) << endl;

    perm = addPermission(perm, PERM_READ);
    cout << "添加读权限: " << permissionToString(perm) << endl;

    perm = addPermission(perm, PERM_WRITE);
    cout << "添加写权限: " << permissionToString(perm) << endl;

    perm = addPermission(perm, PERM_EXECUTE);
    cout << "添加执行权限: " << permissionToString(perm) << endl;

    cout << "检查权限：" << endl;
    cout << "  有读权限? " << (hasPermission(perm, PERM_READ) ? "是" : "否") << endl;
    cout << "  有删除权限? " << (hasPermission(perm, PERM_DELETE) ? "是" : "否") << endl;

    perm = removePermission(perm, PERM_WRITE);
    cout << "移除写权限: " << permissionToString(perm) << endl;
}

void testTask5() {
    cout << "\n========== 任务5测试：位运算算术 ==========" << endl;

    // 测试加法
    cout << "位运算加法：" << endl;
    cout << "  bitwiseAdd(5, 3) = " << bitwiseAdd(5, 3) << " (期望: 8)" << endl;
    cout << "  bitwiseAdd(15, 27) = " << bitwiseAdd(15, 27) << " (期望: 42)" << endl;
    cout << "  bitwiseAdd(0, 100) = " << bitwiseAdd(0, 100) << " (期望: 100)" << endl;

    // 测试乘法
    cout << "位运算乘法：" << endl;
    cout << "  bitwiseMultiply(6, 7) = " << bitwiseMultiply(6, 7) << " (期望: 42)" << endl;
    cout << "  bitwiseMultiply(12, 5) = " << bitwiseMultiply(12, 5) << " (期望: 60)" << endl;
    cout << "  bitwiseMultiply(0, 100) = " << bitwiseMultiply(0, 100) << " (期望: 0)" << endl;
}

void testTask6() {
    cout << "\n========== 任务6测试：紧凑日期 ==========" << endl;

    cout << "CompactDate结构体大小: " << sizeof(CompactDate) << " 字节" << endl;

    CompactDate date;
    setCompactDate(date, 2024, 3, 15);
    cout << "设置日期: 2024-3-15" << endl;
    cout << "读取年份: " << getYear(date) << endl;
    cout << "格式化输出: " << formatDate(date) << endl;

    // 测试边界值
    setCompactDate(date, 2000, 1, 1);
    cout << "最小日期: " << formatDate(date) << endl;

    setCompactDate(date, 2127, 12, 31);
    cout << "最大日期: " << formatDate(date) << endl;
}

int main() {
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║       位运算魔法师 - 实验测试          ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    testTask1();
    testTask2();
    testTask3();
    testTask4();
    testTask5();
    testTask6();

    cout << "\n========== 测试完成 ==========" << endl;

    return 0;
}
