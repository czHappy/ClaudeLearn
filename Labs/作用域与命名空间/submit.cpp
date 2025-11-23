#include <iostream>
using std::cout;
using std::endl;

// ==================== TODO 1: 定义全局变量 ====================
// TODO: 定义全局变量 gameRunning (bool类型)，初始值为 true

// TODO: 定义全局常量 MAX_FPS (int类型)，值为 60


// ==================== TODO 2: 定义 Graphics 命名空间 ====================
// TODO: 创建 Graphics 命名空间
namespace Graphics {
    // TODO: 定义命名空间内的变量 version (double类型)，值为 1.0

    // TODO: 实现 initialize() 函数
    // 输出: "[Graphics] 图形模块初始化完成"

    // TODO: 实现 update() 函数
    // 输出: "  [Graphics] 渲染场景..."

    // TODO: 实现 render() 函数
    // 输出: "  渲染中..."

}


// ==================== TODO 3: 定义 Audio 命名空间 ====================
// TODO: 创建 Audio 命名空间
namespace Audio {
    // TODO: 定义命名空间内的变量 version (double类型)，值为 2.0

    // TODO: 实现 initialize() 函数
    // 输出: "[Audio] 音频模块初始化完成"

    // TODO: 实现 update() 函数
    // 输出: "  [Audio] 播放背景音乐"

    // TODO: 实现 playSound() 函数
    // 输出: "  播放音效..."

}


// ==================== TODO 4: 定义 Physics 命名空间 ====================
// TODO: 创建 Physics 命名空间
namespace Physics {
    // TODO: 定义命名空间内的变量 version (double类型)，值为 1.5

    // TODO: 定义命名空间内的常量 gravity (double类型)，值为 9.8

    // TODO: 实现 initialize() 函数
    // 输出: "[Physics] 物理模块初始化完成"

    // TODO: 实现 update() 函数
    // 输出: "  [Physics] 物理模拟: 重力 = " << gravity

    // TODO: 实现 simulate() 函数
    // 输出: "  模拟物理运动..."

}


// ==================== TODO 5: 实现帧计数函数（静态局部变量） ====================
// TODO: 实现 getFrameCount() 函数
// 使用静态局部变量 frameCount 统计调用次数
// 每次调用时 frameCount 自增1，并返回当前值
// 返回类型: int



// ==================== TODO 6: 演示作用域就近原则 ====================
// TODO: 实现 demonstrateScope() 函数
// 1. 定义局部变量 playerId = 1001
// 2. 输出 "外层作用域: 玩家ID = " << playerId
// 3. 在内层块作用域中:
//    - 定义新的局部变量 playerId = 2002
//    - 输出 "  内层作用域: 玩家ID = " << playerId
//    - 使用 ::playerId 访问外层变量(如果有全局变量的话)
// 4. 返回外层作用域，输出 "返回外层作用域: 玩家ID = " << playerId



// ==================== TODO 7: 演示静态变量 ====================
// TODO: 实现 demonstrateStatic() 函数
// 使用静态局部变量 callCount 统计函数被调用的次数
// 输出 "调用统计: 第 " << callCount << " 次"



// ==================== 主函数 ====================
int main() {
    cout << "=== 游戏系统启动 ===" << endl;

    // TODO: 输出最大FPS和游戏状态
    // 输出: "最大FPS: " << MAX_FPS
    // 输出: "游戏状态: " << (gameRunning ? "运行中" : "已停止")


    cout << "\n--- 初始化各模块 ---" << endl;
    // TODO: 调用三个命名空间的 initialize() 函数
    // 提示: 使用作用域解析运算符 Graphics::initialize()



    cout << "\n--- 游戏主循环 (3帧演示) ---" << endl;
    // TODO: 使用 for 循环模拟3帧游戏循环
    // 每一帧:
    //   1. 输出 "第 X 帧:"
    //   2. 调用 Graphics::update()
    //   3. 调用 Audio::update()
    //   4. 调用 Physics::update()
    //   5. 调用 getFrameCount()
    //   6. 输出空行






    cout << "--- 作用域演示 ---" << endl;
    // TODO: 调用 demonstrateScope() 函数


    cout << "\n--- 静态变量演示 ---" << endl;
    // TODO: 调用 demonstrateStatic() 函数 3 次



    cout << "\n--- 命名空间冲突解决 ---" << endl;
    // TODO: 使用作用域解析运算符输出三个命名空间的 version 变量
    // 输出格式: "Graphics::version = " << Graphics::version




    cout << "\n=== 游戏系统关闭 ===" << endl;
    // TODO: 输出总运行帧数
    // 调用 getFrameCount() 获取当前帧数
    // 输出: "总运行帧数: " << 帧数


    return 0;
}
