/**
 * STL应用实验 - 图书馆管理系统
 * 标准答案
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

struct Book {
    string isbn;
    string title;
    string author;
    string category;
    double price;
    int stock;

    Book() : price(0), stock(0) {}

    Book(string isbn, string title, string author, string category, double price, int stock)
        : isbn(isbn), title(title), author(author), category(category), price(price), stock(stock) {}

    void display() const {
        cout << "ISBN: " << isbn << ", 书名: " << title
             << ", 作者: " << author << ", 分类: " << category
             << ", 价格: " << fixed << setprecision(2) << price
             << ", 库存: " << stock << endl;
    }
};

struct BorrowRequest {
    string userId;
    string isbn;
    bool isVip;
    string requestTime;

    BorrowRequest(string uid, string isbn, bool vip, string time)
        : userId(uid), isbn(isbn), isVip(vip), requestTime(time) {}

    void display() const {
        cout << "用户: " << userId << ", ISBN: " << isbn
             << ", VIP: " << (isVip ? "是" : "否")
             << ", 时间: " << requestTime << endl;
    }
};

// ==================== 图书馆管理类 ====================

class LibrarySystem {
private:
    vector<Book> bookList;
    list<BorrowRequest> borrowQueue;
    set<string> categories;
    map<string, Book> isbnToBook;
    unordered_map<string, string> titleToIsbn;

public:
    // ==================== 任务1: vector应用 ====================

    void addBook(const Book& book) {
        // 检查ISBN是否已存在
        if (isbnToBook.find(book.isbn) != isbnToBook.end()) {
            cout << "错误: ISBN " << book.isbn << " 已存在" << endl;
            return;
        }

        // 添加到vector
        bookList.push_back(book);

        // 更新map
        isbnToBook[book.isbn] = book;

        // 更新unordered_map
        titleToIsbn[book.title] = book.isbn;

        // 更新set
        categories.insert(book.category);

        cout << "成功添加图书: " << book.title << endl;
    }

    bool removeBook(const string& isbn) {
        // 在map中查找
        auto mapIt = isbnToBook.find(isbn);
        if (mapIt == isbnToBook.end()) {
            cout << "错误: 未找到ISBN " << isbn << endl;
            return false;
        }

        string title = mapIt->second.title;

        // 从vector中删除
        auto vecIt = find_if(bookList.begin(), bookList.end(),
            [&isbn](const Book& b) { return b.isbn == isbn; });
        if (vecIt != bookList.end()) {
            bookList.erase(vecIt);
        }

        // 从map中删除
        isbnToBook.erase(mapIt);

        // 从unordered_map中删除
        titleToIsbn.erase(title);

        cout << "成功删除图书: " << title << endl;
        return true;
    }

    bool updateStock(const string& isbn, int newStock) {
        // 在map中查找并更新
        auto mapIt = isbnToBook.find(isbn);
        if (mapIt == isbnToBook.end()) {
            return false;
        }
        mapIt->second.stock = newStock;

        // 同步更新vector
        auto vecIt = find_if(bookList.begin(), bookList.end(),
            [&isbn](const Book& b) { return b.isbn == isbn; });
        if (vecIt != bookList.end()) {
            vecIt->stock = newStock;
        }

        cout << "库存更新成功" << endl;
        return true;
    }

    Book* findBookByIsbn(const string& isbn) {
        auto it = isbnToBook.find(isbn);
        if (it != isbnToBook.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    void displayAllBooks() const {
        if (bookList.empty()) {
            cout << "图书列表为空" << endl;
            return;
        }

        cout << "\n=== 所有图书 (" << bookList.size() << "本) ===" << endl;
        for (const auto& book : bookList) {
            book.display();
        }
    }

    // ==================== 任务2: list应用 ====================

    void addBorrowRequest(const BorrowRequest& request) {
        if (request.isVip) {
            // VIP用户插入到第一个非VIP用户之前
            auto it = find_if(borrowQueue.begin(), borrowQueue.end(),
                [](const BorrowRequest& r) { return !r.isVip; });
            borrowQueue.insert(it, request);
        } else {
            borrowQueue.push_back(request);
        }
        cout << "借阅请求已添加" << endl;
    }

    BorrowRequest processBorrowRequest() {
        if (borrowQueue.empty()) {
            cout << "借阅队列为空" << endl;
            return BorrowRequest("", "", false, "");
        }

        BorrowRequest request = borrowQueue.front();
        borrowQueue.pop_front();

        // 更新库存
        auto it = isbnToBook.find(request.isbn);
        if (it != isbnToBook.end() && it->second.stock > 0) {
            it->second.stock--;
            // 同步vector
            auto vecIt = find_if(bookList.begin(), bookList.end(),
                [&request](const Book& b) { return b.isbn == request.isbn; });
            if (vecIt != bookList.end()) {
                vecIt->stock--;
            }
            cout << "借阅成功: " << request.userId << " 借阅 " << it->second.title << endl;
        } else {
            cout << "借阅失败: 库存不足" << endl;
        }

        return request;
    }

    bool cancelBorrowRequest(const string& userId, const string& isbn) {
        auto it = find_if(borrowQueue.begin(), borrowQueue.end(),
            [&](const BorrowRequest& r) {
                return r.userId == userId && r.isbn == isbn;
            });

        if (it != borrowQueue.end()) {
            borrowQueue.erase(it);
            cout << "借阅请求已取消" << endl;
            return true;
        }

        cout << "未找到该借阅请求" << endl;
        return false;
    }

    void displayBorrowQueue() const {
        if (borrowQueue.empty()) {
            cout << "借阅队列为空" << endl;
            return;
        }

        cout << "\n=== 借阅队列 (" << borrowQueue.size() << "个请求) ===" << endl;
        int i = 1;
        for (const auto& request : borrowQueue) {
            cout << i++ << ". ";
            request.display();
        }
    }

    // ==================== 任务3: set应用 ====================

    bool addCategory(const string& category) {
        auto result = categories.insert(category);
        if (result.second) {
            cout << "分类添加成功: " << category << endl;
            return true;
        }
        cout << "分类已存在: " << category << endl;
        return false;
    }

    bool removeCategory(const string& category) {
        if (categories.erase(category) > 0) {
            cout << "分类删除成功: " << category << endl;
            return true;
        }
        cout << "分类不存在: " << category << endl;
        return false;
    }

    bool hasCategory(const string& category) const {
        return categories.find(category) != categories.end();
    }

    vector<string> getAllCategories() const {
        return vector<string>(categories.begin(), categories.end());
    }

    void displayCategories() const {
        cout << "\n=== 图书分类 (" << categories.size() << "个) ===" << endl;
        for (const auto& cat : categories) {
            cout << "- " << cat << endl;
        }
    }

    // ==================== 任务4: map应用 ====================

    map<string, int> countByCategory() const {
        map<string, int> result;
        for (const auto& book : bookList) {
            result[book.category]++;
        }
        return result;
    }

    vector<Book> findBooksByPriceRange(double minPrice, double maxPrice) const {
        vector<Book> result;
        for (const auto& pair : isbnToBook) {
            if (pair.second.price >= minPrice && pair.second.price <= maxPrice) {
                result.push_back(pair.second);
            }
        }
        return result;
    }

    void displayCategoryStats() const {
        auto stats = countByCategory();
        cout << "\n=== 分类统计 ===" << endl;
        for (const auto& pair : stats) {
            cout << pair.first << ": " << pair.second << "本" << endl;
        }
    }

    // ==================== 任务5: unordered_map应用 ====================

    string findIsbnByTitle(const string& title) const {
        auto it = titleToIsbn.find(title);
        if (it != titleToIsbn.end()) {
            return it->second;
        }
        return "";
    }

    vector<Book> fuzzySearch(const string& keyword) const {
        vector<Book> result;
        for (const auto& pair : titleToIsbn) {
            if (pair.first.find(keyword) != string::npos) {
                auto bookIt = isbnToBook.find(pair.second);
                if (bookIt != isbnToBook.end()) {
                    result.push_back(bookIt->second);
                }
            }
        }
        return result;
    }

    void displayHashInfo() const {
        cout << "\n=== 哈希表性能信息 ===" << endl;
        cout << "桶数量: " << titleToIsbn.bucket_count() << endl;
        cout << "元素数量: " << titleToIsbn.size() << endl;
        cout << "负载因子: " << fixed << setprecision(4) << titleToIsbn.load_factor() << endl;
        cout << "最大负载因子: " << titleToIsbn.max_load_factor() << endl;
    }

    // ==================== 任务6: 迭代器使用 ====================

    void iterateForward() const {
        cout << "\n=== 正向遍历 ===" << endl;
        for (vector<Book>::const_iterator it = bookList.begin(); it != bookList.end(); ++it) {
            cout << it->title << " ";
        }
        cout << endl;
    }

    void iterateBackward() const {
        cout << "\n=== 反向遍历 ===" << endl;
        for (vector<Book>::const_reverse_iterator it = bookList.rbegin(); it != bookList.rend(); ++it) {
            cout << it->title << " ";
        }
        cout << endl;
    }

    void iterateCategories() const {
        cout << "\n=== 分类列表(const迭代器) ===" << endl;
        for (set<string>::const_iterator it = categories.cbegin(); it != categories.cend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void demonstrateIterators() const {
        iterateForward();
        iterateBackward();
        iterateCategories();

        // 使用distance和advance
        if (!bookList.empty()) {
            auto it = bookList.begin();
            advance(it, min((size_t)2, bookList.size() - 1));
            cout << "\n第3本书: " << it->title << endl;
            cout << "距离begin: " << distance(bookList.begin(), it) << endl;
        }
    }

    // ==================== 任务7: 算法应用 ====================

    vector<Book>::iterator findByAuthor(const string& author) {
        return find_if(bookList.begin(), bookList.end(),
            [&author](const Book& b) { return b.author == author; });
    }

    vector<Book> findAllByAuthor(const string& author) const {
        vector<Book> result;
        for (const auto& book : bookList) {
            if (book.author == author) {
                result.push_back(book);
            }
        }
        return result;
    }

    int countBySpecificCategory(const string& category) const {
        return count_if(bookList.begin(), bookList.end(),
            [&category](const Book& b) { return b.category == category; });
    }

    void sortByPrice(bool ascending = true) {
        if (ascending) {
            sort(bookList.begin(), bookList.end(),
                [](const Book& a, const Book& b) { return a.price < b.price; });
        } else {
            sort(bookList.begin(), bookList.end(),
                [](const Book& a, const Book& b) { return a.price > b.price; });
        }
        cout << "已按价格" << (ascending ? "升序" : "降序") << "排序" << endl;
    }

    void sortByTitle() {
        sort(bookList.begin(), bookList.end(),
            [](const Book& a, const Book& b) { return a.title < b.title; });
        cout << "已按书名排序" << endl;
    }

    void sortByStock() {
        sort(bookList.begin(), bookList.end(),
            [](const Book& a, const Book& b) { return a.stock > b.stock; });
        cout << "已按库存降序排序" << endl;
    }

    vector<string> getAllTitles() const {
        vector<string> titles(bookList.size());
        transform(bookList.begin(), bookList.end(), titles.begin(),
            [](const Book& b) { return b.title; });
        return titles;
    }

    vector<string> getAllIsbns() const {
        vector<string> isbns(bookList.size());
        transform(bookList.begin(), bookList.end(), isbns.begin(),
            [](const Book& b) { return b.isbn; });
        return isbns;
    }

    double calculateTotalValue() const {
        return accumulate(bookList.begin(), bookList.end(), 0.0,
            [](double sum, const Book& b) { return sum + b.price * b.stock; });
    }

    double calculateTotalPrice() const {
        return accumulate(bookList.begin(), bookList.end(), 0.0,
            [](double sum, const Book& b) { return sum + b.price; });
    }

    double calculateAveragePrice() const {
        if (bookList.empty()) return 0.0;
        return calculateTotalPrice() / bookList.size();
    }

    int calculateTotalStock() const {
        return accumulate(bookList.begin(), bookList.end(), 0,
            [](int sum, const Book& b) { return sum + b.stock; });
    }

    void applyDiscount(double discount) {
        for_each(bookList.begin(), bookList.end(),
            [discount](Book& b) { b.price *= discount; });

        // 同步map
        for (auto& pair : isbnToBook) {
            pair.second.price *= discount;
        }

        cout << "已应用" << (discount * 100) << "%折扣" << endl;
    }

    void demonstrateAlgorithms() const {
        cout << "\n=== 算法演示 ===" << endl;

        // 所有书名
        cout << "所有书名: ";
        auto titles = getAllTitles();
        for (const auto& t : titles) {
            cout << t << ", ";
        }
        cout << endl;

        // 统计
        cout << "总价值: " << fixed << setprecision(2) << calculateTotalValue() << endl;
        cout << "平均价格: " << calculateAveragePrice() << endl;
        cout << "总库存: " << calculateTotalStock() << endl;

        // 查找最贵的书
        if (!bookList.empty()) {
            auto maxIt = max_element(bookList.begin(), bookList.end(),
                [](const Book& a, const Book& b) { return a.price < b.price; });
            cout << "最贵的书: " << maxIt->title << " (" << maxIt->price << "元)" << endl;

            auto minIt = min_element(bookList.begin(), bookList.end(),
                [](const Book& a, const Book& b) { return a.price < b.price; });
            cout << "最便宜的书: " << minIt->title << " (" << minIt->price << "元)" << endl;
        }
    }

    // ==================== 任务8: 综合应用 ====================

    void displayStatistics() const {
        cout << "\n========== 系统统计 ==========" << endl;
        cout << "图书总数: " << bookList.size() << "本" << endl;
        cout << "分类数量: " << categories.size() << "个" << endl;
        cout << "总库存量: " << calculateTotalStock() << "册" << endl;
        cout << "总价值: " << fixed << setprecision(2) << calculateTotalValue() << "元" << endl;
        cout << "平均价格: " << calculateAveragePrice() << "元" << endl;
        cout << "借阅队列: " << borrowQueue.size() << "个请求" << endl;

        cout << "\n--- 分类统计 ---" << endl;
        auto stats = countByCategory();
        for (const auto& pair : stats) {
            cout << pair.first << ": " << pair.second << "本" << endl;
        }
    }

    void initSampleData() {
        // 添加示例图书
        addBook(Book("978-7-111-40701-0", "C++ Primer", "Stanley Lippman", "编程", 128.0, 10));
        addBook(Book("978-7-111-42752-0", "Effective C++", "Scott Meyers", "编程", 68.0, 15));
        addBook(Book("978-7-115-37944-8", "算法导论", "Thomas Cormen", "算法", 128.0, 8));
        addBook(Book("978-7-111-44129-8", "设计模式", "Erich Gamma", "软件工程", 79.0, 12));
        addBook(Book("978-7-302-33064-6", "数据结构", "严蔚敏", "数据结构", 45.0, 20));
        addBook(Book("978-7-111-52828-8", "深入理解计算机系统", "Randal Bryant", "计算机系统", 139.0, 6));
        addBook(Book("978-7-115-39383-3", "Python编程", "Eric Matthes", "编程", 89.0, 18));
        addBook(Book("978-7-111-57561-9", "机器学习", "周志华", "人工智能", 88.0, 14));

        // 添加示例借阅请求
        addBorrowRequest(BorrowRequest("U001", "978-7-111-40701-0", false, "2024-01-15 10:00"));
        addBorrowRequest(BorrowRequest("U002", "978-7-111-42752-0", true, "2024-01-15 10:30"));
        addBorrowRequest(BorrowRequest("U003", "978-7-111-40701-0", false, "2024-01-15 11:00"));

        cout << "\n示例数据初始化完成" << endl;
    }

    // 菜单处理函数
    void handleAddBook() {
        string isbn, title, author, category;
        double price;
        int stock;

        cout << "请输入ISBN: ";
        cin >> isbn;
        cout << "请输入书名: ";
        cin.ignore();
        getline(cin, title);
        cout << "请输入作者: ";
        getline(cin, author);
        cout << "请输入分类: ";
        getline(cin, category);
        cout << "请输入价格: ";
        cin >> price;
        cout << "请输入库存: ";
        cin >> stock;

        addBook(Book(isbn, title, author, category, price, stock));
    }

    void handleRemoveBook() {
        string isbn;
        cout << "请输入要删除的ISBN: ";
        cin >> isbn;
        removeBook(isbn);
    }

    void handleFindBook() {
        cout << "1. 按ISBN查找" << endl;
        cout << "2. 按书名查找" << endl;
        cout << "3. 模糊查找" << endl;
        cout << "请选择: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string isbn;
            cout << "请输入ISBN: ";
            cin >> isbn;
            Book* book = findBookByIsbn(isbn);
            if (book) {
                book->display();
            } else {
                cout << "未找到该图书" << endl;
            }
        } else if (choice == 2) {
            string title;
            cout << "请输入书名: ";
            cin.ignore();
            getline(cin, title);
            string isbn = findIsbnByTitle(title);
            if (!isbn.empty()) {
                Book* book = findBookByIsbn(isbn);
                if (book) book->display();
            } else {
                cout << "未找到该图书" << endl;
            }
        } else if (choice == 3) {
            string keyword;
            cout << "请输入关键字: ";
            cin.ignore();
            getline(cin, keyword);
            auto results = fuzzySearch(keyword);
            if (results.empty()) {
                cout << "未找到匹配的图书" << endl;
            } else {
                cout << "找到 " << results.size() << " 本图书:" << endl;
                for (const auto& book : results) {
                    book.display();
                }
            }
        }
    }

    void handleBorrowManagement() {
        cout << "1. 添加借阅请求" << endl;
        cout << "2. 处理借阅请求" << endl;
        cout << "3. 取消借阅请求" << endl;
        cout << "4. 显示借阅队列" << endl;
        cout << "请选择: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string userId, isbn, time;
            int vip;
            cout << "用户ID: ";
            cin >> userId;
            cout << "图书ISBN: ";
            cin >> isbn;
            cout << "是否VIP(1/0): ";
            cin >> vip;
            cout << "请求时间: ";
            cin.ignore();
            getline(cin, time);
            addBorrowRequest(BorrowRequest(userId, isbn, vip == 1, time));
        } else if (choice == 2) {
            processBorrowRequest();
        } else if (choice == 3) {
            string userId, isbn;
            cout << "用户ID: ";
            cin >> userId;
            cout << "图书ISBN: ";
            cin >> isbn;
            cancelBorrowRequest(userId, isbn);
        } else if (choice == 4) {
            displayBorrowQueue();
        }
    }

    void handleCategoryManagement() {
        cout << "1. 添加分类" << endl;
        cout << "2. 删除分类" << endl;
        cout << "3. 显示所有分类" << endl;
        cout << "4. 分类统计" << endl;
        cout << "请选择: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string category;
            cout << "请输入分类名: ";
            cin.ignore();
            getline(cin, category);
            addCategory(category);
        } else if (choice == 2) {
            string category;
            cout << "请输入分类名: ";
            cin.ignore();
            getline(cin, category);
            removeCategory(category);
        } else if (choice == 3) {
            displayCategories();
        } else if (choice == 4) {
            displayCategoryStats();
        }
    }

    void handleSort() {
        cout << "1. 按价格升序" << endl;
        cout << "2. 按价格降序" << endl;
        cout << "3. 按书名排序" << endl;
        cout << "4. 按库存排序" << endl;
        cout << "请选择: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            sortByPrice(true);
        } else if (choice == 2) {
            sortByPrice(false);
        } else if (choice == 3) {
            sortByTitle();
        } else if (choice == 4) {
            sortByStock();
        }

        displayAllBooks();
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
    cout << "10. 算法演示" << endl;
    cout << "11. 哈希信息" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请选择: ";
}

// ==================== 主函数 ====================

int main() {
    LibrarySystem library;

    // 初始化示例数据
    library.initSampleData();

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                library.handleAddBook();
                break;
            case 2:
                library.handleRemoveBook();
                break;
            case 3:
                library.handleFindBook();
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5:
                library.handleBorrowManagement();
                break;
            case 6:
                library.handleCategoryManagement();
                break;
            case 7:
                library.displayStatistics();
                break;
            case 8:
                library.handleSort();
                break;
            case 9:
                library.demonstrateIterators();
                break;
            case 10:
                library.demonstrateAlgorithms();
                break;
            case 11:
                library.displayHashInfo();
                break;
            case 0:
                cout << "感谢使用图书馆管理系统，再见！" << endl;
                break;
            default:
                cout << "无效选择，请重新输入" << endl;
        }
    } while (choice != 0);

    return 0;
}
