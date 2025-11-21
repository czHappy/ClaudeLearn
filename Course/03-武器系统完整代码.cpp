// 03-武器系统完整代码.cpp
// RPG 游戏武器系统 - 完整实现
// 展示继承和多态在实际项目中的应用

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// ============================================
// 武器基类 - Weapon
// ============================================
class Weapon {
protected:
    string name;        // 武器名称
    int damage;         // 基础伤害
    int level;          // 武器等级
    string rarity;      // 稀有度
    int price;          // 价格

public:
    // 构造函数
    Weapon(string n, int dmg, string r, int p)
        : name(n), damage(dmg), level(1), rarity(r), price(p) {}

    // 纯虚函数：攻击方法（子类必须实现）
    virtual void attack() = 0;

    // 虚函数：特殊技能（子类可以重写）
    virtual void specialSkill() {
        cout << "⚠️  " << name << " 没有特殊技能" << endl;
    }

    // 显示武器信息
    void showInfo() {
        cout << "\n╔════════════════════════════════╗" << endl;
        cout << "║       " << rarity << " 武器          ║" << endl;
        cout << "╠════════════════════════════════╣" << endl;
        cout << "║ 名称: " << name << endl;
        cout << "║ 伤害: " << damage << endl;
        cout << "║ 等级: Lv." << level << endl;
        cout << "║ 价格: " << price << " 金币" << endl;
        cout << "╚════════════════════════════════╝" << endl;
    }

    // 武器升级
    void upgrade() {
        level++;
        damage = static_cast<int>(damage * 1.2);  // 伤害提升20%
        price = static_cast<int>(price * 1.5);    // 价格提升50%

        cout << "\n✨ ════════ 强化成功！ ════════" << endl;
        cout << "  " << name << " → Lv." << level << endl;
        cout << "  攻击力: " << damage << " (+20%)" << endl;
        cout << "  价值: " << price << " 金币" << endl;
        cout << "═════════════════════════════════" << endl;
    }

    // 武器修理
    void repair() {
        cout << "🔧 " << name << " 已修理完毕！" << endl;
    }

    // 获取武器信息
    string getName() const { return name; }
    int getDamage() const { return damage; }
    int getLevel() const { return level; }
    int getPrice() const { return price; }

    // 虚析构函数（非常重要！）
    virtual ~Weapon() {
        // cout << "销毁武器: " << name << endl;
    }
};

// ============================================
// 剑类 - Sword
// ============================================
class Sword : public Weapon {
private:
    double criticalChance;  // 暴击几率

public:
    Sword(string n, int dmg, int p)
        : Weapon(n, dmg, "⚔️  近战", p), criticalChance(0.25) {}

    // 重写攻击方法
    void attack() override {
        cout << "\n⚔️  [剑技·破空斩]" << endl;

        // 随机判断是否暴击
        int random = rand() % 100;
        if (random < criticalChance * 100) {
            int critDamage = damage * 2;
            cout << "💥 暴击！挥动" << name << "斩出凌厉剑气！" << endl;
            cout << "   造成 " << critDamage << " 点暴击伤害！" << endl;
        } else {
            cout << "   挥动" << name << "劈向敌人！" << endl;
            cout << "   造成 " << damage << " 点斩击伤害！" << endl;
        }
    }

    // 重写特殊技能
    void specialSkill() override {
        cout << "\n🌟 ═════ [奥义·天翔龙闪] ═════" << endl;
        cout << "   " << name << "剑身泛起龙形剑气！" << endl;
        cout << "   一击必杀，造成 " << damage * 3 << " 点真实伤害！" << endl;
        cout << "═════════════════════════════════" << endl;
    }

    void setCriticalChance(double chance) {
        criticalChance = chance;
    }
};

// ============================================
// 弓类 - Bow
// ============================================
class Bow : public Weapon {
private:
    int arrows;          // 箭矢数量
    int maxArrows;       // 最大箭矢

public:
    Bow(string n, int dmg, int p)
        : Weapon(n, dmg, "🏹 远程", p), arrows(20), maxArrows(20) {}

    void attack() override {
        if (arrows > 0) {
            cout << "\n🏹 [精准射击]" << endl;
            cout << "   拉满" << name << "，箭矢破空而出！" << endl;
            cout << "   造成 " << damage << " 点穿刺伤害！" << endl;
            arrows--;
            cout << "   剩余箭矢: " << arrows << "/" << maxArrows << endl;

            // 低箭矢警告
            if (arrows <= 5 && arrows > 0) {
                cout << "   ⚠️  箭矢不足！" << endl;
            }
        } else {
            cout << "\n❌ 箭矢耗尽！" << endl;
            cout << "   只能使用匕首攻击，造成 " << damage / 3 << " 点伤害..." << endl;
        }
    }

    void specialSkill() override {
        cout << "\n🌟 ═════ [箭雨风暴] ═════" << endl;
        cout << "   " << name << "万箭齐发！" << endl;
        cout << "   天空降下箭雨，造成 " << damage * 2 << " 点范围伤害！" << endl;
        cout << "═════════════════════════════════" << endl;

        // 技能后补满箭矢
        arrows = maxArrows;
        cout << "   箭矢已补满！(" << arrows << "/" << maxArrows << ")" << endl;
    }

    void reloadArrows() {
        arrows = maxArrows;
        cout << "🎯 箭矢已补充！(" << arrows << "/" << maxArrows << ")" << endl;
    }

    int getArrows() const { return arrows; }
};

// ============================================
// 魔杖类 - Staff
// ============================================
class Staff : public Weapon {
private:
    int mana;           // 当前魔力
    int maxMana;        // 最大魔力
    string element;     // 元素类型

public:
    Staff(string n, int dmg, int p, string elem)
        : Weapon(n, dmg, "✨ 魔法", p), mana(100), maxMana(100), element(elem) {}

    void attack() override {
        const int manaCost = 25;

        if (mana >= manaCost) {
            cout << "\n✨ [元素冲击·" << element << "]" << endl;
            cout << "   " << name << "凝聚" << element << "之力！" << endl;
            cout << "   释放魔法冲击，造成 " << damage << " 点魔法伤害！" << endl;
            mana -= manaCost;
            cout << "   剩余魔力: " << mana << "/" << maxMana << " MP" << endl;
        } else {
            cout << "\n😵 魔力不足！" << endl;
            cout << "   用" << name << "敲击敌人..." << endl;
            cout << "   造成 " << damage / 3 << " 点物理伤害" << endl;

            // 恢复少量魔力
            mana += 10;
            if (mana > maxMana) mana = maxMana;
            cout << "   恢复魔力: " << mana << "/" << maxMana << " MP" << endl;
        }
    }

    void specialSkill() override {
        cout << "\n🌈 ═════ [禁咒·" << element << "天罚] ═════" << endl;
        cout << "   召唤远古" << element << "魔法！" << endl;
        cout << "   天地变色，造成 " << damage * 4 << " 点毁灭性伤害！" << endl;
        cout << "═════════════════════════════════" << endl;

        // 大招后魔力全满
        mana = maxMana;
        cout << "   魔力全部恢复！(" << mana << "/" << maxMana << " MP)" << endl;
    }

    void meditate() {
        mana = maxMana;
        cout << "🧘 冥想恢复魔力... 魔力全满！(" << mana << "/" << maxMana << " MP)" << endl;
    }

    int getMana() const { return mana; }
};

// ============================================
// 角色类 - Character
// ============================================
class Character {
private:
    string name;
    int hp;
    int maxHp;
    Weapon* equippedWeapon;  // 装备的武器（多态指针）
    vector<Weapon*> inventory;  // 武器库存
    int gold;

public:
    Character(string n) : name(n), hp(100), maxHp(100), equippedWeapon(nullptr), gold(1000) {}

    // 装备武器
    void equipWeapon(Weapon* weapon) {
        equippedWeapon = weapon;
        cout << "\n✅ " << name << " 装备了 " << weapon->getName() << "！" << endl;
    }

    // 卸下武器
    void unequipWeapon() {
        if (equippedWeapon) {
            cout << "📦 " << name << " 卸下了 " << equippedWeapon->getName() << endl;
            equippedWeapon = nullptr;
        }
    }

    // 添加武器到背包
    void addWeapon(Weapon* weapon) {
        inventory.push_back(weapon);
        cout << "📦 获得新武器: " << weapon->getName() << endl;
    }

    // 显示背包
    void showInventory() {
        cout << "\n╔════════════════════════════════╗" << endl;
        cout << "║         " << name << " 的背包          ║" << endl;
        cout << "╠════════════════════════════════╣" << endl;
        cout << "║ 金币: " << gold << " 枚" << endl;

        if (inventory.empty()) {
            cout << "║ 背包是空的..." << endl;
        } else {
            cout << "║ 武器数量: " << inventory.size() << endl;
            cout << "╠════════════════════════════════╣" << endl;
            for (size_t i = 0; i < inventory.size(); i++) {
                cout << "║ " << (i + 1) << ". " << inventory[i]->getName()
                     << " (Lv." << inventory[i]->getLevel() << ")" << endl;
            }
        }
        cout << "╚════════════════════════════════╝" << endl;
    }

    // 攻击
    void attack() {
        cout << "\n⚔️  " << name << " 发起攻击！" << endl;

        if (equippedWeapon) {
            equippedWeapon->attack();  // 多态调用
        } else {
            cout << "👊 手无寸铁，使用拳头攻击！" << endl;
            cout << "   造成 5 点伤害" << endl;
        }
    }

    // 使用技能
    void useSkill() {
        if (equippedWeapon) {
            cout << "\n🌟 " << name << " 释放特殊技能！" << endl;
            equippedWeapon->specialSkill();  // 多态调用
        } else {
            cout << "❌ 没有装备武器，无法使用技能！" << endl;
        }
    }

    // 升级武器
    void upgradeWeapon() {
        if (equippedWeapon) {
            int cost = equippedWeapon->getPrice() / 2;
            if (gold >= cost) {
                gold -= cost;
                equippedWeapon->upgrade();
                cout << "💰 花费 " << cost << " 金币，剩余 " << gold << " 金币" << endl;
            } else {
                cout << "❌ 金币不足！需要 " << cost << " 金币" << endl;
            }
        } else {
            cout << "❌ 没有装备武器！" << endl;
        }
    }

    // 显示角色状态
    void showStatus() {
        cout << "\n╔════════════════════════════════╗" << endl;
        cout << "║        " << name << " 的状态           ║" << endl;
        cout << "╠════════════════════════════════╣" << endl;
        cout << "║ HP: " << hp << "/" << maxHp << endl;
        cout << "║ 金币: " << gold << " 枚" << endl;

        if (equippedWeapon) {
            cout << "║ 武器: " << equippedWeapon->getName()
                 << " (Lv." << equippedWeapon->getLevel() << ")" << endl;
            cout << "║ 攻击力: " << equippedWeapon->getDamage() << endl;
        } else {
            cout << "║ 武器: 未装备" << endl;
        }
        cout << "╚════════════════════════════════╝" << endl;
    }

    ~Character() {
        // 清理背包中的武器
        for (auto weapon : inventory) {
            delete weapon;
        }
    }
};

// ============================================
// 武器商店类 - WeaponShop
// ============================================
class WeaponShop {
private:
    vector<Weapon*> shopInventory;

public:
    WeaponShop() {
        // 初始化商店库存
        shopInventory.push_back(new Sword("新手剑", 30, 100));
        shopInventory.push_back(new Bow("猎人弓", 25, 80));
        shopInventory.push_back(new Staff("学徒法杖", 28, 90, "火焰"));
        shopInventory.push_back(new Sword("精钢大剑", 60, 300));
        shopInventory.push_back(new Bow("银月弓", 55, 280));
        shopInventory.push_back(new Staff("贤者之杖", 65, 350, "冰霜"));
    }

    void showShop() {
        cout << "\n╔════════════════════════════════════════╗" << endl;
        cout << "║        🏪 欢迎光临武器商店！           ║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;

        for (size_t i = 0; i < shopInventory.size(); i++) {
            Weapon* w = shopInventory[i];
            cout << "║ " << (i + 1) << ". " << w->getName()
                 << " - " << w->getPrice() << " 金币"
                 << " (伤害: " << w->getDamage() << ")" << endl;
        }

        cout << "╚════════════════════════════════════════╝" << endl;
    }

    ~WeaponShop() {
        for (auto weapon : shopInventory) {
            delete weapon;
        }
    }
};

// ============================================
// 游戏演示系统
// ============================================
class GameDemo {
public:
    // 武器展示
    static void weaponShowcase() {
        cout << "\n╔═══════════════════════════════════════╗" << endl;
        cout << "║     🎮 武器系统展示 - 继承与多态      ║" << endl;
        cout << "╚═══════════════════════════════════════╝" << endl;

        // 创建各种武器
        Sword* sword = new Sword("霜之哀伤", 120, 500);
        Bow* bow = new Bow("风之追忆", 90, 400);
        Staff* staff = new Staff("贤者之杖", 110, 450, "雷电");

        // 展示武器信息
        sword->showInfo();
        bow->showInfo();
        staff->showInfo();

        cout << "\n--- 武器攻击演示 ---" << endl;
        sword->attack();
        bow->attack();
        staff->attack();

        cout << "\n--- 特殊技能演示 ---" << endl;
        sword->specialSkill();
        bow->specialSkill();
        staff->specialSkill();

        delete sword;
        delete bow;
        delete staff;
    }

    // 战斗演示
    static void battleDemo() {
        cout << "\n╔═══════════════════════════════════════╗" << endl;
        cout << "║          ⚔️  战斗演示              ║" << endl;
        cout << "╚═══════════════════════════════════════╝" << endl;

        Character hero("亚瑟王");

        // 创建武器
        Sword* excalibur = new Sword("誓约胜利之剑", 150, 1000);
        Bow* sunBow = new Bow("太阳神之弓", 100, 800);

        hero.showStatus();

        // 第一回合：使用剑
        cout << "\n━━━━━━━━ 第1回合 ━━━━━━━━" << endl;
        hero.equipWeapon(excalibur);
        hero.attack();

        // 第二回合：使用弓
        cout << "\n━━━━━━━━ 第2回合 ━━━━━━━━" << endl;
        hero.equipWeapon(sunBow);
        hero.attack();

        // 第三回合：使用技能
        cout << "\n━━━━━━━━ 第3回合 ━━━━━━━━" << endl;
        hero.equipWeapon(excalibur);
        hero.useSkill();

        delete excalibur;
        delete sunBow;
    }

    // 多态演示
    static void polymorphismDemo() {
        cout << "\n╔═══════════════════════════════════════╗" << endl;
        cout << "║          🌟 多态特性演示              ║" << endl;
        cout << "╚═══════════════════════════════════════╝" << endl;

        // 使用父类指针数组
        Weapon* arsenal[5];
        arsenal[0] = new Sword("屠龙刀", 80, 300);
        arsenal[1] = new Bow("连弩", 60, 250);
        arsenal[2] = new Staff("元素法杖", 70, 280, "风");
        arsenal[3] = new Sword("青釭剑", 85, 320);
        arsenal[4] = new Bow("破魔弓", 65, 270);

        cout << "\n🎯 统一调用 attack() 方法：" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        for (int i = 0; i < 5; i++) {
            cout << "\n武器 " << (i + 1) << ": " << arsenal[i]->getName() << endl;
            arsenal[i]->attack();  // 多态！自动调用正确的方法
        }

        // 清理内存
        for (int i = 0; i < 5; i++) {
            delete arsenal[i];
        }
    }

    // 升级系统演示
    static void upgradeDemo() {
        cout << "\n╔═══════════════════════════════════════╗" << endl;
        cout << "║          ⬆️  武器升级演示              ║" << endl;
        cout << "╚═══════════════════════════════════════╝" << endl;

        Sword* sword = new Sword("铁剑", 50, 200);

        sword->showInfo();

        for (int i = 1; i <= 3; i++) {
            cout << "\n--- 第 " << i << " 次强化 ---" << endl;
            sword->upgrade();
        }

        sword->showInfo();
        sword->attack();

        delete sword;
    }
};

// ============================================
// 主函数
// ============================================
int main() {
    srand(time(0));  // 初始化随机数种子

    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║                                               ║" << endl;
    cout << "║      🎮 RPG 武器系统 - 完整演示               ║" << endl;
    cout << "║      展示继承和多态的实际应用                 ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;

    int choice;
    do {
        cout << "\n\n╔════════════════════════════╗" << endl;
        cout << "║        主菜单              ║" << endl;
        cout << "╠════════════════════════════╣" << endl;
        cout << "║ 1. 武器展示                ║" << endl;
        cout << "║ 2. 战斗演示                ║" << endl;
        cout << "║ 3. 多态特性演示            ║" << endl;
        cout << "║ 4. 武器升级演示            ║" << endl;
        cout << "║ 5. 商店系统演示            ║" << endl;
        cout << "║ 0. 退出程序                ║" << endl;
        cout << "╚════════════════════════════╝" << endl;
        cout << "请选择 (0-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                GameDemo::weaponShowcase();
                break;
            case 2:
                GameDemo::battleDemo();
                break;
            case 3:
                GameDemo::polymorphismDemo();
                break;
            case 4:
                GameDemo::upgradeDemo();
                break;
            case 5: {
                WeaponShop shop;
                shop.showShop();
                break;
            }
            case 0:
                cout << "\n👋 感谢使用！再见！" << endl;
                break;
            default:
                cout << "\n❌ 无效选择，请重试！" << endl;
        }

    } while (choice != 0);

    return 0;
}

/*
 * 编译和运行：
 * g++ -std=c++11 03-武器系统完整代码.cpp -o weapon_system
 * ./weapon_system
 *
 * 本程序展示了：
 * 1. 继承：Sword、Bow、Staff 继承自 Weapon
 * 2. 多态：通过基类指针调用不同子类的方法
 * 3. 虚函数：attack() 和 specialSkill()
 * 4. 纯虚函数：Weapon 作为抽象类
 * 5. 虚析构函数：正确释放内存
 * 6. 方法重写：子类实现各自的攻击方式
 * 7. 访问控制：protected 和 public
 */