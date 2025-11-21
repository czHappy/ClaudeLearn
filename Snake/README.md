# 🐍 贪吃蛇游戏 (Snake Game)

一个基于 HTML5 Canvas 开发的现代化贪吃蛇游戏，采用霓虹风格设计，提供流畅的游戏体验。

![Game Preview](https://img.shields.io/badge/Status-Ready-success)
![HTML5](https://img.shields.io/badge/HTML5-Canvas-orange)
![JavaScript](https://img.shields.io/badge/JavaScript-ES6+-yellow)
![CSS3](https://img.shields.io/badge/CSS3-Responsive-blue)

## 📸 游戏截图

- 霓虹风格界面
- 深色太空主题背景
- 发光效果的蛇身和食物
- 清晰的分数和速度显示

## ✨ 功能特性

### 核心玩法
- ✅ 经典贪吃蛇游戏机制
- ✅ 流畅的蛇移动动画
- ✅ 随机生成食物位置
- ✅ 碰撞检测（墙壁和自身）
- ✅ 蛇身自动生长

### 游戏控制
- ✅ 方向键控制（↑ ↓ ← →）
- ✅ WASD 键盘控制
- ✅ 空格键暂停/继续
- ✅ 按钮控制（开始、暂停、重启）

### 进阶功能
- ✅ 实时计分系统
- ✅ 最高分记录（本地存储）
- ✅ 速度递增机制（每吃 5 个食物加速）
- ✅ 速度等级显示
- ✅ 新纪录提示
- ✅ 游戏状态管理（准备、进行中、暂停、结束）

### 视觉效果
- ✅ 霓虹发光效果
- ✅ 渐变色蛇身
- ✅ 食物脉冲动画
- ✅ 半透明网格背景
- ✅ 圆角矩形设计
- ✅ 响应式布局（支持移动设备）

## 🎮 如何开始游戏

### ⭐ 最简单的方式（无需任何依赖）

**只需浏览器，即可运行！**

1. **双击打开 `index.html` 文件**
   - 在文件夹中找到 `index.html`
   - 双击文件，会在默认浏览器中打开
   - 立即开始玩！

2. **或使用命令行打开**
   ```bash
   # 在终端中执行
   open index.html

   # 或指定完整路径
   open /Users/cz/workspace/claude/Snake/index.html
   ```

3. **拷贝到任何电脑**
   - 将整个 `Snake` 文件夹复制到 U 盘或其他电脑
   - 只需有浏览器即可运行
   - ✅ 无需 Python
   - ✅ 无需 Node.js
   - ✅ 无需任何服务器
   - ✅ 无需网络连接

### 可选：使用本地服务器（仅用于开发）

如果你是开发者，想要进行代码调试，可以使用本地服务器：

**使用 Python：**
```bash
cd /Users/cz/workspace/claude/Snake
python3 -m http.server 8000
# 访问 http://localhost:8000
```

**使用 Node.js：**
```bash
npm install -g http-server
http-server -p 8000
# 访问 http://localhost:8000
```

**使用 VSCode Live Server：**
- 安装 "Live Server" 插件
- 右键点击 `index.html` → "Open with Live Server"

## 🕹️ 操作指南

### 键盘控制

| 按键 | 功能 |
|------|------|
| `↑` 或 `W` | 向上移动 |
| `↓` 或 `S` | 向下移动 |
| `←` 或 `A` | 向左移动 |
| `→` 或 `D` | 向右移动 |
| `Space` | 开始游戏 / 暂停 / 继续 |

### 鼠标控制

- **开始游戏按钮**：点击开始新游戏
- **暂停按钮**：暂停或继续游戏
- **重新开始按钮**：重置游戏到初始状态

### 游戏规则

1. 🎯 **目标**：控制蛇吃到食物，让蛇身变长，获得更高分数
2. 🚫 **失败条件**：
   - 撞到墙壁（游戏边界）
   - 撞到自己的身体
3. 📈 **计分规则**：
   - 每吃到一个食物 +1 分
   - 每吃 5 个食物，速度提升一级
4. 🏆 **最高分**：自动保存到浏览器本地存储

## 📁 项目结构

```
Snake/
├── index.html              # 主 HTML 文件（游戏入口）
├── snake-game.js           # 游戏完整代码（单文件，无依赖）
├── css/
│   └── style.css          # 样式表（霓虹风格设计）
├── README.md               # 项目文档（本文件）
├── plan.md                 # 开发计划文档
├── js/                     # （已弃用：模块化版本）
│   ├── utils.js           # 工具函数和配置常量
│   ├── snake.js           # Snake 类
│   ├── food.js            # Food 类
│   └── game.js            # Game 类
└── assets/
    └── (预留：音效文件等)
```

**核心文件说明：**
- `index.html` - 游戏主页面
- `snake-game.js` - 完整的游戏逻辑（单文件，便于移植）
- `css/style.css` - 所有样式

**✨ 移植到其他电脑：只需复制这 3 个文件/文件夹即可！**

## 🛠️ 技术架构

### 技术栈

- **HTML5 Canvas**：游戏渲染引擎
- **原生 JavaScript (ES6+)**：游戏逻辑
  - Classes（面向对象）
  - Arrow Functions（箭头函数）
  - LocalStorage（本地存储）
- **CSS3**：界面样式
  - Flexbox 布局
  - CSS Variables（CSS 变量）
  - Backdrop Filter（毛玻璃效果）
  - Gradients（渐变）
  - Shadows（阴影和发光效果）

### 设计模式

#### 1. 面向对象设计

**Snake 类** (`snake-game.js`)
- 职责：管理蛇的状态和行为
- 主要方法：
  - `move()` - 移动蛇
  - `grow()` - 蛇身生长
  - `setDirection()` - 设置移动方向（带反向检测）
  - `checkWallCollision()` - 检测墙壁碰撞
  - `checkSelfCollision()` - 检测自身碰撞
  - `draw()` - 绘制蛇

**Food 类** (`snake-game.js`)
- 职责：管理食物的生成和显示
- 主要方法：
  - `spawn()` - 随机生成食物位置
  - `updateAnimation()` - 更新动画帧
  - `draw()` - 绘制食物（带脉冲动画）

**Game 类** (`snake-game.js`)
- 职责：游戏主控制器
- 主要方法：
  - `startGame()` - 开始游戏
  - `pauseGame()` - 暂停游戏
  - `gameOver()` - 游戏结束
  - `update()` - 游戏主循环
  - `render()` - 渲染画面

#### 2. 单文件架构

为了便于移植和使用，所有 JavaScript 代码整合到一个文件中：
- 无需模块加载器
- 无需构建工具
- 无需服务器
- 可直接在浏览器中运行

#### 3. 事件驱动

- 键盘事件监听
- 按钮点击事件
- 游戏循环使用 `setInterval`

### 核心算法

#### 蛇移动算法
```javascript
// 1. 计算新头部位置
newHead = head + direction

// 2. 添加新头部到数组开头
body.unshift(newHead)

// 3. 移除尾部（正常移动）
// 或保留尾部（吃到食物时）
if (!ateFood) {
    body.pop()
}
```

#### 碰撞检测
```javascript
// 墙壁碰撞
head.x < 0 || head.x >= GRID_SIZE ||
head.y < 0 || head.y >= GRID_SIZE

// 自身碰撞
body.slice(1).some(segment =>
    segment.x === head.x && segment.y === head.y
)
```

#### 速度递增
```javascript
// 每吃 5 个食物减少 10ms 延迟（加快速度）
speed = max(MIN_SPEED, INITIAL_SPEED - floor(score / 5) * 10)
```

## 🎨 设计说明

### 色彩方案

| 元素 | 颜色 | 说明 |
|------|------|------|
| 背景渐变 | `#0f0f23` → `#1a1a3e` → `#252550` | 深色太空主题 |
| 蛇头 | `#00ff88` | 霓虹绿色 |
| 蛇身 | `#00cc6a` | 深绿色 |
| 食物 | `#ff0066` → `#ff6b9d` | 霓虹粉色渐变 |
| 文字主色 | `#ffffff` | 白色 |
| 文字次要色 | `#a0a0c0` | 浅紫灰色 |

### 视觉效果

1. **发光效果** (`box-shadow` + `text-shadow`)
   ```css
   box-shadow: 0 0 20px rgba(0, 255, 136, 0.5);
   ```

2. **渐变背景** (`linear-gradient`)
   ```css
   background: linear-gradient(135deg, #0f0f23 0%, #1a1a3e 50%, #252550 100%);
   ```

3. **毛玻璃效果** (`backdrop-filter`)
   ```css
   backdrop-filter: blur(10px);
   ```

4. **动画效果**
   - 食物脉冲：`Math.sin()` 周期函数
   - 按钮发光：CSS `@keyframes` 动画

### 响应式设计

- 移动端自适应
- 小屏幕下控制按钮堆叠显示
- Canvas 自适应缩放

## 📊 游戏配置

你可以在 `js/utils.js` 中修改游戏配置：

```javascript
export const CONFIG = {
    GRID_SIZE: 20,           // 网格大小 (20x20)
    CELL_SIZE: 25,           // 每个单元格像素大小
    INITIAL_SPEED: 150,      // 初始速度 (ms) - 越小越快
    SPEED_INCREMENT: 10,     // 每次加速减少的时间 (ms)
    SPEED_INTERVAL: 5,       // 每吃几个食物加速一次
    MIN_SPEED: 50,           // 最小速度（最快）(ms)
};
```

### 调整难度示例

**简单模式**
```javascript
INITIAL_SPEED: 200,      // 更慢
SPEED_INCREMENT: 5,      // 加速更慢
SPEED_INTERVAL: 8,       // 需要吃更多食物才加速
```

**困难模式**
```javascript
INITIAL_SPEED: 100,      // 更快
SPEED_INCREMENT: 15,     // 加速更快
SPEED_INTERVAL: 3,       // 更快加速
MIN_SPEED: 30,           // 最终速度更快
```

## 🔧 开发和调试

### 浏览器兼容性

- ✅ Chrome / Edge (推荐)
- ✅ Firefox
- ✅ Safari
- ⚠️ IE 不支持（需要 ES6+ 支持）

### 调试模式

打开浏览器开发者工具（F12）可以：
- 查看控制台日志
- 调试 JavaScript 代码
- 检查 Canvas 渲染
- 查看 LocalStorage 数据

### 清除最高分记录

在浏览器控制台执行：
```javascript
localStorage.removeItem('snakeHighScore');
location.reload();
```

## 🚀 部署指南

### 部署到 GitHub Pages

1. **创建 Git 仓库**
   ```bash
   cd /Users/cz/workspace/claude/Snake
   git init
   git add .
   git commit -m "Initial commit: Snake Game"
   ```

2. **推送到 GitHub**
   ```bash
   # 在 GitHub 创建新仓库，然后执行
   git remote add origin https://github.com/你的用户名/snake-game.git
   git branch -M main
   git push -u origin main
   ```

3. **启用 GitHub Pages**
   - 进入仓库 Settings
   - 找到 Pages 选项
   - Source 选择 `main` 分支
   - 保存后即可访问 `https://你的用户名.github.io/snake-game/`

### 部署到 Vercel / Netlify

**Vercel:**
```bash
# 安装 Vercel CLI
npm install -g vercel

# 部署
cd /Users/cz/workspace/claude/Snake
vercel
```

**Netlify:**
1. 拖拽整个 `Snake` 文件夹到 Netlify Drop
2. 或使用 Netlify CLI 部署

## 📝 未来功能规划

- [ ] 音效系统（吃食物、游戏结束音效）
- [ ] 多种游戏模式（经典、无墙、时间挑战）
- [ ] 道具系统（加速、减速、穿墙）
- [ ] 多人对战模式
- [ ] 排行榜（在线）
- [ ] 主题切换（霓虹、复古、简约）
- [ ] 触摸屏控制（移动端虚拟摇杆）
- [ ] PWA 支持（可安装到桌面）

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

## 📄 许可证

MIT License - 自由使用和修改

## 👨‍💻 作者

开发者：Claude Code
日期：2025年

---

## 🎯 快速开始总结

**最简单的方式（推荐）：**

```bash
# 直接双击打开 index.html
# 或在终端执行：
open index.html
```

**移植到其他电脑：**

1. 复制整个 `Snake` 文件夹
2. 在任何电脑上双击 `index.html`
3. 立即开始玩！

**无需：**
- ❌ Python
- ❌ Node.js
- ❌ 任何服务器
- ❌ 网络连接
- ❌ 安装任何软件

**只需：**
- ✅ 现代浏览器（Chrome、Firefox、Safari、Edge）

---

**祝你玩得开心！🐍🎮✨**
