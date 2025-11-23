# 实验指导书：自定义排序

## 一、实验目的

1. 掌握 std::sort 的基本用法
2. 学习自定义比较函数的编写方法
3. 理解 Lambda 表达式在排序中的应用
4. 掌握多关键字排序的实现技巧
5. 学会为自定义类型设计排序规则

## 二、知识点讲解

### 2.1 std::sort 基本用法

`std::sort` 是 C++ 标准库提供的排序函数，位于 `<algorithm>` 头文件中。

**基本语法：**
```cpp
#include <algorithm>
#include <vector>

std::vector<int> arr = {5, 2, 8, 1, 9};
std::sort(arr.begin(), arr.end());  // 默认升序排序
```

**降序排序：**
```cpp
std::sort(arr.begin(), arr.end(), std::greater<int>());  // 使用标准库提供的比较器
```

### 2.2 自定义比较函数

比较函数应该接受两个参数，返回 bool 类型：
- 返回 `true` 表示第一个参数应该排在第二个参数前面
- 返回 `false` 表示第一个参数应该排在第二个参数后面或相等

**函数指针形式：**
```cpp
bool compare(int a, int b) {
    return a > b;  // 降序排序
}

std::sort(arr.begin(), arr.end(), compare);
```

**结构体排序示例：**
```cpp
struct Student {
    string name;
    int score;
};

bool compareByScore(const Student& a, const Student& b) {
    return a.score > b.score;  // 按分数降序
}

std::sort(students.begin(), students.end(), compareByScore);
```

### 2.3 Lambda 表达式作为比较器

Lambda 表达式提供了一种更简洁的方式来定义比较器，特别适合一次性使用的排序规则。

**基本语法：**
```cpp
std::sort(arr.begin(), arr.end(), [](int a, int b) {
    return a > b;  // 降序排序
});
```

**Lambda 表达式结构：**
```
[捕获列表](参数列表) -> 返回类型 { 函数体 }
```

**示例：**
```cpp
// 按字符串长度排序
std::sort(words.begin(), words.end(), [](const string& a, const string& b) {
    return a.length() < b.length();
});

// 捕获外部变量
int threshold = 60;
std::sort(students.begin(), students.end(), [threshold](const Student& a, const Student& b) {
    // 及格的排前面，不及格的排后面
    bool a_pass = a.score >= threshold;
    bool b_pass = b.score >= threshold;
    if (a_pass != b_pass) return a_pass;
    return a.score > b.score;
});
```

### 2.4 多关键字排序

多关键字排序是指按照多个字段的优先级进行排序。

**实现方式：**
```cpp
struct Student {
    string name;
    int math;
    int english;
    int total;
};

// 先按总分降序，总分相同按数学成绩降序
bool compareStudent(const Student& a, const Student& b) {
    if (a.total != b.total) {
        return a.total > b.total;  // 总分降序
    }
    return a.math > b.math;  // 数学成绩降序
}
```

**使用 Lambda 实现：**
```cpp
std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    if (a.total != b.total) return a.total > b.total;
    if (a.math != b.math) return a.math > b.math;
    return a.english > b.english;
});
```

### 2.5 稳定排序 std::stable_sort

如果需要保持相等元素的相对顺序，使用 `std::stable_sort`：

```cpp
std::stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    return a.score > b.score;
});
```

## 三、实验背景

你需要为某学校设计一个考试成绩排序系统。系统需要支持多种排序方式，以满足不同的查询需求。

**学生信息包含：**
- 学号 (id)
- 姓名 (name)
- 数学成绩 (math)
- 英语成绩 (english)
- 总分 (total)

## 四、实验任务

### 任务1：基本排序

实现函数 `sortBasic()`，完成以下操作：
1. 创建一个整数数组：{85, 92, 78, 95, 88, 76, 90}
2. 先按升序排序并输出
3. 再按降序排序并输出

**输出格式：**
```
升序: 76 78 85 88 90 92 95
降序: 95 92 90 88 85 78 76
```

### 任务2：函数比较器

实现函数 `compareByScore()`，用于按总分降序排序学生。

在 `sortByFunction()` 中：
1. 创建学生数组（至少3个学生）
2. 使用 `compareByScore` 函数排序
3. 输出排序后的结果

**输出格式：**
```
学号: 1003, 姓名: 王五, 总分: 195
学号: 1001, 姓名: 张三, 总分: 185
学号: 1002, 姓名: 李四, 总分: 175
```

### 任务3：Lambda 比较器

实现函数 `sortByLambda()`，使用 Lambda 表达式实现以下三种排序：
1. 按数学成绩降序
2. 按英语成绩升序
3. 按姓名字典序

**输出格式：**
```
按数学成绩降序:
学号: 1003, 数学: 98
学号: 1001, 数学: 95
学号: 1002, 数学: 85

按英语成绩升序:
学号: 1002, 英语: 90
学号: 1001, 英语: 90
学号: 1003, 英语: 97

按姓名字典序:
姓名: 李四
姓名: 王五
姓名: 张三
```

### 任务4：多关键字排序

实现函数 `sortMultiKey()`，实现以下排序规则：
- 首先按总分降序
- 总分相同时按学号升序

**输出格式：**
```
排名1: 学号1003, 总分195
排名2: 学号1001, 总分185
排名3: 学号1002, 总分175
```

### 任务5：综合应用 - 排行榜系统

实现函数 `rankingSystem()`，构建一个完整的排行榜系统：

**排序规则（按优先级）：**
1. 总分高的排前面
2. 总分相同时，数学成绩高的排前面
3. 数学成绩也相同时，学号小的排前面

**输出要求：**
- 显示排名（从1开始）
- 显示所有学生信息
- 格式化输出

**输出格式：**
```
=== 成绩排行榜 ===
排名  学号    姓名    数学  英语  总分
1     1003    王五    98    97    195
2     1001    张三    95    90    185
3     1004    赵六    85    95    180
4     1002    李四    85    90    175
```

## 五、实验步骤

1. **阅读知识点**：仔细阅读上述知识点讲解
2. **理解任务**：明确每个任务的要求和输出格式
3. **编写代码**：在 `submit.cpp` 中完成各个 TODO 部分
4. **编译运行**：
   ```bash
   g++ submit.cpp -o submit -std=c++11
   ./submit
   ```
5. **对比答案**：参考 `answer.cpp` 检查自己的实现
6. **测试验证**：尝试修改测试数据，验证代码的正确性

## 六、注意事项

1. **比较函数的正确性**
   - 比较函数必须满足严格弱序关系
   - 不能出现 `a < b` 和 `b < a` 同时为真的情况
   - 相等元素应该返回 false

2. **参数传递**
   - 对于结构体，使用 `const` 引用传递以提高效率
   - 格式：`bool compare(const Student& a, const Student& b)`

3. **Lambda 表达式**
   - 简单比较不需要捕获外部变量，使用 `[]`
   - 需要外部变量时，使用 `[=]`（值捕获）或 `[&]`（引用捕获）

4. **多关键字排序**
   - 使用 if-else 结构逐级比较
   - 先比较优先级高的字段
   - 注意升序和降序的混合使用

5. **代码风格**
   - 变量命名清晰
   - 适当添加注释
   - 保持代码缩进整齐

## 七、扩展思考

1. `std::sort` 和 `std::stable_sort` 的区别是什么？在什么场景下需要使用稳定排序？

2. 如果要对一个包含 100 万条学生记录的数组排序，应该注意什么性能问题？

3. 能否使用运算符重载来简化自定义类型的排序？如何实现？

4. 除了 `std::sort`，C++ 标准库还提供了哪些排序相关的算法？

5. 如何实现局部排序（只排序前 N 个元素）？提示：了解 `std::partial_sort`

## 八、参考资料

- C++ Reference - std::sort: https://en.cppreference.com/w/cpp/algorithm/sort
- C++ Reference - Lambda expressions: https://en.cppreference.com/w/cpp/language/lambda
- 《C++ Primer》第 10 章：泛型算法

## 九、评分标准

- 任务1（20分）：正确实现基本排序
- 任务2（20分）：正确实现函数比较器
- 任务3（20分）：正确使用 Lambda 表达式
- 任务4（20分）：正确实现多关键字排序
- 任务5（20分）：正确实现综合排行榜系统

**总分：100分**

**附加分（最多10分）：**
- 代码风格良好（+3分）
- 添加了合理的注释（+3分）
- 实现了扩展功能（+4分）
