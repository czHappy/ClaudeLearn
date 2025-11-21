// ===== 工具函数模块 =====

/**
 * 游戏配置常量
 */
export const CONFIG = {
    GRID_SIZE: 20,           // 网格大小 (20x20)
    CELL_SIZE: 25,           // 每个单元格的像素大小
    CANVAS_SIZE: 500,        // 画布大小
    INITIAL_SPEED: 150,      // 初始速度 (ms)
    SPEED_INCREMENT: 10,     // 速度递增量
    SPEED_INTERVAL: 5,       // 每吃几个食物加速
    MIN_SPEED: 50,           // 最小速度（最快）
};

/**
 * 方向枚举
 */
export const DIRECTION = {
    UP: { x: 0, y: -1 },
    DOWN: { x: 0, y: 1 },
    LEFT: { x: -1, y: 0 },
    RIGHT: { x: 1, y: 0 }
};

/**
 * 颜色配置
 */
export const COLORS = {
    // 背景
    GRID_LINE: 'rgba(255, 255, 255, 0.05)',

    // 蛇身
    SNAKE_HEAD: '#00ff88',
    SNAKE_BODY: '#00cc6a',
    SNAKE_GLOW: 'rgba(0, 255, 136, 0.5)',

    // 食物
    FOOD_PRIMARY: '#ff0066',
    FOOD_SECONDARY: '#ff6b9d',
    FOOD_GLOW: 'rgba(255, 0, 102, 0.6)',
};

/**
 * 检查两个位置是否相同
 */
export function isSamePosition(pos1, pos2) {
    return pos1.x === pos2.x && pos1.y === pos2.y;
}

/**
 * 生成随机位置
 */
export function getRandomPosition() {
    return {
        x: Math.floor(Math.random() * CONFIG.GRID_SIZE),
        y: Math.floor(Math.random() * CONFIG.GRID_SIZE)
    };
}

/**
 * 检查位置是否在数组中
 */
export function isPositionInArray(position, array) {
    return array.some(item => isSamePosition(item, position));
}

/**
 * 本地存储操作
 */
export const Storage = {
    // 获取最高分
    getHighScore() {
        return parseInt(localStorage.getItem('snakeHighScore') || '0', 10);
    },

    // 保存最高分
    setHighScore(score) {
        localStorage.setItem('snakeHighScore', score.toString());
    },

    // 更新最高分（如果当前分数更高）
    updateHighScore(currentScore) {
        const highScore = this.getHighScore();
        if (currentScore > highScore) {
            this.setHighScore(currentScore);
            return true;
        }
        return false;
    }
};

/**
 * 绘制圆角矩形
 */
export function drawRoundedRect(ctx, x, y, width, height, radius) {
    ctx.beginPath();
    ctx.moveTo(x + radius, y);
    ctx.lineTo(x + width - radius, y);
    ctx.quadraticCurveTo(x + width, y, x + width, y + radius);
    ctx.lineTo(x + width, y + height - radius);
    ctx.quadraticCurveTo(x + width, y + height, x + width - radius, y + height);
    ctx.lineTo(x + radius, y + height);
    ctx.quadraticCurveTo(x, y + height, x, y + height - radius);
    ctx.lineTo(x, y + radius);
    ctx.quadraticCurveTo(x, y, x + radius, y);
    ctx.closePath();
}

/**
 * 绘制网格背景
 */
export function drawGrid(ctx) {
    ctx.strokeStyle = COLORS.GRID_LINE;
    ctx.lineWidth = 1;

    // 绘制垂直线
    for (let x = 0; x <= CONFIG.GRID_SIZE; x++) {
        const posX = x * CONFIG.CELL_SIZE;
        ctx.beginPath();
        ctx.moveTo(posX, 0);
        ctx.lineTo(posX, CONFIG.CANVAS_SIZE);
        ctx.stroke();
    }

    // 绘制水平线
    for (let y = 0; y <= CONFIG.GRID_SIZE; y++) {
        const posY = y * CONFIG.CELL_SIZE;
        ctx.beginPath();
        ctx.moveTo(0, posY);
        ctx.lineTo(CONFIG.CANVAS_SIZE, posY);
        ctx.stroke();
    }
}

/**
 * 计算速度等级
 */
export function calculateSpeedLevel(score) {
    return Math.floor(score / CONFIG.SPEED_INTERVAL) + 1;
}

/**
 * 计算游戏速度
 */
export function calculateSpeed(score) {
    const speedReduction = Math.floor(score / CONFIG.SPEED_INTERVAL) * CONFIG.SPEED_INCREMENT;
    return Math.max(CONFIG.MIN_SPEED, CONFIG.INITIAL_SPEED - speedReduction);
}
