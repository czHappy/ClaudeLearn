# 实验：运算符重载 - 分数类(Fraction)实现

## 实验目标

通过实现一个完整的分数类(Fraction)，全面掌握C++运算符重载的各种技术，包括算术运算符、关系运算符、赋值运算符、自增自减运算符、流运算符、下标运算符、函数调用运算符以及类型转换运算符的重载方法。

## 实验背景

分数是数学中的基本概念，包含分子(numerator)和分母(denominator)两个部分。通过实现一个功能完整的分数类，我们可以：
- 像使用基本数据类型一样使用分数对象
- 进行分数的四则运算
- 比较分数大小
- 实现分数的输入输出

## 知识要点

### 1. 运算符重载基本语法

运算符重载是C++的重要特性，允许为自定义类型定义运算符的行为。

```cpp
// 基本语法
返回类型 operator运算符(参数列表) {
    // 实现代码
}
```

### 2. 成员函数重载 vs 非成员函数重载

| 特性 | 成员函数重载 | 非成员函数重载 |
|------|-------------|---------------|
| 左操作数 | 必须是类对象(this) | 可以是任意类型 |
| 参数个数 | 二元运算符只需1个参数 | 二元运算符需要2个参数 |
| 访问权限 | 可直接访问私有成员 | 需要声明为友元或使用公有接口 |
| 适用场景 | =, [], (), -> 必须是成员函数 | <<, >> 必须是非成员函数 |

```cpp
class Fraction {
public:
    // 成员函数重载（推荐用于修改自身的运算符）
    Fraction operator+(const Fraction& other) const;

    // 友元函数重载（推荐用于需要对称性的运算符）
    friend Fraction operator*(const Fraction& a, const Fraction& b);
};
```

### 3. 算术运算符重载（+, -, *, /）

分数运算规则：
- 加法：a/b + c/d = (a*d + b*c) / (b*d)
- 减法：a/b - c/d = (a*d - b*c) / (b*d)
- 乘法：a/b * c/d = (a*c) / (b*d)
- 除法：a/b / c/d = (a*d) / (b*c)

```cpp
// 成员函数形式
Fraction operator+(const Fraction& other) const {
    return Fraction(
        num * other.den + den * other.num,  // 新分子
        den * other.den                       // 新分母
    );
}

// 非成员函数形式（友元）
friend Fraction operator+(const Fraction& a, const Fraction& b) {
    return Fraction(a.num * b.den + a.den * b.num, a.den * b.den);
}
```

### 4. 关系运算符重载（==, <, >, <=, >=, !=）

比较两个分数：通分后比较分子

```cpp
bool operator==(const Fraction& other) const {
    // 假设分数已约分
    return num == other.num && den == other.den;
}

bool operator<(const Fraction& other) const {
    // 交叉相乘比较：a/b < c/d 等价于 a*d < b*c（假设分母为正）
    return num * other.den < den * other.num;
}

// 其他关系运算符可以基于 < 和 == 实现
bool operator>(const Fraction& other) const { return other < *this; }
bool operator<=(const Fraction& other) const { return !(other < *this); }
bool operator>=(const Fraction& other) const { return !(*this < other); }
bool operator!=(const Fraction& other) const { return !(*this == other); }
```

### 5. 赋值运算符重载（=）

赋值运算符用于对象赋值，必须是成员函数。

```cpp
Fraction& operator=(const Fraction& other) {
    if (this != &other) {  // 自赋值检查
        num = other.num;
        den = other.den;
    }
    return *this;  // 返回引用支持链式赋值
}
```

**注意事项：**
- 返回引用类型以支持链式赋值 `a = b = c`
- 进行自赋值检查，避免 `a = a` 出问题
- 如果类中有指针成员，需要实现深拷贝

### 6. 复合赋值运算符（+=, -=, *=, /=）

```cpp
Fraction& operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}
```

### 7. 自增自减运算符重载（++, --）

前置和后置版本通过参数区分：

```cpp
// 前置++：++f，返回引用
Fraction& operator++() {
    num += den;  // 分数加1：num/den + 1 = (num+den)/den
    reduce();
    return *this;
}

// 后置++：f++，参数int是哑元，用于区分，返回值
Fraction operator++(int) {
    Fraction temp = *this;  // 保存原值
    ++(*this);              // 调用前置++
    return temp;            // 返回原值
}
```

**区别：**
| 特性 | 前置版本 | 后置版本 |
|------|---------|---------|
| 参数 | 无 | int（哑元） |
| 返回值 | 引用 | 值（副本） |
| 效率 | 更高 | 需要创建临时对象 |
| 语义 | 先修改后使用 | 先使用后修改 |

### 8. 流运算符重载（<<, >>）

流运算符必须重载为非成员函数（友元），因为左操作数是流对象。

```cpp
// 输出运算符
friend ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.num << "/" << f.den;
    return os;  // 返回流引用支持链式输出
}

// 输入运算符
friend istream& operator>>(istream& is, Fraction& f) {
    char slash;  // 用于读取分隔符'/'
    is >> f.num >> slash >> f.den;
    f.reduce();  // 输入后约分
    return is;
}
```

**使用示例：**
```cpp
Fraction f(1, 2);
cout << "分数是: " << f << endl;  // 输出：分数是: 1/2

Fraction g;
cin >> g;  // 输入：3/4
```

### 9. 函数调用运算符重载（()）

使对象可以像函数一样被调用，这样的对象称为"函数对象"或"仿函数"。

```cpp
// 计算分数的小数值
double operator()() const {
    return static_cast<double>(num) / den;
}

// 带参数版本：计算分数的n次幂
double operator()(int n) const {
    return pow(static_cast<double>(num) / den, n);
}
```

**使用示例：**
```cpp
Fraction f(1, 2);
cout << f() << endl;     // 输出：0.5
cout << f(2) << endl;    // 输出：0.25（1/2的平方）
```

### 10. 下标运算符重载（[]）

允许像访问数组一样访问对象的元素，必须是成员函数。

```cpp
// 非const版本，可修改
int& operator[](int index) {
    if (index == 0) return num;
    if (index == 1) return den;
    throw out_of_range("Index must be 0 or 1");
}

// const版本，只读访问
const int& operator[](int index) const {
    if (index == 0) return num;
    if (index == 1) return den;
    throw out_of_range("Index must be 0 or 1");
}
```

**使用示例：**
```cpp
Fraction f(3, 4);
cout << f[0] << "/" << f[1] << endl;  // 输出：3/4
f[0] = 5;  // 修改分子
```

### 11. 类型转换运算符

将对象转换为其他类型。

```cpp
// 转换为double
operator double() const {
    return static_cast<double>(num) / den;
}

// 转换为bool（判断分数是否为0）
explicit operator bool() const {
    return num != 0;
}
```

**注意：** `explicit`关键字防止隐式转换，只允许显式转换。

**使用示例：**
```cpp
Fraction f(1, 2);
double d = static_cast<double>(f);  // 显式转换
double e = f;  // 如果没有explicit，可以隐式转换

if (f) {  // 转换为bool
    cout << "分数不为0" << endl;
}
```

### 12. 约分算法（辅助功能）

使用欧几里得算法求最大公约数：

```cpp
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduce() {
    int g = gcd(num, den);
    num /= g;
    den /= g;
    // 确保分母为正
    if (den < 0) {
        num = -num;
        den = -den;
    }
}
```

## 实验任务

### 任务1：类基础结构（10分）

实现Fraction类的基本结构：
- 私有成员：分子(num)和分母(den)
- 构造函数：默认构造、带参构造
- 约分函数：reduce()
- 获取分子分母的接口

### 任务2：算术运算符重载（20分）

实现四则运算：
- `+` 加法
- `-` 减法
- `*` 乘法
- `/` 除法
- 对应的复合赋值运算符：`+=`, `-=`, `*=`, `/=`

### 任务3：关系运算符重载（15分）

实现比较运算：
- `==` 等于
- `!=` 不等于
- `<` 小于
- `>` 大于
- `<=` 小于等于
- `>=` 大于等于

### 任务4：赋值运算符重载（10分）

实现赋值运算：
- `=` 拷贝赋值运算符
- 包含自赋值检查

### 任务5：自增自减运算符重载（15分）

实现：
- 前置`++`：分数加1
- 后置`++`：分数加1
- 前置`--`：分数减1
- 后置`--`：分数减1

### 任务6：流运算符重载（10分）

实现：
- `<<` 输出运算符：格式为 "分子/分母"
- `>>` 输入运算符：接受 "分子/分母" 格式

### 任务7：函数调用运算符重载（5分）

实现：
- `()` 无参数版本：返回分数的小数值(double)

### 任务8：下标运算符重载（10分）

实现：
- `[]` 运算符：下标0返回分子，下标1返回分母
- 提供const和非const两个版本

### 任务9：类型转换运算符（5分）

实现：
- `operator double()`：将分数转换为double

## 测试用例

```cpp
int main() {
    // 测试构造和输出
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    cout << "f1 = " << f1 << endl;  // 1/2
    cout << "f2 = " << f2 << endl;  // 3/4

    // 测试算术运算
    cout << "f1 + f2 = " << f1 + f2 << endl;  // 5/4
    cout << "f1 - f2 = " << f1 - f2 << endl;  // -1/4
    cout << "f1 * f2 = " << f1 * f2 << endl;  // 3/8
    cout << "f1 / f2 = " << f1 / f2 << endl;  // 2/3

    // 测试关系运算
    cout << "f1 < f2: " << (f1 < f2) << endl;   // 1
    cout << "f1 == f2: " << (f1 == f2) << endl; // 0

    // 测试自增
    Fraction f3(1, 3);
    cout << "f3 = " << f3 << endl;      // 1/3
    cout << "++f3 = " << ++f3 << endl;  // 4/3
    cout << "f3++ = " << f3++ << endl;  // 4/3
    cout << "f3 = " << f3 << endl;      // 7/3

    // 测试下标
    cout << "f1[0] = " << f1[0] << ", f1[1] = " << f1[1] << endl;

    // 测试函数调用
    cout << "f1() = " << f1() << endl;  // 0.5

    // 测试类型转换
    double d = static_cast<double>(f1);
    cout << "double(f1) = " << d << endl;  // 0.5

    return 0;
}
```

## 评分标准

| 任务 | 分值 | 评分标准 |
|------|------|---------|
| 类基础结构 | 10分 | 成员变量、构造函数、约分功能正确 |
| 算术运算符 | 20分 | 四则运算正确，结果自动约分 |
| 关系运算符 | 15分 | 所有比较运算正确 |
| 赋值运算符 | 10分 | 赋值正确，有自赋值检查 |
| 自增自减 | 15分 | 前置后置区分正确，语义正确 |
| 流运算符 | 10分 | 输入输出格式正确 |
| 函数调用 | 5分 | 返回正确的小数值 |
| 下标运算符 | 10分 | 两个版本都实现，边界检查 |
| 类型转换 | 5分 | 转换结果正确 |

**总分：100分**

## 常见错误

1. **忘记约分**：运算结果应该自动约分
2. **分母为0**：除法和构造时要检查
3. **前置后置混淆**：注意返回类型和参数
4. **流运算符声明为成员函数**：必须是友元或普通函数
5. **赋值运算符没有返回引用**：影响链式赋值
6. **下标越界**：要进行边界检查

## 扩展思考

1. 如何实现分数与整数的混合运算？
2. 如何避免运算过程中的整数溢出？
3. 如何实现负号运算符（一元`-`）？
4. 如何让分数支持 `2 + f` 这样整数在前的运算？

## 参考资料

- C++ Primer 第14章：重载运算与类型转换
- Effective C++ 条款10：令operator=返回一个reference to *this
- More Effective C++ 条款22：考虑以操作符复合形式取代其独立形式
