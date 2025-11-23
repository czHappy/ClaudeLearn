/**
 * 实验：类和对象 - 银行账户管理系统
 * 标准答案
 *
 * 知识点覆盖：
 * 1. 类的定义与成员访问控制
 * 2. 构造函数（默认构造、带参构造、成员初始化列表）
 * 3. 析构函数
 * 4. 拷贝构造函数
 * 5. const成员函数
 * 6. static成员变量与成员函数
 * 7. this指针与链式调用
 * 8. 友元函数
 * 9. 对象生命周期
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * 银行账户类
 */
class BankAccount {
private:
    // 私有成员变量：封装数据，外部无法直接访问
    string accountNumber;   // 账号
    string ownerName;       // 户名
    double balance;         // 余额

    // 静态成员变量：所有对象共享，用于统计信息
    static int totalAccounts;      // 账户总数
    static double totalDeposits;   // 总存款额

public:
    /**
     * 默认构造函数
     * 知识点：构造函数、成员初始化列表
     */
    BankAccount() : accountNumber("000000"), ownerName("未命名"), balance(0.0) {
        totalAccounts++;
        cout << "账户创建成功：[" << accountNumber << "] " << ownerName
             << "，初始余额：" << balance << "元" << endl;
    }

    /**
     * 带参数的构造函数
     * 知识点：构造函数重载、成员初始化列表
     *
     * @param accNum 账号
     * @param name 户名
     * @param initialBalance 初始余额
     */
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {
        totalAccounts++;
        totalDeposits += balance;
        cout << "账户创建成功：[" << accountNumber << "] " << ownerName
             << "，初始余额：" << fixed << setprecision(2) << balance << "元" << endl;
    }

    /**
     * 拷贝构造函数
     * 知识点：拷贝构造函数、对象复制
     *
     * @param other 要复制的账户对象
     *
     * 注意：账户复制时需要生成新的账号，避免账号重复
     */
    BankAccount(const BankAccount& other)
        : accountNumber(other.accountNumber + "-copy"),
          ownerName(other.ownerName),
          balance(other.balance) {
        totalAccounts++;
        totalDeposits += balance;
        cout << "账户创建成功（拷贝）：[" << accountNumber << "] " << ownerName
             << "，初始余额：" << fixed << setprecision(2) << balance << "元" << endl;
    }

    /**
     * 析构函数
     * 知识点：析构函数、资源清理
     *
     * 对象销毁时自动调用，用于清理资源、更新统计信息
     */
    ~BankAccount() {
        totalAccounts--;
        totalDeposits -= balance;
        cout << "账户销毁：[" << accountNumber << "] " << ownerName << endl;
    }

    /**
     * 存款
     * 知识点：this指针、链式调用
     *
     * @param amount 存款金额
     * @return 返回对象引用，支持链式调用
     */
    BankAccount& deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            totalDeposits += amount;
            cout << ownerName << " 存款 " << fixed << setprecision(2)
                 << amount << " 元" << endl;
        } else {
            cout << "存款金额必须大于0！" << endl;
        }
        return *this;  // 返回当前对象引用，支持链式调用
    }

    /**
     * 取款
     * 知识点：this指针、链式调用
     *
     * @param amount 取款金额
     * @return 返回对象引用，支持链式调用
     */
    BankAccount& withdraw(double amount) {
        if (amount > 0) {
            if (this->balance >= amount) {
                this->balance -= amount;
                totalDeposits -= amount;
                cout << ownerName << " 取款 " << fixed << setprecision(2)
                     << amount << " 元" << endl;
            } else {
                cout << "余额不足！当前余额：" << fixed << setprecision(2)
                     << balance << "元" << endl;
            }
        } else {
            cout << "取款金额必须大于0！" << endl;
        }
        return *this;  // 返回当前对象引用，支持链式调用
    }

    /**
     * 获取余额
     * 知识点：const成员函数
     *
     * const修饰表示该函数不会修改对象状态
     * const对象只能调用const成员函数
     */
    double getBalance() const {
        return balance;
    }

    /**
     * 获取账号
     * 知识点：const成员函数
     */
    string getAccountNumber() const {
        return accountNumber;
    }

    /**
     * 获取户名
     * 知识点：const成员函数
     */
    string getOwnerName() const {
        return ownerName;
    }

    /**
     * 显示账户信息
     * 知识点：const成员函数、格式化输出
     */
    void displayInfo() const {
        cout << "账号：" << accountNumber << endl;
        cout << "户名：" << ownerName << endl;
        cout << "余额：" << fixed << setprecision(2) << balance << "元" << endl;
    }

    /**
     * 获取账户总数
     * 知识点：static成员函数
     *
     * 静态成员函数属于类，不属于某个对象
     * 可以通过类名直接调用：BankAccount::getTotalAccounts()
     * 静态成员函数没有this指针，只能访问静态成员
     */
    static int getTotalAccounts() {
        return totalAccounts;
    }

    /**
     * 获取总存款额
     * 知识点：static成员函数
     */
    static double getTotalDeposits() {
        return totalDeposits;
    }

    /**
     * 友元函数声明
     * 知识点：友元函数
     *
     * 友元函数不是成员函数，但可以访问类的私有成员
     * 用于实现需要操作多个对象私有数据的功能（如转账）
     */
    friend void transfer(BankAccount& from, BankAccount& to, double amount);
};

// 静态成员变量必须在类外初始化
// 知识点：静态成员变量初始化
int BankAccount::totalAccounts = 0;
double BankAccount::totalDeposits = 0.0;

/**
 * 转账函数（友元函数）
 * 知识点：友元函数、直接访问私有成员
 *
 * @param from 转出账户
 * @param to 转入账户
 * @param amount 转账金额
 *
 * 作为友元函数，可以直接访问对象的私有成员
 * 适合实现需要同时操作多个对象私有数据的功能
 */
void transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount <= 0) {
        cout << "转账金额必须大于0！" << endl;
        return;
    }

    // 友元函数可以直接访问私有成员 balance
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << from.ownerName << " 向 " << to.ownerName << " 转账 "
             << fixed << setprecision(2) << amount << " 元" << endl;
    } else {
        cout << "转账失败：余额不足！" << endl;
        cout << from.ownerName << " 当前余额：" << fixed << setprecision(2)
             << from.balance << "元" << endl;
    }
}

/**
 * 演示对象生命周期
 * 知识点：对象的创建与销毁、作用域
 *
 * 局部对象在函数结束时自动销毁（调用析构函数）
 */
void demonstrateLifecycle() {
    cout << "  创建临时账户..." << endl;
    BankAccount tempAccount("TEMP", "临时用户", 100.0);
    cout << "  离开演示函数，临时账户即将销毁..." << endl;
    // 函数结束时，tempAccount自动销毁，调用析构函数
}

/**
 * 主函数 - 演示所有功能
 */
int main() {
    cout << "========== 银行账户管理系统 ==========" << endl << endl;

    // 任务1：创建账户
    // 知识点：构造函数的调用
    cout << "--- 创建账户 ---" << endl;
    BankAccount account1("001", "张三", 1000.0);
    BankAccount account2("002", "李四", 2000.0);
    cout << endl;

    // 任务2：显示账户信息
    // 知识点：const成员函数的调用
    cout << "--- 账户信息 ---" << endl;
    account1.displayInfo();
    cout << endl;

    // 任务3：存取款操作
    // 知识点：成员函数调用、this指针
    cout << "--- 存取款操作 ---" << endl;
    account1.deposit(500);
    account1.withdraw(200);
    cout << "当前余额：" << fixed << setprecision(2)
         << account1.getBalance() << "元" << endl;
    cout << endl;

    // 任务4：链式调用演示
    // 知识点：链式调用、返回*this
    cout << "--- 链式调用演示 ---" << endl;
    cout << account2.getOwnerName() << " 执行链式操作：.deposit(300).withdraw(100).deposit(500)" << endl;
    account2.deposit(300).withdraw(100).deposit(500);
    cout << "当前余额：" << fixed << setprecision(2)
         << account2.getBalance() << "元" << endl;
    cout << endl;

    // 任务5：转账演示
    // 知识点：友元函数
    cout << "--- 转账演示 ---" << endl;
    cout << "转账前：" << endl;
    cout << "  " << account1.getOwnerName() << " 余额："
         << fixed << setprecision(2) << account1.getBalance() << "元" << endl;
    cout << "  " << account2.getOwnerName() << " 余额："
         << fixed << setprecision(2) << account2.getBalance() << "元" << endl;

    transfer(account1, account2, 500.0);

    cout << "转账后：" << endl;
    cout << "  " << account1.getOwnerName() << " 余额："
         << fixed << setprecision(2) << account1.getBalance() << "元" << endl;
    cout << "  " << account2.getOwnerName() << " 余额："
         << fixed << setprecision(2) << account2.getBalance() << "元" << endl;
    cout << endl;

    // 任务6：拷贝构造演示
    // 知识点：拷贝构造函数
    cout << "--- 拷贝构造演示 ---" << endl;
    cout << "使用 " << account1.getOwnerName() << " 的账户创建新账户" << endl;
    BankAccount account3 = account1;  // 调用拷贝构造函数
    account3.displayInfo();
    cout << endl;

    // 任务7：显示统计信息
    // 知识点：static成员函数、通过类名调用
    cout << "--- 统计信息 ---" << endl;
    cout << "账户总数：" << BankAccount::getTotalAccounts() << endl;
    cout << "总存款额：" << fixed << setprecision(2)
         << BankAccount::getTotalDeposits() << "元" << endl;
    cout << endl;

    // 任务8：对象生命周期演示
    // 知识点：对象的生命周期、作用域
    cout << "--- 对象生命周期演示 ---" << endl;
    cout << "进入演示函数..." << endl;
    demonstrateLifecycle();
    cout << "已离开演示函数，临时账户已销毁" << endl;
    cout << endl;

    // 显示当前统计信息（临时账户已销毁）
    cout << "销毁临时账户后的统计信息：" << endl;
    cout << "账户总数：" << BankAccount::getTotalAccounts() << endl;
    cout << "总存款额：" << fixed << setprecision(2)
         << BankAccount::getTotalDeposits() << "元" << endl;
    cout << endl;

    cout << "--- 程序结束 ---" << endl;
    // 程序结束时，account1, account2, account3 自动销毁
    // 销毁顺序与创建顺序相反：account3 -> account2 -> account1
    return 0;
}
