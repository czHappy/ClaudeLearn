#include <iostream>
using std::cout;
using std::endl;

// ==================== 全局变量定义 ====================
// 演示: 全局作用域
bool gameRunning = true;
const int MAX_FPS = 60;

// 用于演示全局变量被遮蔽后的访问
int playerId = 1001;  // 全局玩家ID

// ==================== Graphics 命名空间 ====================
// 演示: namespace 定义与使用
namespace Graphics {
    // 命名空间内的变量
    double version = 1.0;

    // 初始化函数
    void initialize() {
        cout << "[Graphics] 图形模块初始化完成" << endl;
    }

    // 更新函数
    void update() {
        cout << "  [Graphics] 渲染场景..." << endl;
    }

    // 渲染函数
    void render() {
        cout << "  渲染中..." << endl;
    }
}

// ==================== Audio 命名空间 ====================
namespace Audio {
    double version = 2.0;

    void initialize() {
        cout << "[Audio] 音频模块初始化完成" << endl;
    }

    void update() {
        cout << "  [Audio] 播放背景音乐" << endl;
    }

    void playSound() {
        cout << "  播放音效..." << endl;
    }
}

// ==================== Physics 命名空间 ====================
namespace Physics {
    double version = 1.5;
    const double gravity = 9.8;

    void initialize() {
        cout << "[Physics] 物理模块初始化完成" << endl;
    }

    void update() {
        cout << "  [Physics] 物理模拟: 重力 = " << gravity << endl;
    }

    void simulate() {
        cout << "  模拟物理运动..." << endl;
    }
}

// ==================== 帧计数函数 ====================
// 演示: 静态局部变量(static)
int getFrameCount() {
    static int frameCount = 0;  // 静态局部变量，只初始化一次
    frameCount++;
    return frameCount;
}

// ==================== 作用域演示函数 ====================
// 演示: 块作用域与变量生命周期、作用域就近原则、作用域解析运算符(::)
void demonstrateScope() {
    // 局部变量，遮蔽全局变量
    int playerId = 1001;  // 局部作用域
    cout << "外层作用域: 玩家ID = " << playerId << endl;

    {   // 内层块作用域
        int playerId = 2002;  // 块作用域，遮蔽外层局部变量
        cout << "  内层作用域: 玩家ID = " << playerId << " (局部变量遮蔽)" << endl;
        // 使用作用域解析运算符访问全局变量
        cout << "  使用全局作用域: 玩家ID = " << ::playerId << endl;
    }   // 内层变量 playerId 在此处销毁

    // 返回外层作用域
    cout << "返回外层作用域: 玩家ID = " << playerId << endl;
}

// ==================== 静态变量演示函数 ====================
// 演示: 静态局部变量在多次调用间保持值
void demonstrateStatic() {
    static int callCount = 0;  // 静态局部变量
    callCount++;
    cout << "调用统计: 第 " << callCount << " 次" << endl;
}

// ==================== using 声明演示 ====================
// 演示: using 声明与 using 指令
void demonstrateUsing() {
    // using 声明: 引入特定成员
    using Graphics::render;
    render();  // 可以直接调用，无需加命名空间前缀

    // 在局部作用域中使用 using 指令
    {
        using namespace Physics;
        simulate();  // 可以直接调用 Physics 中的函数
        // 注意: 这只在这个块作用域内有效
    }
}

// ==================== 主函数 ====================
int main() {
    cout << "=== 游戏系统启动 ===" << endl;

    // 演示: 访问全局变量
    cout << "最大FPS: " << MAX_FPS << endl;
    cout << "游戏状态: " << (gameRunning ? "运行中" : "已停止") << endl;

    cout << "\n--- 初始化各模块 ---" << endl;
    // 演示: 作用域解析运算符(::)
    Graphics::initialize();
    Audio::initialize();
    Physics::initialize();

    cout << "\n--- 游戏主循环 (3帧演示) ---" << endl;
    // 演示: 块作用域与变量生命周期
    for (int frame = 1; frame <= 3; frame++) {
        cout << "第 " << frame << " 帧:" << endl;

        // 演示: 使用作用域解析运算符调用命名空间中的函数
        Graphics::update();
        Audio::update();
        Physics::update();

        // 演示: 静态局部变量记录帧数
        getFrameCount();

        cout << endl;
    }
    // 此处 frame 变量已销毁（块作用域结束）

    cout << "--- 作用域演示 ---" << endl;
    demonstrateScope();

    cout << "\n--- 静态变量演示 ---" << endl;
    // 演示: 静态变量在多次调用间保持值
    demonstrateStatic();
    demonstrateStatic();
    demonstrateStatic();

    cout << "\n--- 命名空间冲突解决 ---" << endl;
    // 演示: 不同命名空间中的同名变量
    cout << "Graphics::version = " << Graphics::version << endl;
    cout << "Audio::version = " << Audio::version << endl;
    cout << "Physics::version = " << Physics::version << endl;

    cout << "\n=== 游戏系统关闭 ===" << endl;
    // 获取最终帧数（静态变量保持了之前的值，当前为3）
    cout << "总运行帧数: 3" << endl;

    return 0;
}
