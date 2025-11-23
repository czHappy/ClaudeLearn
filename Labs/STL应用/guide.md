# STL应用实验指导书

## 实验信息

- **实验名称**: STL应用 - 图书馆管理系统
- **实验学时**: 4学时
- **实验类型**: 综合性实验

## 一、实验目的

1. 掌握STL序列容器（vector、list、deque）的使用方法
2. 掌握STL关联容器（set、map）的使用方法
3. 掌握STL无序容器（unordered_set、unordered_map）的使用方法
4. 理解迭代器的类型与使用方式
5. 熟练运用STL常用算法（find、count、sort、transform、accumulate等）
6. 能够综合运用STL容器和算法解决实际问题

## 二、实验环境

- 操作系统: Windows/Linux
- 编译器: g++ (支持C++11及以上标准)
- 编译命令: `g++ -std=c++11 -o library submit.cpp`

## 三、知识要点

### 3.1 容器概述

#### 序列容器
- **vector**: 动态数组，支持随机访问，尾部插入删除高效
- **list**: 双向链表，任意位置插入删除高效，不支持随机访问
- **deque**: 双端队列，两端插入删除高效，支持随机访问

#### 关联容器
- **set**: 有序集合，元素唯一，基于红黑树
- **map**: 有序键值对，键唯一，基于红黑树
- **multiset/multimap**: 允许重复键

#### 无序容器
- **unordered_set**: 哈希集合，平均O(1)查找
- **unordered_map**: 哈希映射，平均O(1)查找

### 3.2 vector的使用与内存管理

```cpp
#include <vector>
using namespace std;

vector<int> vec;              // 创建空vector
vec.push_back(10);            // 尾部添加
vec.pop_back();               // 尾部删除
vec[0] = 5;                   // 随机访问
vec.size();                   // 元素个数
vec.capacity();               // 当前容量
vec.reserve(100);             // 预分配空间
vec.resize(50);               // 调整大小
vec.clear();                  // 清空
vec.empty();                  // 是否为空
```

### 3.3 list与deque

```cpp
#include <list>
#include <deque>

// list操作
list<int> lst;
lst.push_front(1);            // 头部插入
lst.push_back(2);             // 尾部插入
lst.insert(it, 3);            // 迭代器位置插入
lst.erase(it);                // 删除迭代器位置元素
lst.remove(5);                // 删除所有值为5的元素
lst.sort();                   // 排序
lst.unique();                 // 去重（需先排序）

// deque操作
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
dq[0] = 10;                   // 支持随机访问
```

### 3.4 set与map

```cpp
#include <set>
#include <map>

// set操作
set<int> s;
s.insert(10);                 // 插入
s.erase(10);                  // 删除
s.find(10);                   // 查找，返回迭代器
s.count(10);                  // 计数（0或1）

// map操作
map<string, int> m;
m["key"] = 100;               // 插入/修改
m.insert({"key2", 200});      // 插入
m.erase("key");               // 删除
m.find("key");                // 查找
m.count("key");               // 是否存在
```

### 3.5 unordered_set与unordered_map

```cpp
#include <unordered_set>
#include <unordered_map>

// 接口与set/map类似，但基于哈希表
unordered_set<int> us;
unordered_map<string, int> um;

// 哈希相关
um.bucket_count();            // 桶数量
um.load_factor();             // 负载因子
um.rehash(100);               // 重新哈希
```

### 3.6 迭代器的类型与使用

```cpp
// 迭代器类型
vector<int>::iterator it;              // 普通迭代器
vector<int>::const_iterator cit;       // 常量迭代器
vector<int>::reverse_iterator rit;     // 反向迭代器

// 获取迭代器
vec.begin();  vec.end();               // 正向
vec.rbegin(); vec.rend();              // 反向
vec.cbegin(); vec.cend();              // 常量

// 迭代器操作
++it; --it;                            // 移动
*it;                                   // 解引用
it1 == it2;                            // 比较
it + n; it - n;                        // 随机访问迭代器
distance(it1, it2);                    // 距离
advance(it, n);                        // 移动n步
```

### 3.7 常用算法

```cpp
#include <algorithm>
#include <numeric>

// 查找算法
find(vec.begin(), vec.end(), value);           // 线性查找
find_if(vec.begin(), vec.end(), pred);         // 条件查找
binary_search(vec.begin(), vec.end(), value);  // 二分查找
lower_bound(vec.begin(), vec.end(), value);    // 下界
upper_bound(vec.begin(), vec.end(), value);    // 上界

// 计数算法
count(vec.begin(), vec.end(), value);          // 计数
count_if(vec.begin(), vec.end(), pred);        // 条件计数

// 排序算法
sort(vec.begin(), vec.end());                  // 排序
sort(vec.begin(), vec.end(), comp);            // 自定义比较
stable_sort(vec.begin(), vec.end());           // 稳定排序
partial_sort(vec.begin(), vec.begin()+n, vec.end()); // 部分排序

// 变换算法
transform(src.begin(), src.end(), dst.begin(), func);
for_each(vec.begin(), vec.end(), func);

// 数值算法
accumulate(vec.begin(), vec.end(), init);      // 累加
accumulate(vec.begin(), vec.end(), init, op);  // 自定义操作
```

## 四、实验背景

某图书馆需要开发一个图书管理系统，要求使用C++ STL容器和算法实现以下功能：
- 图书信息的存储和管理
- 借阅队列的维护
- 图书分类管理
- 快速检索功能
- 统计分析功能

## 五、实验任务

### 任务1: vector应用 - 图书列表管理 (15分)

使用vector存储图书列表，实现增删改查功能。

**要求**:
- 定义Book结构体（ISBN、书名、作者、价格、库存）
- 实现添加图书功能
- 实现删除图书功能（按ISBN）
- 实现修改图书信息功能
- 实现查询图书功能

### 任务2: list应用 - 借阅队列管理 (10分)

使用list管理图书借阅等待队列。

**要求**:
- 实现借阅请求入队
- 实现处理借阅请求（出队）
- 实现优先级调整（VIP用户提前）
- 实现取消借阅请求

### 任务3: set应用 - 图书分类去重 (10分)

使用set管理图书分类。

**要求**:
- 实现分类添加（自动去重）
- 实现分类删除
- 实现分类查询
- 获取所有分类（有序）

### 任务4: map应用 - ISBN映射 (15分)

使用map实现ISBN到图书的映射。

**要求**:
- 通过ISBN快速查找图书
- 实现图书信息更新
- 统计各分类图书数量
- 实现按价格区间查询

### 任务5: unordered_map应用 - 快速查找 (10分)

使用unordered_map实现书名到ISBN的快速映射。

**要求**:
- 通过书名快速获取ISBN
- 支持模糊查询（包含关键字）
- 统计哈希性能信息

### 任务6: 迭代器使用 (10分)

使用各种迭代器遍历容器。

**要求**:
- 使用正向迭代器遍历
- 使用反向迭代器遍历
- 使用const迭代器遍历
- 结合算法使用迭代器

### 任务7: 算法应用 (15分)

使用STL算法实现各种功能。

**要求**:
- 使用find/find_if查找图书
- 使用count/count_if统计数量
- 使用sort排序图书
- 使用transform转换数据
- 使用accumulate计算总价值

### 任务8: 综合应用 (15分)

整合所有功能，实现完整的图书管理系统。

**要求**:
- 提供菜单界面
- 各功能模块协调工作
- 数据一致性维护
- 异常处理

## 六、评分标准

| 任务 | 分值 | 评分要点 |
|------|------|----------|
| 任务1 | 15分 | vector操作正确，增删改查完整 |
| 任务2 | 10分 | list操作正确，队列逻辑清晰 |
| 任务3 | 10分 | set去重有效，操作正确 |
| 任务4 | 15分 | map映射正确，查询高效 |
| 任务5 | 10分 | unordered_map使用正确 |
| 任务6 | 10分 | 迭代器类型使用正确 |
| 任务7 | 15分 | 算法使用恰当，结果正确 |
| 任务8 | 15分 | 系统完整，运行稳定 |

**总分: 100分**

## 七、注意事项

1. 代码需要有适当的注释
2. 变量命名要有意义
3. 注意迭代器失效问题
4. 合理选择容器类型
5. 注意算法的时间复杂度
6. 处理边界情况和异常

## 八、提交要求

1. 提交源代码文件 `submit.cpp`
2. 代码必须能够编译通过
3. 程序运行结果正确
4. 包含必要的测试代码

## 九、参考资料

1. C++ Reference: https://en.cppreference.com/
2. STL Tutorial: https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
3. 《C++ Primer》第5版，第9-11章
