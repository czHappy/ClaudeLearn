#include <iostream>
#include <cstring>
using namespace std;

/**
 * MyString类 - 简化版string实现（标准答案）
 *
 * 本实现包含：
 * 1. 完整的构造函数和析构函数
 * 2. 深拷贝的拷贝构造函数和赋值运算符
 * 3. 基本成员函数
 * 4. 运算符重载
 * 5. 流运算符
 */

class MyString {
private:
    char* data;        // 字符串数据指针
    size_t len;        // 字符串长度（不含'\0'）
    size_t capacity;   // 已分配容量（包含'\0'位置）

public:
    // ============= 构造函数 =============

    /**
     * 默认构造函数
     * 创建空字符串
     */
    MyString() : len(0), capacity(16) {
        data = new char[capacity];
        data[0] = '\0';
    }

    /**
     * C字符串构造函数
     * 从C风格字符串构造
     */
    MyString(const char* str) {
        if (str == nullptr) {
            // 处理空指针情况
            len = 0;
            capacity = 16;
            data = new char[capacity];
            data[0] = '\0';
        } else {
            len = strlen(str);
            capacity = len + 1;
            data = new char[capacity];
            strcpy(data, str);
        }
    }

    /**
     * 拷贝构造函数（深拷贝）
     * 关键：分配新内存，复制内容
     */
    MyString(const MyString& other) {
        len = other.len;
        capacity = other.capacity;
        data = new char[capacity];  // 分配新内存！
        strcpy(data, other.data);    // 复制内容
    }

    // ============= 析构函数 =============

    /**
     * 析构函数
     * 释放动态分配的内存
     */
    ~MyString() {
        delete[] data;
        data = nullptr;  // 安全起见，置为空指针
    }

    // ============= 赋值运算符 =============

    /**
     * 赋值运算符（深拷贝）
     * 关键：检测自赋值，释放旧资源，分配新资源
     */
    MyString& operator=(const MyString& other) {
        // 1. 自赋值检测（非常重要！）
        if (this == &other) {
            return *this;
        }

        // 2. 释放旧资源
        delete[] data;

        // 3. 复制新资源
        len = other.len;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);

        // 4. 返回*this支持链式赋值
        return *this;
    }

    // ============= 基本成员函数 =============

    /**
     * 获取字符串长度
     */
    size_t size() const {
        return len;
    }

    /**
     * 获取字符串长度（length是size的别名）
     */
    size_t length() const {
        return len;
    }

    /**
     * 获取C风格字符串指针
     */
    const char* c_str() const {
        return data;
    }

    /**
     * 判断字符串是否为空
     */
    bool empty() const {
        return len == 0;
    }

    /**
     * 清空字符串
     * 重置为空，但保留已分配内存
     */
    void clear() {
        len = 0;
        data[0] = '\0';
    }

    /**
     * 获取容量
     */
    size_t get_capacity() const {
        return capacity;
    }

    // ============= 字符串操作 =============

    /**
     * 追加C字符串
     * 实现自动扩容机制
     */
    void append(const char* str) {
        if (str == nullptr) return;

        size_t str_len = strlen(str);
        size_t new_len = len + str_len;

        // 检查是否需要扩容
        if (new_len + 1 > capacity) {
            // 扩容：通常扩展为2倍或刚好够用，取较大者
            size_t new_capacity = (new_len + 1) * 2;
            if (new_capacity < capacity * 2) {
                new_capacity = capacity * 2;
            }

            // 分配新内存
            char* new_data = new char[new_capacity];
            strcpy(new_data, data);

            // 释放旧内存
            delete[] data;

            // 更新指针和容量
            data = new_data;
            capacity = new_capacity;
        }

        // 追加内容
        strcat(data, str);
        len = new_len;
    }

    /**
     * 追加MyString对象
     */
    void append(const MyString& str) {
        append(str.data);
    }

    /**
     * 提取子串
     * pos: 起始位置
     * count: 提取长度
     */
    MyString substr(size_t pos, size_t count) const {
        // 边界检查：起始位置超出范围
        if (pos >= len) {
            return MyString("");
        }

        // 调整count：不能超出剩余长度
        if (pos + count > len) {
            count = len - pos;
        }

        // 创建临时缓冲区
        char* temp = new char[count + 1];
        strncpy(temp, data + pos, count);
        temp[count] = '\0';

        // 创建结果字符串
        MyString result(temp);

        // 释放临时缓冲区
        delete[] temp;

        return result;
    }

    /**
     * 查找子串
     * 返回子串首次出现的位置，未找到返回npos
     */
    static const size_t npos = -1;

    size_t find(const char* str, size_t pos = 0) const {
        if (pos >= len) return npos;

        const char* found = strstr(data + pos, str);
        if (found == nullptr) return npos;

        return found - data;
    }

    // ============= 运算符重载 =============

    /**
     * 字符串连接运算符 + (MyString + MyString)
     */
    MyString operator+(const MyString& other) const {
        MyString result;

        // 确保有足够容量
        result.len = len + other.len;
        result.capacity = result.len + 1;

        // 释放result默认构造分配的内存，重新分配
        delete[] result.data;
        result.data = new char[result.capacity];

        // 拼接内容
        strcpy(result.data, data);
        strcat(result.data, other.data);

        return result;
    }

    /**
     * 字符串连接运算符 + (MyString + const char*)
     */
    MyString operator+(const char* str) const {
        return *this + MyString(str);
    }

    /**
     * 追加运算符 += (MyString)
     */
    MyString& operator+=(const MyString& other) {
        append(other.data);
        return *this;
    }

    /**
     * 追加运算符 += (const char*)
     */
    MyString& operator+=(const char* str) {
        append(str);
        return *this;
    }

    /**
     * 下标运算符 []（可修改）
     */
    char& operator[](size_t index) {
        return data[index];
    }

    /**
     * 下标运算符 []（只读）
     */
    const char& operator[](size_t index) const {
        return data[index];
    }

    /**
     * at()方法 - 带边界检查的下标访问
     */
    char& at(size_t index) {
        if (index >= len) {
            throw out_of_range("MyString::at() - index out of range");
        }
        return data[index];
    }

    const char& at(size_t index) const {
        if (index >= len) {
            throw out_of_range("MyString::at() - index out of range");
        }
        return data[index];
    }

    /**
     * 相等比较运算符 ==
     */
    bool operator==(const MyString& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator==(const char* str) const {
        return strcmp(data, str) == 0;
    }

    /**
     * 不等比较运算符 !=
     */
    bool operator!=(const MyString& other) const {
        return !(*this == other);
    }

    bool operator!=(const char* str) const {
        return !(*this == str);
    }

    /**
     * 小于比较运算符 <
     */
    bool operator<(const MyString& other) const {
        return strcmp(data, other.data) < 0;
    }

    /**
     * 大于比较运算符 >
     */
    bool operator>(const MyString& other) const {
        return strcmp(data, other.data) > 0;
    }

    /**
     * 小于等于 <=
     */
    bool operator<=(const MyString& other) const {
        return strcmp(data, other.data) <= 0;
    }

    /**
     * 大于等于 >=
     */
    bool operator>=(const MyString& other) const {
        return strcmp(data, other.data) >= 0;
    }

    // ============= 流运算符 =============

    /**
     * 输出流运算符 <<
     */
    friend ostream& operator<<(ostream& os, const MyString& str) {
        os << str.data;
        return os;
    }

    /**
     * 输入流运算符 >>
     * 读取一个单词（空白符分隔）
     */
    friend istream& operator>>(istream& is, MyString& str) {
        // 使用临时缓冲区
        const size_t BUFFER_SIZE = 1024;
        char buffer[BUFFER_SIZE];

        // 读取输入
        if (is >> buffer) {
            // 释放旧数据
            delete[] str.data;

            // 分配新内存并复制
            str.len = strlen(buffer);
            str.capacity = str.len + 1;
            str.data = new char[str.capacity];
            strcpy(str.data, buffer);
        }

        return is;
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

    MyString s4(nullptr);           // 空指针构造
    cout << "s4 (nullptr): \"" << s4 << "\" (长度: " << s4.size() << ")" << endl;

    cout << endl;
}

void test_assignment() {
    cout << "=== 测试赋值运算符 ===" << endl;

    MyString s1("Hello");
    MyString s2("World");

    cout << "赋值前: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;
    s1 = s2;
    cout << "s1=s2后: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;

    // 测试自赋值（关键测试！）
    s1 = s1;
    cout << "s1=s1后（自赋值）: s1=\"" << s1 << "\"" << endl;

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
    cout << "length(): " << s.length() << endl;
    cout << "c_str(): " << s.c_str() << endl;
    cout << "empty(): " << (s.empty() ? "true" : "false") << endl;
    cout << "capacity(): " << s.get_capacity() << endl;

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

    s.append("!");
    cout << "append(\"!\")后: \"" << s << "\"" << endl;

    // 测试子串提取
    MyString sub = s.substr(0, 5);
    cout << "substr(0, 5): \"" << sub << "\"" << endl;

    sub = s.substr(6, 5);
    cout << "substr(6, 5): \"" << sub << "\"" << endl;

    sub = s.substr(0, 100);  // 超出范围测试
    cout << "substr(0, 100): \"" << sub << "\"" << endl;

    sub = s.substr(100, 5);  // 起始位置超出测试
    cout << "substr(100, 5): \"" << sub << "\"" << endl;

    // 测试查找
    size_t pos = s.find("World");
    cout << "find(\"World\"): " << pos << endl;

    pos = s.find("xyz");
    cout << "find(\"xyz\"): " << (pos == MyString::npos ? "npos" : to_string(pos)) << endl;

    cout << endl;
}

void test_operators() {
    cout << "=== 测试运算符重载 ===" << endl;

    MyString s1("Hello");
    MyString s2(" World");

    // 测试 +
    MyString s3 = s1 + s2;
    cout << "\"" << s1 << "\" + \"" << s2 << "\" = \"" << s3 << "\"" << endl;

    // 测试 + (与const char*)
    MyString s4 = s1 + "!!!";
    cout << "\"" << s1 << "\" + \"!!!\" = \"" << s4 << "\"" << endl;

    // 测试 +=
    s1 += s2;
    cout << "s1 += s2: \"" << s1 << "\"" << endl;

    // 测试 []
    cout << "s1[0] = '" << s1[0] << "'" << endl;
    s1[0] = 'h';
    cout << "s1[0] = 'h'后: \"" << s1 << "\"" << endl;

    // 测试比较运算符
    MyString s5("hello World");
    cout << "s1 == s5: " << (s1 == s5 ? "true" : "false") << endl;
    cout << "s1 != s5: " << (s1 != s5 ? "true" : "false") << endl;

    MyString a("apple"), b("banana");
    cout << "\"apple\" < \"banana\": " << (a < b ? "true" : "false") << endl;
    cout << "\"apple\" > \"banana\": " << (a > b ? "true" : "false") << endl;

    cout << endl;
}

void test_deep_copy() {
    cout << "=== 测试深拷贝 ===" << endl;

    MyString s1("Original");
    MyString s2 = s1;  // 拷贝构造

    cout << "拷贝后: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;

    // 修改s2，验证s1不受影响
    s2[0] = 'M';
    cout << "修改s2后: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;

    // 验证地址不同
    cout << "s1.c_str()地址: " << (void*)s1.c_str() << endl;
    cout << "s2.c_str()地址: " << (void*)s2.c_str() << endl;
    cout << "地址不同: " << (s1.c_str() != s2.c_str() ? "验证成功" : "验证失败") << endl;

    cout << endl;
}

void test_capacity_growth() {
    cout << "=== 测试容量增长 ===" << endl;

    MyString s;
    cout << "初始: 长度=" << s.size() << ", 容量=" << s.get_capacity() << endl;

    s.append("Hello");
    cout << "append后: 长度=" << s.size() << ", 容量=" << s.get_capacity() << endl;

    s.append(" World! This is a test string.");
    cout << "再次append后: 长度=" << s.size() << ", 容量=" << s.get_capacity() << endl;

    cout << endl;
}

void test_edge_cases() {
    cout << "=== 测试边界情况 ===" << endl;

    // 空字符串操作
    MyString empty;
    cout << "空字符串 empty(): " << (empty.empty() ? "true" : "false") << endl;
    cout << "空字符串 size(): " << empty.size() << endl;

    // 空字符串连接
    MyString s("Test");
    MyString result = empty + s;
    cout << "空字符串 + \"Test\": \"" << result << "\"" << endl;

    result = s + empty;
    cout << "\"Test\" + 空字符串: \"" << result << "\"" << endl;

    // 自身连接
    MyString self("AB");
    self += self;  // 危险操作，但应该正确处理
    cout << "自身连接 \"AB\" += \"AB\": \"" << self << "\"" << endl;

    cout << endl;
}

int main() {
    cout << "===========================================" << endl;
    cout << "     MyString类测试程序（标准答案）" << endl;
    cout << "===========================================" << endl;
    cout << endl;

    test_constructors();
    test_assignment();
    test_basic_functions();
    test_string_operations();
    test_operators();
    test_deep_copy();
    test_capacity_growth();
    test_edge_cases();

    cout << "===========================================" << endl;
    cout << "     所有测试完成！" << endl;
    cout << "===========================================" << endl;

    return 0;
}
