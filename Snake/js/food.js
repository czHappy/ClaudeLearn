// ===== 食物类 =====

import { CONFIG, COLORS, getRandomPosition, isPositionInArray, drawRoundedRect } from './utils.js';

export class Food {
    constructor() {
        this.position = null;
        this.animation = 0; // 用于动画效果
    }

    /**
     * 生成新的食物位置
     * @param {Array} snakeBody - 蛇身数组，确保食物不生成在蛇身上
     */
    spawn(snakeBody) {
        let newPosition;
        let attempts = 0;
        const maxAttempts = 100; // 防止无限循环

        // 随机生成位置，直到找到一个不在蛇身上的位置
        do {
            newPosition = getRandomPosition();
            attempts++;
        } while (isPositionInArray(newPosition, snakeBody) && attempts < maxAttempts);

        this.position = newPosition;
        this.animation = 0;
    }

    /**
     * 获取食物位置
     */
    getPosition() {
        return this.position;
    }

    /**
     * 更新动画
     */
    updateAnimation() {
        this.animation += 0.1;
        if (this.animation > Math.PI * 2) {
            this.animation = 0;
        }
    }

    /**
     * 绘制食物
     */
    draw(ctx) {
        if (!this.position) return;

        const x = this.position.x * CONFIG.CELL_SIZE;
        const y = this.position.y * CONFIG.CELL_SIZE;
        const padding = 3;
        const size = CONFIG.CELL_SIZE - padding * 2;

        // 计算脉冲效果
        const pulse = Math.sin(this.animation) * 0.2 + 1; // 0.8 - 1.2
        const glowIntensity = Math.sin(this.animation) * 10 + 15; // 5 - 25

        // 渐变色
        const gradient = ctx.createRadialGradient(
            x + CONFIG.CELL_SIZE / 2,
            y + CONFIG.CELL_SIZE / 2,
            0,
            x + CONFIG.CELL_SIZE / 2,
            y + CONFIG.CELL_SIZE / 2,
            size / 2
        );
        gradient.addColorStop(0, COLORS.FOOD_SECONDARY);
        gradient.addColorStop(1, COLORS.FOOD_PRIMARY);

        // 发光效果
        ctx.shadowBlur = glowIntensity;
        ctx.shadowColor = COLORS.FOOD_GLOW;
        ctx.fillStyle = gradient;

        // 绘制圆形食物（使用 arc）
        ctx.beginPath();
        ctx.arc(
            x + CONFIG.CELL_SIZE / 2,
            y + CONFIG.CELL_SIZE / 2,
            (size / 2) * pulse,
            0,
            Math.PI * 2
        );
        ctx.fill();

        // 内部高光
        ctx.shadowBlur = 0;
        ctx.fillStyle = 'rgba(255, 255, 255, 0.3)';
        ctx.beginPath();
        ctx.arc(
            x + CONFIG.CELL_SIZE / 2 - 3,
            y + CONFIG.CELL_SIZE / 2 - 3,
            size / 6,
            0,
            Math.PI * 2
        );
        ctx.fill();

        // 重置阴影
        ctx.shadowBlur = 0;
    }
}
