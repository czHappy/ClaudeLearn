#include <iostream>
#include <cstring>
using namespace std;

/**
 * MyString类 - 简化版string实现
 *
 * 实验任务：
 * 1. 实现完整的构造函数和析构函数
 * 2. 实现深拷贝（拷贝构造函数和赋值运算符）
 * 3. 实现基本成员函数
 * 4. 实现运算符重载
 * 5. 实现流运算符
 */

class MyString {
private:
    char* data;        // 字符串数据指针
    size_t len;        // 字符串长度（不含'\0'）
    size_t capacity;   // 已分配容量

public:
    // ============= 任务1: 构造函数 =============

    /**
     * 默认构造函数
     * 创建空字符串，需要：
     * 1. 设置len为0
     * 2. 设置capacity为1（至少容纳'\0'）
     * 3. 分配内存并初始化为空字符串
     */
    MyString() {
        // TODO: 实现默认构造函数
    }

    /**
     * C字符串构造函数
     * 从C风格字符串构造，需要：
     * 1. 计算字符串长度
     * 2. 分配足够内存
     * 3. 复制字符串内容
     */
    MyString(const char* str) {
        // TODO: 实现C字符串构造函数
        // 提示：使用strlen()获取长度，strcpy()复制内容
    }

    /**
     * 拷贝构造函数（深拷贝）
     * 从另一个MyString对象构造，需要：
     * 1. 复制len和capacity
     * 2. 分配新内存（不能共享）
     * 3. 复制字符串内容
     */
    MyString(const MyString& other) {
        // TODO: 实现拷贝构造函数（深拷贝）
    }

    // ============= 任务2: 析构函数 =============

    /**
     * 析构函数
     * 释放动态分配的内存
     */
    ~MyString() {
        // TODO: 实现析构函数
        // 提示：使用delete[]释放data
    }

    // ============= 任务3: 赋值运算符 =============

    /**
     * 赋值运算符（深拷贝）
     * 需要处理：
     * 1. 自赋值检测（this == &other）
     * 2. 释放旧资源
     * 3. 分配新资源并复制
     * 4. 返回*this支持链式赋值
     */
    MyString& operator=(const MyString& other) {
        // TODO: 实现赋值运算符
        // 重要：必须检测自赋值！
    }

    // ============= 任务4: 基本成员函数 =============

    /**
     * 获取字符串长度
     */
    size_t size() const {
        // TODO: 实现size函数
    }

    /**
     * 获取C风格字符串指针
     */
    const char* c_str() const {
        // TODO: 实现c_str函数
    }

    /**
     * 判断字符串是否为空
     */
    bool empty() const {
        // TODO: 实现empty函数
    }

    /**
     * 清空字符串
     * 将字符串重置为空，但保留已分配的内存
     */
    void clear() {
        // TODO: 实现clear函数
        // 提示：设置len为0，data[0]为'\0'
    }

    // ============= 任务5: 字符串操作 =============

    /**
     * 追加字符串
     * 需要处理：
     * 1. 检查容量是否足够
     * 2. 如果不够，重新分配内存（建议扩展为2倍）
     * 3. 追加内容并更新len
     */
    void append(const char* str) {
        // TODO: 实现append函数
        // 提示：可能需要realloc式的扩容
    }

    /**
     * 提取子串
     * pos: 起始位置
     * count: 提取长度
     * 需要处理：
     * 1. 边界检查（pos不能超出范围）
     * 2. 调整count（不能超出剩余长度）
     * 3. 创建并返回新字符串
     */
    MyString substr(size_t pos, size_t count) const {
        // TODO: 实现substr函数
        // 提示：使用strncpy复制指定长度
    }

    // ============= 任务6: 运算符重载 =============

    /**
     * 字符串连接运算符 +
     * 创建新字符串，包含this + other的内容
     */
    MyString operator+(const MyString& other) const {
        // TODO: 实现operator+
    }

    /**
     * 追加运算符 +=
     * 将other追加到当前字符串
     */
    MyString& operator+=(const MyString& other) {
        // TODO: 实现operator+=
        // 提示：可以调用append函数
    }

    /**
     * 下标运算符 []（可修改）
     * 返回引用，允许修改字符
     */
    char& operator[](size_t index) {
        // TODO: 实现operator[]（非const版本）
    }

    /**
     * 下标运算符 []（只读）
     * 返回const引用，不允许修改
     */
    const char& operator[](size_t index) const {
        // TODO: 实现operator[]（const版本）
    }

    /**
     * 相等比较运算符 ==
     * 比较两个字符串内容是否相同
     */
    bool operator==(const MyString& other) const {
        // TODO: 实现operator==
        // 提示：使用strcmp比较
    }

    /**
     * 不等比较运算符 !=
     */
    bool operator!=(const MyString& other) const {
        // TODO: 实现operator!=
        // 提示：return !(*this == other);
    }

    // ============= 任务7: 流运算符 =============

    /**
     * 输出流运算符 <<
     * 友元函数，支持 cout << mystring
     */
    friend ostream& operator<<(ostream& os, const MyString& str) {
        // TODO: 实现operator<<
    }

    /**
     * 输入流运算符 >>
     * 友元函数，支持 cin >> mystring
     * 读取一个单词（以空白符分隔）
     */
    friend istream& operator>>(istream& is, MyString& str) {
        // TODO: 实现operator>>
        // 提示：可以使用临时缓冲区读取，然后赋值
    }
};


// ============= 测试函数 =============

void test_constructors() {
    cout << "=== 测试构造函数 ===" << endl;

    MyString s1;                    // 默认构造
    cout << "s1 (默认): \"" << s1 << "\" (长度: " << s1.size() << ")" << endl;

    MyString s2("Hello");           // C字符串构造
    cout << "s2 (C串): \"" << s2 << "\" (长度: " << s2.size() << ")" << endl;

    MyString s3(s2);                // 拷贝构造
    cout << "s3 (拷贝s2): \"" << s3 << "\" (长度: " << s3.size() << ")" << endl;

    cout << endl;
}

void test_assignment() {
    cout << "=== 测试赋值运算符 ===" << endl;

    MyString s1("Hello");
    MyString s2("World");

    cout << "赋值前: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;
    s1 = s2;
    cout << "s1=s2后: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;

    // 测试自赋值
    s1 = s1;
    cout << "s1=s1后: s1=\"" << s1 << "\"" << endl;

    // 测试链式赋值
    MyString s3, s4;
    s3 = s4 = s1;
    cout << "链式赋值: s3=\"" << s3 << "\", s4=\"" << s4 << "\"" << endl;

    cout << endl;
}

void test_basic_functions() {
    cout << "=== 测试基本函数 ===" << endl;

    MyString s("Hello World");

    cout << "字符串: \"" << s << "\"" << endl;
    cout << "size(): " << s.size() << endl;
    cout << "c_str(): " << s.c_str() << endl;
    cout << "empty(): " << (s.empty() ? "true" : "false") << endl;

    s.clear();
    cout << "clear()后: \"" << s << "\" (empty: " << (s.empty() ? "true" : "false") << ")" << endl;

    cout << endl;
}

void test_string_operations() {
    cout << "=== 测试字符串操作 ===" << endl;

    MyString s("Hello");
    cout << "原字符串: \"" << s << "\"" << endl;

    s.append(" World");
    cout << "append(\" World\")后: \"" << s << "\"" << endl;

    MyString sub = s.substr(0, 5);
    cout << "substr(0, 5): \"" << sub << "\"" << endl;

    sub = s.substr(6, 5);
    cout << "substr(6, 5): \"" << sub << "\"" << endl;

    cout << endl;
}

void test_operators() {
    cout << "=== 测试运算符重载 ===" << endl;

    MyString s1("Hello");
    MyString s2(" World");

    // 测试 +
    MyString s3 = s1 + s2;
    cout << "\"" << s1 << "\" + \"" << s2 << "\" = \"" << s3 << "\"" << endl;

    // 测试 +=
    s1 += s2;
    cout << "s1 += s2: \"" << s1 << "\"" << endl;

    // 测试 []
    cout << "s1[0] = " << s1[0] << endl;
    s1[0] = 'h';
    cout << "s1[0] = 'h'后: \"" << s1 << "\"" << endl;

    // 测试 == 和 !=
    MyString s4("hello World");
    cout << "s1 == s4: " << (s1 == s4 ? "true" : "false") << endl;
    cout << "s1 != s4: " << (s1 != s4 ? "true" : "false") << endl;

    cout << endl;
}

void test_deep_copy() {
    cout << "=== 测试深拷贝 ===" << endl;

    MyString s1("Original");
    MyString s2 = s1;  // 拷贝构造

    cout << "拷贝前: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;

    s2[0] = 'M';
    cout << "修改s2后: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;
    cout << "s1和s2独立: " << (s1 != s2 ? "验证成功" : "验证失败") << endl;

    cout << endl;
}

int main() {
    cout << "===========================================" << endl;
    cout << "     MyString类测试程序" << endl;
    cout << "===========================================" << endl;
    cout << endl;

    test_constructors();
    test_assignment();
    test_basic_functions();
    test_string_operations();
    test_operators();
    test_deep_copy();

    cout << "===========================================" << endl;
    cout << "     所有测试完成！" << endl;
    cout << "===========================================" << endl;

    return 0;
}
