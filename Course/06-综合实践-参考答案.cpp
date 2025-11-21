// 06-综合实践-参考答案.cpp
// 魔法学院战斗竞技场 - 教师参考答案
// 完整实现版本

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ============================================
// Character 基类
// ============================================
class Character {
protected:
    string name;
    int hp;
    int maxHp;
    int attackPower;
    string school;

public:
    // 构造函数
    Character(string n, int health, int attack, string sch)
        : name(n), hp(health), maxHp(health), attackPower(attack), school(sch) {
    }

    // 纯虚函数 - 子类必须实现
    virtual void attack(Character* target) = 0;

    // 受到伤害
    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
        cout << name << " 受到 " << damage << " 点伤害！";
        if (hp == 0) {
            cout << " (已阵亡)";
        }
        cout << endl;
    }

    // 判断是否存活
    bool isAlive() {
        return hp > 0;
    }

    // 显示状态（生命值进度条）
    void showStatus() {
        cout << "[" << school << "] " << name << " ";

        // 计算进度条
        int filled = (hp * 10) / maxHp;
        cout << "[";
        for (int i = 0; i < 10; i++) {
            if (i < filled) {
                cout << "█";
            } else {
                cout << "░";
            }
        }
        cout << "] " << hp << "/" << maxHp << " HP" << endl;
    }

    // 显示技能信息
    virtual void showSkillInfo() {
        cout << "[" << school << "] " << name << " 的技能信息" << endl;
    }

    // 虚析构函数
    virtual ~Character() {}

    // 辅助方法
    string getName() const { return name; }
    string getSchool() const { return school; }
};

// ============================================
// Warrior 战士类
// ============================================
class Warrior : public Character {
private:
    int rage;  // 怒气值 (0-100)

public:
    Warrior(string name, int hp, int attack)
        : Character(name, hp, attack, "战士"), rage(0) {
    }

    void attack(Character* target) override {
        cout << "\n" << name << " 发起攻击：" << endl;

        if (rage >= 100) {
            // 狂暴打击
            int damage = attackPower * 3;
            cout << "💥 [狂暴打击] 怒气爆发！造成 " << damage << " 点毁灭性伤害！" << endl;
            target->takeDamage(damage);
            rage = 0;  // 清空怒气
        } else {
            // 普通攻击
            cout << "[战士] 挥舞巨剑，造成 " << attackPower << " 点物理伤害！" << endl;
            target->takeDamage(attackPower);
            rage += 20;  // 积累怒气
            if (rage > 100) rage = 100;
        }

        cout << "怒气值: " << rage << "/100" << endl;
    }

    void showSkillInfo() override {
        cout << "【战士技能】" << endl;
        cout << "- 狂暴打击：怒气满100时，下次攻击造成3倍伤害" << endl;
        cout << "- 当前怒气：" << rage << "/100" << endl;
    }
};

// ============================================
// Mage 法师类
// ============================================
class Mage : public Character {
private:
    int mp;     // 当前魔法值
    int maxMp;  // 最大魔法值

public:
    Mage(string name, int hp, int attack)
        : Character(name, hp, attack, "法师"), mp(100), maxMp(100) {
    }

    void attack(Character* target) override {
        cout << "\n" << name << " 发起攻击：" << endl;

        if (mp >= 20) {
            // 火球术
            int damage = attackPower * 1.5;
            cout << "✨ [法师] 释放火球术，造成 " << damage << " 点魔法伤害！" << endl;
            target->takeDamage(damage);
            mp -= 20;
        } else {
            // 魔力耗尽
            int damage = attackPower * 0.5;
            cout << "[法师] 魔力耗尽，用法杖敲击，造成 " << damage << " 点伤害..." << endl;
            target->takeDamage(damage);
        }

        cout << "剩余魔力: " << mp << "/" << maxMp << " MP" << endl;
    }

    void restoreMana() {
        mp += 10;
        if (mp > maxMp) mp = maxMp;
    }

    void showSkillInfo() override {
        cout << "【法师技能】" << endl;
        cout << "- 火球术：消耗20MP，造成1.5倍伤害" << endl;
        cout << "- 当前魔力：" << mp << "/" << maxMp << " MP" << endl;
    }
};

// ============================================
// Archer 游侠类
// ============================================
class Archer : public Character {
private:
    int arrows;  // 箭矢数量

public:
    Archer(string name, int hp, int attack)
        : Character(name, hp, attack, "游侠"), arrows(10) {
    }

    void attack(Character* target) override {
        cout << "\n" << name << " 发起攻击：" << endl;

        if (arrows > 0) {
            arrows--;

            // 30% 几率连射
            if (rand() % 100 < 30) {
                int damage = attackPower * 2;
                cout << "🎯 [连珠箭] 快速连射！造成 " << damage << " 点伤害！" << endl;
                target->takeDamage(damage);
            } else {
                cout << "🏹 [游侠] 精准射击，造成 " << attackPower << " 点伤害！" << endl;
                target->takeDamage(attackPower);
            }

            cout << "剩余箭矢: " << arrows << "/10" << endl;
        } else {
            // 箭矢用尽
            int damage = attackPower * 0.3;
            cout << "[游侠] 箭矢用尽，匕首攻击，造成 " << damage << " 点伤害..." << endl;
            target->takeDamage(damage);
        }
    }

    void showSkillInfo() override {
        cout << "【游侠技能】" << endl;
        cout << "- 精准射击：30%几率连射造成双倍伤害" << endl;
        cout << "- 剩余箭矢：" << arrows << endl;
    }
};

// ============================================
// Assassin 刺客类
// ============================================
class Assassin : public Character {
private:
    int energy;        // 能量值
    bool stealthMode;  // 隐身状态

public:
    Assassin(string name, int hp, int attack)
        : Character(name, hp, attack, "刺客"), energy(50), stealthMode(false) {
    }

    void attack(Character* target) override {
        cout << "\n" << name << " 发起攻击：" << endl;

        if (stealthMode) {
            // 暗影暗杀
            int damage = attackPower * 5;
            cout << "💀 [暗影暗杀] 从阴影中突袭！造成 " << damage << " 点致命伤害！！！" << endl;
            target->takeDamage(damage);
            stealthMode = false;
        } else if (energy >= 30) {
            // 进入隐身
            energy -= 30;
            stealthMode = true;
            cout << "🌑 [潜行] 消失在阴影中...（下次攻击造成5倍伤害）" << endl;
            cout << "剩余能量: " << energy << "/100" << endl;
        } else {
            // 普通攻击，50% 暴击
            if (rand() % 100 < 50) {
                int damage = attackPower * 2;
                cout << "⚡ [暴击] 致命一击！造成 " << damage << " 点伤害！" << endl;
                target->takeDamage(damage);
            } else {
                cout << "🗡️ [刺客] 利刃攻击，造成 " << attackPower << " 点伤害！" << endl;
                target->takeDamage(attackPower);
            }
            cout << "剩余能量: " << energy << "/100" << endl;
        }
    }

    void restoreEnergy() {
        energy += 15;
        if (energy > 100) energy = 100;
    }

    void showSkillInfo() override {
        cout << "【刺客技能】" << endl;
        cout << "- 暗影暗杀：消耗30能量，下次攻击造成5倍伤害" << endl;
        cout << "- 暴击：50%几率造成2倍伤害" << endl;
        cout << "- 当前能量：" << energy << "/100" << endl;
        cout << "- 隐身状态：" << (stealthMode ? "是" : "否") << endl;
    }
};

// ============================================
// Arena 竞技场类
// ============================================
class Arena {
public:
    void battle(Character* fighter1, Character* fighter2) {
        // 显示战斗开始信息
        cout << "\n╔══════════════════════════════╗" << endl;
        cout << "║        战斗开始！             ║" << endl;
        cout << "╠══════════════════════════════╣" << endl;
        cout << "║  " << fighter1->getName() << " VS " << fighter2->getName() << endl;
        cout << "╚══════════════════════════════╝" << endl;

        // 显示双方初始状态
        cout << "\n初始状态：" << endl;
        fighter1->showStatus();
        fighter2->showStatus();

        int round = 1;

        // 回合制战斗循环
        while (fighter1->isAlive() && fighter2->isAlive()) {
            cout << "\n======== 第 " << round << " 回合 ========" << endl;

            // fighter1 攻击 fighter2
            fighter1->attack(fighter2);

            // 显示战况
            cout << "\n--- 战况 ---" << endl;
            fighter1->showStatus();
            fighter2->showStatus();

            // 判断 fighter2 是否存活
            if (!fighter2->isAlive()) {
                break;
            }

            // fighter2 反击
            fighter2->attack(fighter1);

            // 显示战况
            cout << "\n--- 战况 ---" << endl;
            fighter1->showStatus();
            fighter2->showStatus();

            // 判断 fighter1 是否存活
            if (!fighter1->isAlive()) {
                break;
            }

            // 回合结束处理
            // 法师恢复魔力
            Mage* mage1 = dynamic_cast<Mage*>(fighter1);
            if (mage1) {
                mage1->restoreMana();
            }
            Mage* mage2 = dynamic_cast<Mage*>(fighter2);
            if (mage2) {
                mage2->restoreMana();
            }

            // 刺客恢复能量
            Assassin* assassin1 = dynamic_cast<Assassin*>(fighter1);
            if (assassin1) {
                assassin1->restoreEnergy();
            }
            Assassin* assassin2 = dynamic_cast<Assassin*>(fighter2);
            if (assassin2) {
                assassin2->restoreEnergy();
            }

            round++;
        }

        // 显示战斗结果
        cout << "\n╔══════════════════════════════╗" << endl;
        cout << "║        战斗结束！             ║" << endl;
        cout << "╠══════════════════════════════╣" << endl;

        if (fighter1->isAlive()) {
            cout << "║  🏆 胜利者：" << fighter1->getName() << " (" << fighter1->getSchool() << ")" << endl;
        } else {
            cout << "║  🏆 胜利者：" << fighter2->getName() << " (" << fighter2->getSchool() << ")" << endl;
        }

        cout << "║  共进行了 " << round << " 回合" << endl;
        cout << "╚══════════════════════════════╝" << endl;
    }

private:
    void showSeparator() {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    }
};

// ============================================
// 主函数
// ============================================
int main() {
    // 初始化随机数种子
    srand(time(0));

    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║                                               ║" << endl;
    cout << "║      🎮 魔法学院战斗竞技场                    ║" << endl;
    cout << "║      霍格沃兹年度大赛                         ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;

    // 创建角色（使用基类指针，体现多态）
    Character* warrior = new Warrior("勇士阿瑟", 150, 30);
    Character* mage = new Mage("法师梅林", 100, 25);
    Character* archer = new Archer("游侠莱戈拉斯", 120, 28);
    Character* assassin = new Assassin("刺客影", 90, 22);

    // 显示所有角色技能信息
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "        参赛角色介绍" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    warrior->showSkillInfo();
    cout << endl;
    mage->showSkillInfo();
    cout << endl;
    archer->showSkillInfo();
    cout << endl;
    assassin->showSkillInfo();

    // 创建竞技场
    Arena arena;

    // 战斗1：战士 vs 法师
    cout << "\n\n【第一场战斗：力量 vs 魔法】" << endl;
    arena.battle(warrior, mage);

    // 重置战士和法师的生命值（为了演示）
    warrior = new Warrior("勇士阿瑟", 150, 30);
    mage = new Mage("法师梅林", 100, 25);

    // 战斗2：游侠 vs 刺客
    cout << "\n\n【第二场战斗：精准 vs 致命】" << endl;
    arena.battle(archer, assassin);

    // 重置游侠和刺客的生命值
    archer = new Archer("游侠莱戈拉斯", 120, 28);
    assassin = new Assassin("刺客影", 90, 22);

    // 战斗3：战士 vs 游侠
    cout << "\n\n【第三场战斗：近战 vs 远程】" << endl;
    arena.battle(warrior, archer);

    // 战斗4：法师 vs 刺客
    cout << "\n\n【第四场战斗：魔法 vs 暗影】" << endl;
    arena.battle(mage, assassin);

    // 多态演示：使用数组统一管理
    cout << "\n\n【终极挑战：混战模式】" << endl;
    cout << "让我们看看四种职业的实力对比！" << endl;

    Character* fighters[4];
    fighters[0] = new Warrior("战神", 150, 30);
    fighters[1] = new Mage("大法师", 100, 25);
    fighters[2] = new Archer("神射手", 120, 28);
    fighters[3] = new Assassin("暗杀者", 90, 22);

    cout << "\n所有参赛者：" << endl;
    for (int i = 0; i < 4; i++) {
        fighters[i]->showStatus();
    }

    // 释放内存
    delete warrior;
    delete mage;
    delete archer;
    delete assassin;

    for (int i = 0; i < 4; i++) {
        delete fighters[i];
    }

    cout << "\n\n╔═══════════════════════════════════════════════╗" << endl;
    cout << "║                                               ║" << endl;
    cout << "║           竞技大赛圆满结束！                   ║" << endl;
    cout << "║           感谢观看！                          ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;

    return 0;
}

/*
 * ============================================
 * 知识点覆盖说明
 * ============================================
 *
 * ✅ 继承：
 *    - Character 基类
 *    - Warrior, Mage, Archer, Assassin 派生类
 *    - 使用 : public Character 继承语法
 *
 * ✅ 多态：
 *    - virtual void attack() = 0 纯虚函数
 *    - 各子类重写 attack() 方法
 *    - Arena::battle() 使用基类指针调用
 *
 * ✅ 虚函数：
 *    - virtual void attack()
 *    - virtual void showSkillInfo()
 *    - virtual ~Character()
 *
 * ✅ 方法重写：
 *    - 使用 override 关键字
 *    - 每个角色有独特的攻击方式
 *
 * ✅ 访问控制：
 *    - protected 成员：name, hp, attackPower 等
 *    - private 成员：rage, mp, arrows, energy
 *    - public 方法：attack(), showStatus() 等
 *
 * ✅ 构造函数继承：
 *    - 使用 : Character(name, hp, attack, school)
 *    - 初始化列表语法
 *
 * ✅ 动态类型转换：
 *    - dynamic_cast<Mage*>(fighter)
 *    - 用于回合结束的魔力恢复
 *
 * ✅ 内存管理：
 *    - new/delete 配对使用
 *    - 虚析构函数确保正确释放
 *
 * ============================================
 * 编译和运行
 * ============================================
 *
 * g++ -std=c++11 06-综合实践-参考答案.cpp -o battle
 * ./battle
 *
 * ============================================
 * 示例输出
 * ============================================
 *
 * ╔═══════════════════════════════════════════════╗
 * ║      🎮 魔法学院战斗竞技场                    ║
 * ║      霍格沃兹年度大赛                         ║
 * ╚═══════════════════════════════════════════════╝
 *
 * 【第一场战斗：力量 vs 魔法】
 *
 * ╔══════════════════════════════╗
 * ║        战斗开始！             ║
 * ╠══════════════════════════════╣
 * ║  勇士阿瑟 VS 法师梅林
 * ╚══════════════════════════════╝
 *
 * 初始状态：
 * [战士] 勇士阿瑟 [██████████] 150/150 HP
 * [法师] 法师梅林 [██████████] 100/100 HP
 *
 * ======== 第 1 回合 ========
 *
 * 勇士阿瑟 发起攻击：
 * [战士] 挥舞巨剑，造成 30 点物理伤害！
 * 法师梅林 受到 30 点伤害！
 * 怒气值: 20/100
 *
 * --- 战况 ---
 * [战士] 勇士阿瑟 [██████████] 150/150 HP
 * [法师] 法师梅林 [███████░░░] 70/100 HP
 *
 * 法师梅林 发起攻击：
 * ✨ [法师] 释放火球术，造成 37 点魔法伤害！
 * 勇士阿瑟 受到 37 点伤害！
 * 剩余魔力: 80/100 MP
 *
 * ... (战斗继续) ...
 *
 * ╔══════════════════════════════╗
 * ║        战斗结束！             ║
 * ╠══════════════════════════════╣
 * ║  🏆 胜利者：勇士阿瑟 (战士)
 * ║  共进行了 5 回合
 * ╚══════════════════════════════╝
 *
 * ============================================
 * 教学要点提示
 * ============================================
 *
 * 1. 多态的体现：
 *    - Arena::battle() 接受 Character* 指针
 *    - 实际调用时会根据对象类型调用正确的方法
 *    - 这就是"一个接口，多种实现"
 *
 * 2. 继承的优势：
 *    - 公共属性和方法在基类定义
 *    - 子类只需关注自己的特色功能
 *    - 代码复用，易于维护
 *
 * 3. 虚函数的作用：
 *    - 没有 virtual 关键字就无法实现多态
 *    - 纯虚函数强制子类必须实现
 *    - 虚析构函数确保正确释放内存
 *
 * 4. 设计模式：
 *    - 策略模式：不同角色有不同的攻击策略
 *    - 模板方法：battle() 定义战斗流程框架
 *
 * 5. 扩展性：
 *    - 新增职业只需继承 Character 并实现 attack()
 *    - 无需修改 Arena 类
 *    - 符合开闭原则
 */
