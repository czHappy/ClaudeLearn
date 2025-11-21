// ===== 贪吃蛇游戏 - 完整版本 =====

// ===== 配置和工具函数 =====

const CONFIG = {
    GRID_SIZE: 20,           // 网格大小 (20x20)
    CELL_SIZE: 25,           // 每个单元格的像素大小
    CANVAS_SIZE: 500,        // 画布大小
    INITIAL_SPEED: 150,      // 初始速度 (ms)
    SPEED_INCREMENT: 10,     // 速度递增量
    SPEED_INTERVAL: 5,       // 每吃几个食物加速
    MIN_SPEED: 50,           // 最小速度（最快）
};

const DIRECTION = {
    UP: { x: 0, y: -1 },
    DOWN: { x: 0, y: 1 },
    LEFT: { x: -1, y: 0 },
    RIGHT: { x: 1, y: 0 }
};

const COLORS = {
    GRID_LINE: 'rgba(255, 255, 255, 0.05)',
    SNAKE_HEAD: '#00ff88',
    SNAKE_BODY: '#00cc6a',
    SNAKE_GLOW: 'rgba(0, 255, 136, 0.5)',
    FOOD_PRIMARY: '#ff0066',
    FOOD_SECONDARY: '#ff6b9d',
    FOOD_GLOW: 'rgba(255, 0, 102, 0.6)',
};

// 工具函数
function isSamePosition(pos1, pos2) {
    return pos1.x === pos2.x && pos1.y === pos2.y;
}

function getRandomPosition() {
    return {
        x: Math.floor(Math.random() * CONFIG.GRID_SIZE),
        y: Math.floor(Math.random() * CONFIG.GRID_SIZE)
    };
}

function isPositionInArray(position, array) {
    return array.some(item => isSamePosition(item, position));
}

const Storage = {
    getHighScore() {
        return parseInt(localStorage.getItem('snakeHighScore') || '0', 10);
    },
    setHighScore(score) {
        localStorage.setItem('snakeHighScore', score.toString());
    },
    updateHighScore(currentScore) {
        const highScore = this.getHighScore();
        if (currentScore > highScore) {
            this.setHighScore(currentScore);
            return true;
        }
        return false;
    }
};

function drawRoundedRect(ctx, x, y, width, height, radius) {
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

function drawGrid(ctx) {
    ctx.strokeStyle = COLORS.GRID_LINE;
    ctx.lineWidth = 1;

    for (let x = 0; x <= CONFIG.GRID_SIZE; x++) {
        const posX = x * CONFIG.CELL_SIZE;
        ctx.beginPath();
        ctx.moveTo(posX, 0);
        ctx.lineTo(posX, CONFIG.CANVAS_SIZE);
        ctx.stroke();
    }

    for (let y = 0; y <= CONFIG.GRID_SIZE; y++) {
        const posY = y * CONFIG.CELL_SIZE;
        ctx.beginPath();
        ctx.moveTo(0, posY);
        ctx.lineTo(CONFIG.CANVAS_SIZE, posY);
        ctx.stroke();
    }
}

function calculateSpeedLevel(score) {
    return Math.floor(score / CONFIG.SPEED_INTERVAL) + 1;
}

function calculateSpeed(score) {
    const speedReduction = Math.floor(score / CONFIG.SPEED_INTERVAL) * CONFIG.SPEED_INCREMENT;
    return Math.max(CONFIG.MIN_SPEED, CONFIG.INITIAL_SPEED - speedReduction);
}

// ===== Snake 类 =====

class Snake {
    constructor() {
        this.reset();
    }

    reset() {
        const startX = Math.floor(CONFIG.GRID_SIZE / 2);
        const startY = Math.floor(CONFIG.GRID_SIZE / 2);

        this.body = [
            { x: startX, y: startY },
            { x: startX - 1, y: startY },
            { x: startX - 2, y: startY }
        ];

        this.direction = DIRECTION.RIGHT;
        this.nextDirection = DIRECTION.RIGHT;
    }

    getHead() {
        return this.body[0];
    }

    setDirection(newDirection) {
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

    move() {
        this.direction = this.nextDirection;

        const head = this.getHead();
        const newHead = {
            x: head.x + this.direction.x,
            y: head.y + this.direction.y
        };

        this.body.unshift(newHead);
        this.body.pop();

        return newHead;
    }

    grow() {
        const tail = this.body[this.body.length - 1];
        this.body.push({ ...tail });
    }

    checkWallCollision() {
        const head = this.getHead();
        return (
            head.x < 0 ||
            head.x >= CONFIG.GRID_SIZE ||
            head.y < 0 ||
            head.y >= CONFIG.GRID_SIZE
        );
    }

    checkSelfCollision() {
        const head = this.getHead();
        for (let i = 1; i < this.body.length; i++) {
            if (isSamePosition(head, this.body[i])) {
                return true;
            }
        }
        return false;
    }

    checkFoodCollision(foodPosition) {
        return isSamePosition(this.getHead(), foodPosition);
    }

    draw(ctx) {
        this.body.forEach((segment, index) => {
            const x = segment.x * CONFIG.CELL_SIZE;
            const y = segment.y * CONFIG.CELL_SIZE;
            const padding = 2;
            const size = CONFIG.CELL_SIZE - padding * 2;

            if (index === 0) {
                ctx.fillStyle = COLORS.SNAKE_HEAD;
                ctx.shadowBlur = 15;
                ctx.shadowColor = COLORS.SNAKE_GLOW;
            } else {
                const gradient = ctx.createLinearGradient(x, y, x + size, y + size);
                gradient.addColorStop(0, COLORS.SNAKE_HEAD);
                gradient.addColorStop(1, COLORS.SNAKE_BODY);
                ctx.fillStyle = gradient;
                ctx.shadowBlur = 10;
                ctx.shadowColor = COLORS.SNAKE_GLOW;
            }

            drawRoundedRect(ctx, x + padding, y + padding, size, size, 5);
            ctx.fill();

            ctx.shadowBlur = 0;
        });
    }

    getLength() {
        return this.body.length;
    }
}

// ===== Food 类 =====

class Food {
    constructor() {
        this.position = null;
        this.animation = 0;
    }

    spawn(snakeBody) {
        let newPosition;
        let attempts = 0;
        const maxAttempts = 100;

        do {
            newPosition = getRandomPosition();
            attempts++;
        } while (isPositionInArray(newPosition, snakeBody) && attempts < maxAttempts);

        this.position = newPosition;
        this.animation = 0;
    }

    getPosition() {
        return this.position;
    }

    updateAnimation() {
        this.animation += 0.1;
        if (this.animation > Math.PI * 2) {
            this.animation = 0;
        }
    }

    draw(ctx) {
        if (!this.position) return;

        const x = this.position.x * CONFIG.CELL_SIZE;
        const y = this.position.y * CONFIG.CELL_SIZE;
        const padding = 3;
        const size = CONFIG.CELL_SIZE - padding * 2;

        const pulse = Math.sin(this.animation) * 0.2 + 1;
        const glowIntensity = Math.sin(this.animation) * 10 + 15;

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

        ctx.shadowBlur = glowIntensity;
        ctx.shadowColor = COLORS.FOOD_GLOW;
        ctx.fillStyle = gradient;

        ctx.beginPath();
        ctx.arc(
            x + CONFIG.CELL_SIZE / 2,
            y + CONFIG.CELL_SIZE / 2,
            (size / 2) * pulse,
            0,
            Math.PI * 2
        );
        ctx.fill();

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

        ctx.shadowBlur = 0;
    }
}

// ===== Game 类 =====

class Game {
    constructor() {
        this.canvas = document.getElementById('game-canvas');
        this.ctx = this.canvas.getContext('2d');
        this.overlay = document.getElementById('game-overlay');
        this.overlayTitle = document.getElementById('overlay-title');
        this.overlayMessage = document.getElementById('overlay-message');

        this.currentScoreEl = document.getElementById('current-score');
        this.highScoreEl = document.getElementById('high-score');
        this.speedLevelEl = document.getElementById('speed-level');

        this.startBtn = document.getElementById('start-btn');
        this.pauseBtn = document.getElementById('pause-btn');
        this.restartBtn = document.getElementById('restart-btn');

        this.snake = new Snake();
        this.food = new Food();

        this.gameState = 'ready';
        this.score = 0;
        this.highScore = Storage.getHighScore();
        this.gameLoop = null;

        this.init();
    }

    init() {
        this.startBtn.addEventListener('click', () => this.startGame());
        this.pauseBtn.addEventListener('click', () => this.togglePause());
        this.restartBtn.addEventListener('click', () => this.restartGame());

        document.addEventListener('keydown', (e) => this.handleKeyPress(e));

        this.updateHighScoreDisplay();
        this.food.spawn(this.snake.body);
        this.render();
    }

    startGame() {
        if (this.gameState === 'ready' || this.gameState === 'gameOver') {
            this.resetGame();
            this.gameState = 'playing';
            this.hideOverlay();
            this.startGameLoop();
        }
    }

    resetGame() {
        this.snake.reset();
        this.food.spawn(this.snake.body);
        this.score = 0;
        this.updateScoreDisplay();
        this.updateSpeedDisplay();
    }

    restartGame() {
        this.stopGameLoop();
        this.gameState = 'ready';
        this.resetGame();
        this.showOverlay('准备开始', '按 SPACE 开始游戏');
        this.render();
    }

    togglePause() {
        if (this.gameState === 'playing') {
            this.pauseGame();
        } else if (this.gameState === 'paused') {
            this.resumeGame();
        }
    }

    pauseGame() {
        this.gameState = 'paused';
        this.stopGameLoop();
        this.showOverlay('游戏暂停', '按 SPACE 继续', 'paused');
        this.pauseBtn.innerHTML = '<span class="btn-icon">▶</span><span class="btn-text">继续</span>';
    }

    resumeGame() {
        this.gameState = 'playing';
        this.hideOverlay();
        this.startGameLoop();
        this.pauseBtn.innerHTML = '<span class="btn-icon">⏸</span><span class="btn-text">暂停</span>';
    }

    gameOver() {
        this.gameState = 'gameOver';
        this.stopGameLoop();

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

    update() {
        this.snake.move();

        if (this.snake.checkWallCollision() || this.snake.checkSelfCollision()) {
            this.gameOver();
            return;
        }

        if (this.snake.checkFoodCollision(this.food.getPosition())) {
            this.snake.grow();
            this.score++;
            this.updateScoreDisplay();
            this.updateSpeedDisplay();
            this.food.spawn(this.snake.body);

            this.stopGameLoop();
            this.startGameLoop();
        }

        this.food.updateAnimation();
        this.render();
    }

    render() {
        this.ctx.clearRect(0, 0, CONFIG.CANVAS_SIZE, CONFIG.CANVAS_SIZE);
        drawGrid(this.ctx);
        this.food.draw(this.ctx);
        this.snake.draw(this.ctx);
    }

    startGameLoop() {
        const speed = calculateSpeed(this.score);
        this.gameLoop = setInterval(() => this.update(), speed);
    }

    stopGameLoop() {
        if (this.gameLoop) {
            clearInterval(this.gameLoop);
            this.gameLoop = null;
        }
    }

    handleKeyPress(e) {
        if (['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'Space'].includes(e.code)) {
            e.preventDefault();
        }

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

    showOverlay(title, message, type = '') {
        this.overlayTitle.textContent = title;
        this.overlayMessage.textContent = message;
        this.overlayTitle.className = `overlay-title ${type}`;
        this.overlay.style.display = 'flex';
    }

    hideOverlay() {
        this.overlay.style.display = 'none';
    }

    updateScoreDisplay() {
        this.currentScoreEl.textContent = this.score;
    }

    updateHighScoreDisplay() {
        this.highScoreEl.textContent = this.highScore;
    }

    updateSpeedDisplay() {
        const level = calculateSpeedLevel(this.score);
        this.speedLevelEl.textContent = level;
    }
}

// 页面加载完成后初始化游戏
document.addEventListener('DOMContentLoaded', () => {
    new Game();
});
