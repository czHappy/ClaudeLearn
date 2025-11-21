// ===== 蛇类 =====

import { CONFIG, DIRECTION, COLORS, isSamePosition, drawRoundedRect } from './utils.js';

export class Snake {
    constructor() {
        this.reset();
    }

    /**
     * 重置蛇的状态
     */
    reset() {
        // 初始位置在中间
        const startX = Math.floor(CONFIG.GRID_SIZE / 2);
        const startY = Math.floor(CONFIG.GRID_SIZE / 2);

        // 蛇身数组，头部在第一个位置
        this.body = [
            { x: startX, y: startY },
            { x: startX - 1, y: startY },
            { x: startX - 2, y: startY }
        ];

        // 初始方向向右
        this.direction = DIRECTION.RIGHT;
        this.nextDirection = DIRECTION.RIGHT; // 下一个方向（缓冲输入）
    }

    /**
     * 获取蛇头位置
     */
    getHead() {
        return this.body[0];
    }

    /**
     * 设置方向（带反向检查）
     */
    setDirection(newDirection) {
        // 防止反向移动（不能180度转向）
        const currentDir = this.direction;
        if (
            (newDirection === DIRECTION.UP && currentDir !== DIRECTION.DOWN) ||
            (newDirection === DIRECTION.DOWN && currentDir !== DIRECTION.UP) ||
            (newDirection === DIRECTION.LEFT && currentDir !== DIRECTION.RIGHT) ||
            (newDirection === DIRECTION.RIGHT && currentDir !== DIRECTION.LEFT)
        ) {
            this.nextDirection = newDirection;
        }
    }

    /**
     * 移动蛇
     * @returns {Object} 新的头部位置
     */
    move() {
        // 更新方向
        this.direction = this.nextDirection;

        // 计算新头部位置
        const head = this.getHead();
        const newHead = {
            x: head.x + this.direction.x,
            y: head.y + this.direction.y
        };

        // 添加新头部
        this.body.unshift(newHead);

        // 移除尾部（正常移动）
        this.body.pop();

        return newHead;
    }

    /**
     * 生长（吃到食物时）
     */
    grow() {
        // 在当前尾部位置添加一节
        const tail = this.body[this.body.length - 1];
        this.body.push({ ...tail });
    }

    /**
     * 检查是否撞墙
     */
    checkWallCollision() {
        const head = this.getHead();
        return (
            head.x < 0 ||
            head.x >= CONFIG.GRID_SIZE ||
            head.y < 0 ||
            head.y >= CONFIG.GRID_SIZE
        );
    }

    /**
     * 检查是否撞到自己
     */
    checkSelfCollision() {
        const head = this.getHead();
        // 从第1个位置开始检查（跳过头部自己）
        for (let i = 1; i < this.body.length; i++) {
            if (isSamePosition(head, this.body[i])) {
                return true;
            }
        }
        return false;
    }

    /**
     * 检查是否吃到食物
     */
    checkFoodCollision(foodPosition) {
        return isSamePosition(this.getHead(), foodPosition);
    }

    /**
     * 绘制蛇
     */
    draw(ctx) {
        this.body.forEach((segment, index) => {
            const x = segment.x * CONFIG.CELL_SIZE;
            const y = segment.y * CONFIG.CELL_SIZE;
            const padding = 2; // 内边距
            const size = CONFIG.CELL_SIZE - padding * 2;

            // 头部和身体使用不同颜色
            if (index === 0) {
                // 头部 - 更亮的绿色 + 发光效果
                ctx.fillStyle = COLORS.SNAKE_HEAD;
                ctx.shadowBlur = 15;
                ctx.shadowColor = COLORS.SNAKE_GLOW;
            } else {
                // 身体 - 渐变效果
                const gradient = ctx.createLinearGradient(x, y, x + size, y + size);
                gradient.addColorStop(0, COLORS.SNAKE_HEAD);
                gradient.addColorStop(1, COLORS.SNAKE_BODY);
                ctx.fillStyle = gradient;
                ctx.shadowBlur = 10;
                ctx.shadowColor = COLORS.SNAKE_GLOW;
            }

            // 绘制圆角矩形
            drawRoundedRect(ctx, x + padding, y + padding, size, size, 5);
            ctx.fill();

            // 重置阴影
            ctx.shadowBlur = 0;
        });
    }

    /**
     * 获取蛇的长度
     */
    getLength() {
        return this.body.length;
    }
}
