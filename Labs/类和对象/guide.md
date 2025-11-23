# 实验：类和对象 - 银行账户管理系统

## 一、实验目的

通过设计和实现一个银行账户管理系统，掌握C++面向对象编程的核心概念：

1. 理解类的定义与成员访问控制（public, private, protected）
2. 掌握构造函数与析构函数的使用
3. 理解拷贝构造函数的作用与实现
4. 学会使用成员初始化列表
5. 理解this指针的含义与应用
6. 掌握const成员函数的使用场景
7. 理解static成员变量与成员函数
8. 学会使用友元函数与友元类
9. 理解对象的生命周期

## 二、实验背景

银行账户是日常生活中常见的概念，每个账户都有账号、户名、余额等属性，可以进行存款、取款、查询等操作。我们将用C++类来模拟这个真实场景，体会面向对象编程的优势。

## 三、知识点详解

### 3.1 类的定义与访问控制

```cpp
class BankAccount {
private:      // 私有成员：只能在类内部访问
    string accountNumber;
    double balance;

protected:    // 保护成员：类内部和派生类可访问
    string ownerName;

public:       // 公有成员：任何地方都可访问
    void deposit(double amount);
    double getBalance() const;
};
```

**访问控制原则**：
- `private`：数据成员通常设为私有，实现数据封装
- `public`：接口函数设为公有，供外部调用
- `protected`：为继承预留，派生类可访问

### 3.2 构造函数与析构函数

```cpp
class BankAccount {
public:
    // 默认构造函数
    BankAccount();

    // 带参数的构造函数
    BankAccount(string accNum, string name, double initialBalance);

    // 析构函数：对象销毁时自动调用
    ~BankAccount();
};
```

**要点**：
- 构造函数名与类名相同，无返回类型
- 可以重载多个构造函数
- 析构函数名是`~类名`，不能重载，不能有参数

### 3.3 成员初始化列表

```cpp
// 推荐方式：使用初始化列表
BankAccount::BankAccount(string accNum, string name, double bal)
    : accountNumber(accNum), ownerName(name), balance(bal) {
    // 构造函数体
}

// 不推荐：在函数体内赋值
BankAccount::BankAccount(string accNum, string name, double bal) {
    accountNumber = accNum;  // 这是赋值，不是初始化
    ownerName = name;
    balance = bal;
}
```

**初始化列表的优势**：
- 效率更高（直接初始化 vs 先默认构造再赋值）
- const成员和引用成员必须使用初始化列表
- 成员对象没有默认构造函数时必须使用

### 3.4 拷贝构造函数

```cpp
// 拷贝构造函数声明
BankAccount(const BankAccount& other);

// 实现示例
BankAccount::BankAccount(const BankAccount& other)
    : ownerName(other.ownerName), balance(other.balance) {
    // 生成新的账号，避免两个账户有相同账号
    accountNumber = generateNewAccountNumber();
}
```

**调用时机**：
- 用一个对象初始化另一个对象：`BankAccount acc2 = acc1;`
- 对象作为函数参数按值传递
- 对象作为函数返回值

### 3.5 this指针

```cpp
class BankAccount {
public:
    // this指针指向调用该成员函数的对象
    BankAccount& deposit(double amount) {
        this->balance += amount;  // this->可省略
        return *this;  // 返回对象本身，支持链式调用
    }

    BankAccount& withdraw(double amount) {
        if (this->balance >= amount) {
            this->balance -= amount;
        }
        return *this;
    }
};

// 链式调用示例
account.deposit(100).withdraw(50).deposit(200);
```

### 3.6 const成员函数

```cpp
class BankAccount {
public:
    // const成员函数：承诺不修改对象状态
    double getBalance() const {
        // balance = 0;  // 错误！不能修改成员变量
        return balance;
    }

    string getAccountNumber() const;
    void displayInfo() const;

    // 非const成员函数：可能修改对象状态
    void deposit(double amount);
};
```

**const函数规则**：
- const对象只能调用const成员函数
- const成员函数中不能修改成员变量（除非是mutable成员）
- const成员函数中不能调用非const成员函数

### 3.7 static成员

```cpp
class BankAccount {
private:
    static int totalAccounts;      // 静态成员变量：所有对象共享
    static double totalDeposits;

public:
    static int getTotalAccounts() {  // 静态成员函数
        return totalAccounts;
    }

    static double getTotalDeposits() {
        return totalDeposits;
    }
};

// 静态成员变量必须在类外初始化
int BankAccount::totalAccounts = 0;
double BankAccount::totalDeposits = 0.0;
```

**静态成员特点**：
- 属于类而非对象，所有对象共享
- 静态成员函数没有this指针
- 静态成员函数只能访问静态成员
- 可通过类名直接访问：`BankAccount::getTotalAccounts()`

### 3.8 友元函数与友元类

```cpp
class BankAccount {
    friend void transfer(BankAccount& from, BankAccount& to, double amount);
    friend class BankManager;  // 友元类

private:
    double balance;
};

// 友元函数可以访问私有成员
void transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;  // 可以直接访问私有成员
        to.balance += amount;
    }
}
```

**友元特点**：
- 友元不是成员函数，但可以访问私有成员
- 友元关系不能传递
- 友元关系是单向的
- 过度使用友元会破坏封装性

### 3.9 对象生命周期

```cpp
void demonstrateLifecycle() {
    cout << "--- 进入函数 ---" << endl;

    BankAccount acc1("001", "张三", 1000);  // 调用构造函数

    {
        cout << "--- 进入内部作用域 ---" << endl;
        BankAccount acc2("002", "李四", 2000);  // 调用构造函数
        cout << "--- 离开内部作用域 ---" << endl;
    }  // acc2析构

    BankAccount* acc3 = new BankAccount("003", "王五", 3000);  // 堆上创建
    delete acc3;  // 手动销毁，调用析构函数

    cout << "--- 离开函数 ---" << endl;
}  // acc1析构
```

## 四、实验任务

### 任务1：定义BankAccount类（基本框架）

实现包含以下私有成员的类：
- `accountNumber`：账号（string类型）
- `ownerName`：户名（string类型）
- `balance`：余额（double类型）

### 任务2：实现构造函数

1. **默认构造函数**：账号设为"000000"，户名为"未命名"，余额为0
2. **带参构造函数**：使用成员初始化列表初始化所有成员
3. 在构造函数中增加账户总数统计

### 任务3：实现析构函数

- 输出账户销毁信息（包含账号和户名）
- 更新账户总数统计

### 任务4：实现拷贝构造函数

- 复制户名和余额
- 生成新的账号（原账号后加"-copy"）
- 更新统计信息

### 任务5：实现const成员函数

- `getBalance()`：获取余额
- `getAccountNumber()`：获取账号
- `getOwnerName()`：获取户名
- `displayInfo()`：显示账户信息

### 任务6：实现static成员

- `totalAccounts`：账户总数
- `totalDeposits`：总存款额
- `getTotalAccounts()`：获取账户总数
- `getTotalDeposits()`：获取总存款额

### 任务7：实现支持链式调用的成员函数

- `deposit(double amount)`：存款，返回`*this`
- `withdraw(double amount)`：取款，返回`*this`

### 任务8：实现友元函数

- `transfer(BankAccount& from, BankAccount& to, double amount)`：转账操作

### 任务9：编写main函数演示

1. 创建多个账户
2. 演示存款、取款操作
3. 演示链式调用
4. 演示转账
5. 显示统计信息
6. 演示对象生命周期

## 五、预期输出示例

```
========== 银行账户管理系统 ==========

--- 创建账户 ---
账户创建成功：[001] 张三，初始余额：1000元
账户创建成功：[002] 李四，初始余额：2000元

--- 账户信息 ---
账号：001
户名：张三
余额：1000元

--- 存取款操作 ---
张三 存款 500 元
张三 取款 200 元
当前余额：1300元

--- 链式调用演示 ---
李四.deposit(300).withdraw(100).deposit(500)
当前余额：2700元

--- 转账演示 ---
转账前：
  张三余额：1300元
  李四余额：2700元
张三 向 李四 转账 500 元
转账后：
  张三余额：800元
  李四余额：3200元

--- 拷贝构造演示 ---
使用张三的账户创建新账户
账户创建成功：[001-copy] 张三，初始余额：800元

--- 统计信息 ---
账户总数：3
总存款额：4800元

--- 对象生命周期演示 ---
进入演示函数...
  创建临时账户：[TEMP] 临时用户
  离开演示函数...
  账户销毁：[TEMP] 临时用户

--- 程序结束 ---
账户销毁：[001-copy] 张三
账户销毁：[002] 李四
账户销毁：[001] 张三
```

## 六、评分标准

| 评分项 | 分值 | 说明 |
|--------|------|------|
| 类定义正确 | 10分 | 成员变量和函数声明正确 |
| 访问控制 | 10分 | 正确使用public/private |
| 构造函数 | 15分 | 默认构造、带参构造、初始化列表 |
| 析构函数 | 10分 | 正确实现，输出销毁信息 |
| 拷贝构造函数 | 10分 | 正确复制并生成新账号 |
| const成员函数 | 10分 | 正确使用const修饰 |
| static成员 | 15分 | 正确定义和使用静态成员 |
| this指针与链式调用 | 10分 | 正确返回*this |
| 友元函数 | 10分 | 正确实现转账功能 |

## 七、思考题

1. 为什么要将数据成员设为private而不是public？
2. 什么情况下必须使用成员初始化列表？
3. 如果不定义拷贝构造函数，编译器会如何处理对象拷贝？
4. static成员函数为什么不能访问非static成员？
5. 友元函数和成员函数有什么区别？何时应该使用友元？

## 八、提交要求

1. 完成`submit.cpp`中所有标记为`// TODO`的部分
2. 确保程序能够编译通过并正确运行
3. 输出格式尽量与预期输出保持一致
4. 添加必要的注释说明你的实现思路

## 九、参考资料

- 《C++ Primer》第7章：类
- cppreference.com - Classes
- 课程PPT：面向对象编程基础
