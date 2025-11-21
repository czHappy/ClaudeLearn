// 02-代码示例.cpp
// 继承和多态 - 所有代码示例汇总
// 可以直接编译运行的完整代码

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ============================================
// 示例 1：简单继承
// ============================================
namespace Example1 {
    class Animal {
    protected:
        string name;

    public:
        Animal(string n) : name(n) {}

        void eat() {
            cout << name << " 正在吃东西" << endl;
        }

        void sleep() {
            cout << name << " 正在睡觉 Zzz..." << endl;
        }
    };

    class Dog : public Animal {
    public:
        Dog(string n) : Animal(n) {}
    };

    void demo() {
        cout << "\n========== 示例1：简单继承 ==========" << endl;
        Dog myDog("旺财");
        myDog.eat();
        myDog.sleep();
    }
}

// ============================================
// 示例 2：子类扩展新功能
// ============================================
namespace Example2 {
    class Animal {
    protected:
        string name;

    public:
        Animal(string n) : name(n) {}

        void eat() {
            cout << name << " 正在吃东西" << endl;
        }
    };

    class Dog : public Animal {
    public:
        Dog(string n) : Animal(n) {}

        void bark() {
            cout << name << " 汪汪叫！🐕" << endl;
        }

        void wagTail() {
            cout << name << " 摇着尾巴~" << endl;
        }
    };

    void demo() {
        cout << "\n========== 示例2：子类扩展 ==========" << endl;
        Dog myDog("旺财");
        myDog.eat();
        myDog.bark();
        myDog.wagTail();
    }
}

// ============================================
// 示例 3：方法重写
// ============================================
namespace Example3 {
    class Animal {
    protected:
        string name;

    public:
        Animal(string n) : name(n) {}

        void eat() {
            cout << name << " 正在吃东西" << endl;
        }
    };

    class Cat : public Animal {
    public:
        Cat(string n) : Animal(n) {}

        void eat() {  // 重写父类方法
            cout << name << " 优雅地吃着猫粮 🐱" << endl;
            cout << "（猫咪吃东西就是与众不同）" << endl;
        }
    };

    void demo() {
        cout << "\n========== 示例3：方法重写 ==========" << endl;
        Animal animal("普通动物");
        Cat cat("咪咪");

        animal.eat();
        cat.eat();
    }
}

// ============================================
// 示例 4：调用父类方法
// ============================================
namespace Example4 {
    class Animal {
    protected:
        string name;

    public:
        Animal(string n) : name(n) {}

        void eat() {
            cout << name << " 正在吃东西" << endl;
        }
    };

    class Bird : public Animal {
    private:
        bool canFly;

    public:
        Bird(string n, bool fly) : Animal(n), canFly(fly) {}

        void eat() {
            Animal::eat();  // 调用父类方法
            cout << "吃完后，" << name << " 整理了一下羽毛 🪶" << endl;

            if (canFly) {
                cout << name << " 准备起飞！" << endl;
            }
        }
    };

    void demo() {
        cout << "\n========== 示例4：调用父类方法 ==========" << endl;
        Bird sparrow("小麻雀", true);
        sparrow.eat();
    }
}

// ============================================
// 示例 5：多态基础
// ============================================
namespace Example5 {
    class Animal {
    public:
        virtual void speak() {  // 虚函数
            cout << "动物发出声音" << endl;
        }

        virtual ~Animal() {}  // 虚析构函数
    };

    class Dog : public Animal {
    public:
        void speak() override {
            cout << "🐕 汪汪汪！" << endl;
        }
    };

    class Cat : public Animal {
    public:
        void speak() override {
            cout << "🐱 喵喵喵~" << endl;
        }
    };

    class Duck : public Animal {
    public:
        void speak() override {
            cout << "🦆 嘎嘎嘎！" << endl;
        }
    };

    void makeSound(Animal* animal) {
        animal->speak();  // 多态调用
    }

    void demo() {
        cout << "\n========== 示例5：多态基础 ==========" << endl;
        cout << "动物音乐会开始啦！" << endl;
        cout << "-------------------" << endl;

        Dog dog;
        Cat cat;
        Duck duck;

        makeSound(&dog);
        makeSound(&cat);
        makeSound(&duck);
    }
}

// ============================================
// 示例 6：多态与数组
// ============================================
namespace Example6 {
    using namespace Example5;  // 重用上面的类定义

    void demo() {
        cout << "\n========== 示例6：多态与数组 ==========" << endl;
        cout << "🎪 欢迎来到动物园！" << endl;
        cout << "动物们要开始表演了：" << endl;
        cout << "=====================" << endl;

        Animal* zoo[5];
        zoo[0] = new Dog();
        zoo[1] = new Cat();
        zoo[2] = new Duck();
        zoo[3] = new Dog();
        zoo[4] = new Cat();

        for(int i = 0; i < 5; i++) {
            cout << "动物 " << (i+1) << ": ";
            zoo[i]->speak();
        }

        // 清理内存
        for(int i = 0; i < 5; i++) {
            delete zoo[i];
        }
    }
}

// ============================================
// 示例 7：纯虚函数与抽象类
// ============================================
namespace Example7 {
    class Shape {  // 抽象类
    public:
        virtual double getArea() = 0;  // 纯虚函数
        virtual void draw() = 0;
        virtual ~Shape() {}
    };

    class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        double getArea() override {
            return 3.14159 * radius * radius;
        }

        void draw() override {
            cout << "○ 画了一个半径为 " << radius << " 的圆" << endl;
        }
    };

    class Rectangle : public Shape {
    private:
        double width, height;

    public:
        Rectangle(double w, double h) : width(w), height(h) {}

        double getArea() override {
            return width * height;
        }

        void draw() override {
            cout << "□ 画了一个 " << width << "x" << height << " 的矩形" << endl;
        }
    };

    void processShape(Shape* shape) {
        shape->draw();
        cout << "   面积：" << shape->getArea() << endl;
    }

    void demo() {
        cout << "\n========== 示例7：纯虚函数 ==========" << endl;
        Circle circle(5);
        Rectangle rect(4, 6);

        processShape(&circle);
        processShape(&rect);
    }
}

// ============================================
// 示例 8：武器系统（继承重构版）
// ============================================
namespace Example8 {
    class Weapon {
    protected:
        string name;
        int damage;
        int level;

    public:
        Weapon(string n, int dmg) : name(n), damage(dmg), level(1) {}

        void showInfo() {
            cout << "========== 武器信息 ==========" << endl;
            cout << "名称：" << name << endl;
            cout << "伤害：" << damage << endl;
            cout << "等级：" << level << endl;
            cout << "==============================" << endl;
        }

        void upgrade() {
            level++;
            damage += 10;
            cout << "✨ " << name << " 升级成功！" << endl;
            cout << "等级：" << level << " | 伤害：" << damage << endl;
        }

        virtual void attack() {
            cout << "使用 " << name << " 进行攻击！" << endl;
        }

        virtual ~Weapon() {}
    };

    class Sword : public Weapon {
    public:
        Sword(string n, int dmg) : Weapon(n, dmg) {}

        void attack() override {
            cout << "⚔️ 挥动" << name << "横扫千军！造成 " << damage << " 点斩击伤害！" << endl;
        }
    };

    class Bow : public Weapon {
    public:
        Bow(string n, int dmg) : Weapon(n, dmg) {}

        void attack() override {
            cout << "🏹 拉满" << name << "一箭穿心！造成 " << damage << " 点穿刺伤害！" << endl;
        }
    };

    class Staff : public Weapon {
    public:
        Staff(string n, int dmg) : Weapon(n, dmg) {}

        void attack() override {
            cout << "🔮 " << name << "魔力涌动！造成 " << damage << " 点魔法伤害！" << endl;
        }
    };

    void demo() {
        cout << "\n========== 示例8：武器系统 ==========" << endl;

        Sword sword("霜之哀伤", 100);
        Bow bow("精灵之弓", 80);
        Staff staff("大法师之杖", 90);

        // 展示武器信息
        sword.showInfo();

        // 不同武器的攻击
        cout << "\n--- 武器攻击展示 ---" << endl;
        sword.attack();
        bow.attack();
        staff.attack();

        // 升级武器
        cout << "\n--- 武器升级 ---" << endl;
        sword.upgrade();
        sword.attack();
    }
}

// ============================================
// 示例 9：角色装备系统（多态应用）
// ============================================
namespace Example9 {
    using namespace Example8;  // 使用武器类

    class Character {
    private:
        string name;
        Weapon* weapon;

    public:
        Character(string n) : name(n), weapon(nullptr) {}

        void equipWeapon(Weapon* w) {
            weapon = w;
            cout << name << " 装备了武器！" << endl;
        }

        void attack() {
            cout << "\n" << name << " 发起攻击：" << endl;
            if (weapon) {
                weapon->attack();  // 多态调用
            } else {
                cout << name << " 手无寸铁，使用拳头攻击！" << endl;
            }
        }
    };

    void demo() {
        cout << "\n========== 示例9：角色装备系统 ==========" << endl;

        Character hero("勇者");

        Sword excalibur("王者之剑", 120);
        Bow windBow("疾风之弓", 90);
        Staff arcaneStaff("奥术法杖", 100);

        // 测试不同武器
        hero.attack();  // 无武器

        hero.equipWeapon(&excalibur);
        hero.attack();

        hero.equipWeapon(&windBow);
        hero.attack();

        hero.equipWeapon(&arcaneStaff);
        hero.attack();
    }
}

// ============================================
// 主函数 - 运行所有示例
// ============================================
int main() {
    cout << "╔═══════════════════════════════════════╗" << endl;
    cout << "║     继承和多态 - 代码示例演示          ║" << endl;
    cout << "╚═══════════════════════════════════════╝" << endl;

    // 继承示例
    cout << "\n\n【第一部分：继承】" << endl;
    Example1::demo();
    Example2::demo();
    Example3::demo();
    Example4::demo();

    // 多态示例
    cout << "\n\n【第二部分：多态】" << endl;
    Example5::demo();
    Example6::demo();
    Example7::demo();

    // 综合应用
    cout << "\n\n【第三部分：综合应用】" << endl;
    Example8::demo();
    Example9::demo();

    cout << "\n\n╔═══════════════════════════════════════╗" << endl;
    cout << "║           演示结束，感谢观看！           ║" << endl;
    cout << "╚═══════════════════════════════════════╝" << endl;

    return 0;
}

// 编译命令：
// g++ -std=c++11 02-代码示例.cpp -o examples
// ./examples