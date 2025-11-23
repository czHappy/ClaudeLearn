/**
 * STL应用实验 - 图书馆管理系统
 * 学生提交模板
 *
 * 姓名：___________
 * 学号：___________
 * 日期：___________
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iomanip>

using namespace std;

// ==================== 数据结构定义 ====================

// 图书结构体
struct Book {
    string isbn;        // ISBN号
    string title;       // 书名
    string author;      // 作者
    string category;    // 分类
    double price;       // 价格
    int stock;          // 库存数量

    // TODO: 实现构造函数
    Book() {}

    Book(string isbn, string title, string author, string category, double price, int stock) {
        // 请在此处实现
    }

    // 用于输出
    void display() const {
        cout << "ISBN: " << isbn << ", 书名: " << title
             << ", 作者: " << author << ", 分类: " << category
             << ", 价格: " << price << ", 库存: " << stock << endl;
    }
};

// 借阅请求结构体
struct BorrowRequest {
    string userId;      // 用户ID
    string isbn;        // 图书ISBN
    bool isVip;         // 是否VIP用户
    string requestTime; // 请求时间

    BorrowRequest(string uid, string isbn, bool vip, string time)
        : userId(uid), isbn(isbn), isVip(vip), requestTime(time) {}
};

// ==================== 图书馆管理类 ====================

class LibrarySystem {
private:
    // 任务1: vector - 图书列表
    vector<Book> bookList;

    // 任务2: list - 借阅队列
    list<BorrowRequest> borrowQueue;

    // 任务3: set - 图书分类
    set<string> categories;

    // 任务4: map - ISBN到图书的映射
    map<string, Book> isbnToBook;

    // 任务5: unordered_map - 书名到ISBN的映射
    unordered_map<string, string> titleToIsbn;

public:
    // ==================== 任务1: vector应用 ====================

    /**
     * 添加图书到列表
     * @param book 要添加的图书
     */
    void addBook(const Book& book) {
        // TODO: 实现添加图书功能
        // 1. 添加到vector
        // 2. 同时更新其他容器（map, unordered_map, set）
    }

    /**
     * 根据ISBN删除图书
     * @param isbn 要删除的图书ISBN
     * @return 是否删除成功
     */
    bool removeBook(const string& isbn) {
        // TODO: 实现删除图书功能
        // 提示: 使用find_if查找，注意同步删除其他容器中的数据
        return false;
    }

    /**
     * 修改图书库存
     * @param isbn 图书ISBN
     * @param newStock 新库存数量
     * @return 是否修改成功
     */
    bool updateStock(const string& isbn, int newStock) {
        // TODO: 实现修改库存功能
        return false;
    }

    /**
     * 根据ISBN查找图书
     * @param isbn 图书ISBN
     * @return 指向图书的指针，未找到返回nullptr
     */
    Book* findBookByIsbn(const string& isbn) {
        // TODO: 实现查找功能
        // 提示: 可以使用map快速查找
        return nullptr;
    }

    /**
     * 显示所有图书
     */
    void displayAllBooks() const {
        // TODO: 实现显示所有图书
        // 提示: 遍历vector并调用Book的display方法
    }

    // ==================== 任务2: list应用 ====================

    /**
     * 添加借阅请求到队列
     * @param request 借阅请求
     */
    void addBorrowRequest(const BorrowRequest& request) {
        // TODO: 实现借阅请求入队
        // VIP用户应该排在普通用户前面
    }

    /**
     * 处理下一个借阅请求
     * @return 处理的请求，队列为空返回空请求
     */
    BorrowRequest processBorrowRequest() {
        // TODO: 实现处理借阅请求（出队）
        return BorrowRequest("", "", false, "");
    }

    /**
     * 取消借阅请求
     * @param userId 用户ID
     * @param isbn 图书ISBN
     * @return 是否取消成功
     */
    bool cancelBorrowRequest(const string& userId, const string& isbn) {
        // TODO: 实现取消借阅请求
        // 提示: 使用list的remove_if或遍历删除
        return false;
    }

    /**
     * 显示借阅队列
     */
    void displayBorrowQueue() const {
        // TODO: 显示当前借阅队列
    }

    // ==================== 任务3: set应用 ====================

    /**
     * 添加图书分类
     * @param category 分类名称
     * @return 是否添加成功（已存在返回false）
     */
    bool addCategory(const string& category) {
        // TODO: 实现添加分类
        return false;
    }

    /**
     * 删除图书分类
     * @param category 分类名称
     * @return 是否删除成功
     */
    bool removeCategory(const string& category) {
        // TODO: 实现删除分类
        return false;
    }

    /**
     * 检查分类是否存在
     * @param category 分类名称
     * @return 是否存在
     */
    bool hasCategory(const string& category) const {
        // TODO: 实现分类查询
        return false;
    }

    /**
     * 获取所有分类
     * @return 所有分类的vector
     */
    vector<string> getAllCategories() const {
        // TODO: 返回所有分类
        // 提示: set已经是有序的
        return vector<string>();
    }

    // ==================== 任务4: map应用 ====================

    /**
     * 统计各分类的图书数量
     * @return 分类到数量的映射
     */
    map<string, int> countByCategory() const {
        // TODO: 统计各分类图书数量
        return map<string, int>();
    }

    /**
     * 按价格区间查询图书
     * @param minPrice 最低价格
     * @param maxPrice 最高价格
     * @return 符合条件的图书列表
     */
    vector<Book> findBooksByPriceRange(double minPrice, double maxPrice) const {
        // TODO: 实现价格区间查询
        return vector<Book>();
    }

    // ==================== 任务5: unordered_map应用 ====================

    /**
     * 通过书名查找ISBN
     * @param title 书名
     * @return ISBN，未找到返回空字符串
     */
    string findIsbnByTitle(const string& title) const {
        // TODO: 实现通过书名查找ISBN
        return "";
    }

    /**
     * 模糊查询（书名包含关键字）
     * @param keyword 关键字
     * @return 匹配的图书列表
     */
    vector<Book> fuzzySearch(const string& keyword) const {
        // TODO: 实现模糊查询
        return vector<Book>();
    }

    /**
     * 显示哈希表性能信息
     */
    void displayHashInfo() const {
        // TODO: 显示unordered_map的性能信息
        // 包括: bucket_count, load_factor, max_load_factor
    }

    // ==================== 任务6: 迭代器使用 ====================

    /**
     * 使用正向迭代器遍历图书
     */
    void iterateForward() const {
        cout << "=== 正向遍历 ===" << endl;
        // TODO: 使用begin()和end()遍历
    }

    /**
     * 使用反向迭代器遍历图书
     */
    void iterateBackward() const {
        cout << "=== 反向遍历 ===" << endl;
        // TODO: 使用rbegin()和rend()遍历
    }

    /**
     * 使用const迭代器遍历分类
     */
    void iterateCategories() const {
        cout << "=== 分类列表 ===" << endl;
        // TODO: 使用cbegin()和cend()遍历set
    }

    // ==================== 任务7: 算法应用 ====================

    /**
     * 使用find_if查找特定作者的图书
     * @param author 作者名
     * @return 指向图书的迭代器
     */
    vector<Book>::iterator findByAuthor(const string& author) {
        // TODO: 使用find_if算法
        return bookList.end();
    }

    /**
     * 统计特定分类的图书数量
     * @param category 分类名
     * @return 数量
     */
    int countBySpecificCategory(const string& category) const {
        // TODO: 使用count_if算法
        return 0;
    }

    /**
     * 按价格排序图书
     * @param ascending 是否升序
     */
    void sortByPrice(bool ascending = true) {
        // TODO: 使用sort算法
    }

    /**
     * 按书名排序图书
     */
    void sortByTitle() {
        // TODO: 使用sort算法
    }

    /**
     * 获取所有图书的书名列表
     * @return 书名列表
     */
    vector<string> getAllTitles() const {
        // TODO: 使用transform算法
        return vector<string>();
    }

    /**
     * 计算所有图书的总价值
     * @return 总价值（价格*库存的总和）
     */
    double calculateTotalValue() const {
        // TODO: 使用accumulate算法
        return 0.0;
    }

    /**
     * 计算平均价格
     * @return 平均价格
     */
    double calculateAveragePrice() const {
        // TODO: 使用accumulate算法
        return 0.0;
    }

    /**
     * 对所有图书价格打折
     * @param discount 折扣率（如0.8表示8折）
     */
    void applyDiscount(double discount) {
        // TODO: 使用for_each或transform算法
    }

    // ==================== 任务8: 综合应用 ====================

    /**
     * 显示系统统计信息
     */
    void displayStatistics() const {
        cout << "\n========== 系统统计 ==========" << endl;
        // TODO: 显示各种统计信息
        // 包括: 图书总数、分类数、总价值、平均价格、借阅队列长度等
    }

    /**
     * 初始化示例数据
     */
    void initSampleData() {
        // TODO: 添加一些示例图书数据
    }
};

// ==================== 主菜单函数 ====================

void displayMenu() {
    cout << "\n========== 图书馆管理系统 ==========" << endl;
    cout << "1. 添加图书" << endl;
    cout << "2. 删除图书" << endl;
    cout << "3. 查找图书" << endl;
    cout << "4. 显示所有图书" << endl;
    cout << "5. 借阅管理" << endl;
    cout << "6. 分类管理" << endl;
    cout << "7. 统计信息" << endl;
    cout << "8. 排序显示" << endl;
    cout << "9. 迭代器演示" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请选择: ";
}

// ==================== 主函数 ====================

int main() {
    LibrarySystem library;

    // 初始化示例数据
    library.initSampleData();

    int choice;

    // TODO: 实现主循环和菜单交互
    // 提示: 使用while循环和switch语句

    cout << "=== STL应用实验 - 图书馆管理系统 ===" << endl;
    cout << "请完成各个TODO部分的实现" << endl;

    // 示例：显示统计信息
    library.displayStatistics();

    return 0;
}
