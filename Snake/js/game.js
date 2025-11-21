// ===== 游戏主逻辑 =====

import { Snake } from './snake.js';
import { Food } from './food.js';
import {
    CONFIG,
    DIRECTION,
    Storage,
    drawGrid,
    calculateSpeed,
    calculateSpeedLevel
} from './utils.js';

class Game {
    constructor() {
        // 获取 DOM 元素
        this.canvas = document.getElementById('game-canvas');
        this.ctx = this.canvas.getContext('2d');
        this.overlay = document.getElementById('game-overlay');
        this.overlayTitle = document.getElementById('overlay-title');
        this.overlayMessage = document.getElementById('overlay-message');

        // 分数显示
        this.currentScoreEl = document.getElementById('current-score');
        this.highScoreEl = document.getElementById('high-score');
        this.speedLevelEl = document.getElementById('speed-level');

        // 按钮
        this.startBtn = document.getElementById('start-btn');
        this.pauseBtn = document.getElementById('pause-btn');
        this.restartBtn = document.getElementById('restart-btn');

        // 游戏对象
        this.snake = new Snake();
        this.food = new Food();

        // 游戏状态
        this.gameState = 'ready'; // ready, playing, paused, gameOver
        this.score = 0;
        this.highScore = Storage.getHighScore();
        this.gameLoop = null;
        this.lastRenderTime = 0;

        // 初始化
        this.init();
    }

    /**
     * 初始化游戏
     */
    init() {
        // 绑定事件
        this.startBtn.addEventListener('click', () => this.startGame());
        this.pauseBtn.addEventListener('click', () => this.togglePause());
        this.restartBtn.addEventListener('click', () => this.restartGame());

        // 键盘控制
        document.addEventListener('keydown', (e) => this.handleKeyPress(e));

        // 显示最高分
        this.updateHighScoreDisplay();

        // 初始化食物位置
        this.food.spawn(this.snake.body);

        // 初始渲染
        this.render();
    }

    /**
     * 开始游戏
     */
    startGame() {
        if (this.gameState === 'ready' || this.gameState === 'gameOver') {
            this.resetGame();
            this.gameState = 'playing';
            this.hideOverlay();
            this.startGameLoop();
        }
    }

    /**
     * 重置游戏
     */
    resetGame() {
        this.snake.reset();
        this.food.spawn(this.snake.body);
        this.score = 0;
        this.updateScoreDisplay();
        this.updateSpeedDisplay();
    }

    /**
     * 重新开始游戏
     */
    restartGame() {
        this.stopGameLoop();
        this.gameState = 'ready';
        this.resetGame();
        this.showOverlay('准备开始', '按 SPACE 开始游戏');
        this.render();
    }

    /**
     * 切换暂停
     */
    togglePause() {
        if (this.gameState === 'playing') {
            this.pauseGame();
        } else if (this.gameState === 'paused') {
            this.resumeGame();
        }
    }

    /**
     * 暂停游戏
     */
    pauseGame() {
        this.gameState = 'paused';
        this.stopGameLoop();
        this.showOverlay('游戏暂停', '按 SPACE 继续', 'paused');
        this.pauseBtn.innerHTML = '<span class="btn-icon">▶</span><span class="btn-text">继续</span>';
    }

    /**
     * 继续游戏
     */
    resumeGame() {
        this.gameState = 'playing';
        this.hideOverlay();
        this.startGameLoop();
        this.pauseBtn.innerHTML = '<span class="btn-icon">⏸</span><span class="btn-text">暂停</span>';
    }

    /**
     * 游戏结束
     */
    gameOver() {
        this.gameState = 'gameOver';
        this.stopGameLoop();

        // 更新最高分
        const isNewHighScore = Storage.updateHighScore(this.score);
        if (isNewHighScore) {
            this.highScore = this.score;
            this.updateHighScoreDisplay();
        }

        const message = isNewHighScore
            ? `🎉 新纪录！得分: ${this.score}`
            : `得分: ${this.score}`;

        this.showOverlay('游戏结束', message, 'game-over');
        this.startBtn.textContent = '再来一局';
    }

    /**
     * 游戏主循环
     */
    update() {
        // 移动蛇
        this.snake.move();

        // 检查碰撞
        if (this.snake.checkWallCollision() || this.snake.checkSelfCollision()) {
            this.gameOver();
            return;
        }

        // 检查是否吃到食物
        if (this.snake.checkFoodCollision(this.food.getPosition())) {
            this.snake.grow();
            this.score++;
            this.updateScoreDisplay();
            this.updateSpeedDisplay();
            this.food.spawn(this.snake.body);

            // 重新启动游戏循环以更新速度
            this.stopGameLoop();
            this.startGameLoop();
        }

        // 更新食物动画
        this.food.updateAnimation();

        // 渲染
        this.render();
    }

    /**
     * 渲染游戏画面
     */
    render() {
        // 清空画布
        this.ctx.clearRect(0, 0, CONFIG.CANVAS_SIZE, CONFIG.CANVAS_SIZE);

        // 绘制网格
        drawGrid(this.ctx);

        // 绘制食物
        this.food.draw(this.ctx);

        // 绘制蛇
        this.snake.draw(this.ctx);
    }

    /**
     * 启动游戏循环
     */
    startGameLoop() {
        const speed = calculateSpeed(this.score);
        this.gameLoop = setInterval(() => this.update(), speed);
    }

    /**
     * 停止游戏循环
     */
    stopGameLoop() {
        if (this.gameLoop) {
            clearInterval(this.gameLoop);
            this.gameLoop = null;
        }
    }

    /**
     * 键盘事件处理
     */
    handleKeyPress(e) {
        // 防止方向键滚动页面
        if (['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'Space'].includes(e.code)) {
            e.preventDefault();
        }

        // 方向控制（方向键）
        if (this.gameState === 'playing') {
            switch (e.code) {
                case 'ArrowUp':
                case 'KeyW':
                    this.snake.setDirection(DIRECTION.UP);
                    break;
                case 'ArrowDown':
                case 'KeyS':
                    this.snake.setDirection(DIRECTION.DOWN);
                    break;
                case 'ArrowLeft':
                case 'KeyA':
                    this.snake.setDirection(DIRECTION.LEFT);
                    break;
                case 'ArrowRight':
                case 'KeyD':
                    this.snake.setDirection(DIRECTION.RIGHT);
                    break;
            }
        }

        // 空格键：开始/暂停
        if (e.code === 'Space') {
            if (this.gameState === 'ready' || this.gameState === 'gameOver') {
                this.startGame();
            } else if (this.gameState === 'playing') {
                this.pauseGame();
            } else if (this.gameState === 'paused') {
                this.resumeGame();
            }
        }
    }

    /**
     * 显示覆盖层
     */
    showOverlay(title, message, type = '') {
        this.overlayTitle.textContent = title;
        this.overlayMessage.textContent = message;
        this.overlayTitle.className = `overlay-title ${type}`;
        this.overlay.style.display = 'flex';
    }

    /**
     * 隐藏覆盖层
     */
    hideOverlay() {
        this.overlay.style.display = 'none';
    }

    /**
     * 更新分数显示
     */
    updateScoreDisplay() {
        this.currentScoreEl.textContent = this.score;
    }

    /**
     * 更新最高分显示
     */
    updateHighScoreDisplay() {
        this.highScoreEl.textContent = this.highScore;
    }

    /**
     * 更新速度等级显示
     */
    updateSpeedDisplay() {
        const level = calculateSpeedLevel(this.score);
        this.speedLevelEl.textContent = level;
    }
}

// 页面加载完成后初始化游戏
document.addEventListener('DOMContentLoaded', () => {
    new Game();
});
