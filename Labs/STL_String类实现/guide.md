# STL String类实现 - 实验指导书

## 一、实验目的

1. 深入理解C++ string类的内部实现原理
2. 掌握动态内存管理技术（new/delete）
3. 理解深拷贝与浅拷贝的区别
4. 熟练掌握运算符重载技术
5. 学习资源管理的RAII思想
6. 理解面向对象封装思想

## 二、实验背景

STL的string类是C++标准库中最常用的类之一，它封装了C风格字符串的底层细节，提供了安全、高效的字符串操作接口。本实验将从零开始实现一个简化版的MyString类，帮助你深入理解：
- 如何管理动态分配的内存
- 如何设计类的拷贝语义
- 如何通过运算符重载提供直观的接口

## 三、核心知识点

### 3.1 类的基本框架设计

```cpp
class MyString {
private:
    char* data;        // 指向字符串数据的指针
    size_t len;        // 字符串长度（不包括'\0'）
    size_t capacity;   // 已分配内存容量

public:
    // 构造、析构、拷贝控制
    // 成员函数
    // 运算符重载
};
```

**设计要点：**
- `data`：动态分配的字符数组，以'\0'结尾
- `len`：当前字符串长度，方便快速获取
- `capacity`：预分配容量，减少频繁的内存重新分配

### 3.2 动态内存管理

**内存分配：**
```cpp
data = new char[capacity];
```

**内存释放：**
```cpp
delete[] data;
```

**关键原则：**
1. 谁分配，谁释放
2. 使用new[]分配的内存，必须用delete[]释放
3. 避免重复释放和内存泄漏
4. 释放后应将指针置为nullptr

### 3.3 深拷贝 vs 浅拷贝

**浅拷贝（错误示范）：**
```cpp
// 编译器默认的拷贝构造
MyString s1("hello");
MyString s2 = s1;  // s1.data和s2.data指向同一块内存！
// 析构时会double free，导致程序崩溃
```

**深拷贝（正确实现）：**
```cpp
MyString(const MyString& other) {
    len = other.len;
    capacity = other.capacity;
    data = new char[capacity];  // 分配新内存
    strcpy(data, other.data);    // 复制内容
}
```

**为什么需要深拷贝：**
- 每个对象拥有独立的内存空间
- 修改一个对象不影响另一个
- 析构时各自释放自己的内存

### 3.4 拷贝构造函数

**使用场景：**
```cpp
MyString s1("hello");
MyString s2 = s1;           // 场景1: 初始化
MyString s3(s1);            // 场景2: 显式调用
void func(MyString s);      // 场景3: 值传递
func(s1);
```

**实现要点：**
```cpp
MyString(const MyString& other) {
    // 1. 复制基本成员
    len = other.len;
    capacity = other.capacity;

    // 2. 分配新内存
    data = new char[capacity];

    // 3. 复制数据
    strcpy(data, other.data);
}
```

### 3.5 赋值运算符实现

**使用场景：**
```cpp
MyString s1("hello");
MyString s2("world");
s2 = s1;  // 赋值运算符
```

**关键问题：自赋值检测**
```cpp
MyString s1("hello");
s1 = s1;  // 自赋值！必须处理
```

**标准实现模式：**
```cpp
MyString& operator=(const MyString& other) {
    // 1. 自赋值检测
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
```

**为什么返回引用：**
```cpp
s1 = s2 = s3;  // 链式赋值
```

### 3.6 常用成员函数实现

#### 3.6.1 size() - 获取长度
```cpp
size_t size() const {
    return len;
}
```

#### 3.6.2 c_str() - 获取C风格字符串
```cpp
const char* c_str() const {
    return data;
}
```

#### 3.6.3 append() - 追加字符串
```cpp
void append(const char* str) {
    size_t str_len = strlen(str);
    size_t new_len = len + str_len;

    // 如果容量不足，需要扩容
    if (new_len + 1 > capacity) {
        // 扩容逻辑：通常扩展为原来的2倍
        size_t new_capacity = (new_len + 1) * 2;
        char* new_data = new char[new_capacity];
        strcpy(new_data, data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    // 追加内容
    strcat(data, str);
    len = new_len;
}
```

#### 3.6.4 substr() - 提取子串
```cpp
MyString substr(size_t pos, size_t count) const {
    // 边界检查
    if (pos >= len) {
        return MyString("");
    }

    // 调整count
    if (pos + count > len) {
        count = len - pos;
    }

    // 创建临时缓冲区
    char* temp = new char[count + 1];
    strncpy(temp, data + pos, count);
    temp[count] = '\0';

    MyString result(temp);
    delete[] temp;
    return result;
}
```

### 3.7 运算符重载

#### 3.7.1 operator+ (字符串连接)
```cpp
MyString operator+(const MyString& other) const {
    MyString result;
    result.len = len + other.len;
    result.capacity = result.len + 1;
    result.data = new char[result.capacity];

    strcpy(result.data, data);
    strcat(result.data, other.data);

    return result;
}
```

#### 3.7.2 operator+= (追加)
```cpp
MyString& operator+=(const MyString& other) {
    append(other.data);
    return *this;
}
```

#### 3.7.3 operator[] (下标访问)
```cpp
char& operator[](size_t index) {
    return data[index];  // 可修改
}

const char& operator[](size_t index) const {
    return data[index];  // 只读
}
```

**为什么需要两个版本：**
```cpp
MyString s("hello");
char c = s[0];      // 调用const版本
s[0] = 'H';         // 调用非const版本
```

#### 3.7.4 operator== (相等比较)
```cpp
bool operator==(const MyString& other) const {
    return strcmp(data, other.data) == 0;
}
```

#### 3.7.5 operator<< (输出流)
```cpp
// 必须声明为友元函数
friend ostream& operator<<(ostream& os, const MyString& str) {
    os << str.data;
    return os;
}
```

**为什么是友元函数：**
- 第一个参数是ostream&，不能是成员函数
- 需要访问private成员data

## 四、实验任务详解

### 任务1：类框架设计
设计合理的私有成员变量和公有接口。

### 任务2：构造函数实现
- **默认构造函数**：创建空字符串
- **C字符串构造函数**：从const char*构造
- **拷贝构造函数**：深拷贝实现

### 任务3：析构函数实现
正确释放动态分配的内存，避免内存泄漏。

### 任务4：拷贝控制
实现深拷贝的拷贝构造函数和赋值运算符。

### 任务5：赋值运算符
处理自赋值情况，避免资源泄漏。

### 任务6：基本成员函数
实现size()、c_str()、empty()、clear()。

### 任务7：字符串操作
实现append()和substr()函数。

### 任务8：运算符重载
实现+、+=、[]、==、!=运算符。

### 任务9：流运算符
实现<<和>>运算符。

### 任务10：测试验证
编写完整的测试用例验证所有功能。

## 五、常见错误与调试

### 5.1 内存泄漏
```cpp
// 错误：忘记释放内存
~MyString() {
    // 空实现，造成内存泄漏
}

// 正确：
~MyString() {
    delete[] data;
}
```

### 5.2 悬空指针
```cpp
// 错误：使用已释放的内存
MyString s("hello");
delete[] s.data;
cout << s.c_str();  // 悬空指针！
```

### 5.3 缓冲区溢出
```cpp
// 错误：没有为'\0'预留空间
data = new char[len];  // 错误！应该是len+1
strcpy(data, str);     // 溢出！
```

### 5.4 忘记处理自赋值
```cpp
// 错误：
MyString& operator=(const MyString& other) {
    delete[] data;  // 如果是自赋值，这里就释放了唯一的数据！
    data = new char[other.capacity];
    strcpy(data, other.data);  // 悬空指针！
    return *this;
}
```

## 六、扩展思考

1. **移动语义**：如何实现移动构造函数和移动赋值运算符？
2. **小字符串优化（SSO）**：如何避免短字符串的动态分配？
3. **写时复制（COW）**：如何实现延迟复制策略？
4. **异常安全**：如果new失败会怎样？如何保证异常安全性？
5. **性能优化**：如何减少内存重新分配的次数？

## 七、实验步骤

1. 阅读本指导书，理解每个知识点
2. 打开submit.cpp，查看代码框架
3. 按照TODO提示，逐步实现每个函数
4. 编译运行，对比answer.cpp检查实现
5. 运行测试用例，确保所有功能正常
6. 使用valgrind等工具检测内存泄漏

## 八、评分标准

- 构造/析构函数实现正确（20分）
- 深拷贝实现正确（20分）
- 赋值运算符正确处理自赋值（15分）
- 基本成员函数实现正确（15分）
- 运算符重载实现正确（20分）
- 无内存泄漏（10分）

## 九、参考资料

1. C++ Primer 第5版 - 第13章：拷贝控制
2. Effective C++ 条款10-12：拷贝控制
3. cppreference.com - std::string文档

## 十、提交要求

1. 提交完整的submit.cpp文件
2. 确保代码能够编译通过
3. 所有测试用例通过
4. 使用内存检测工具验证无泄漏
