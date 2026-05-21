#include "game.h"

void fireEnemyBullet(Game* game, Enemy* enemy) {
    if (!game->enemyBullet.active) {
        game->enemyBullet.active = true;
        game->enemyBullet.x = enemy->x + enemy->width / 2;
        game->enemyBullet.y = enemy->y + enemy->height;
        game->enemyBullet.speed = 3.0f;
    }
}

void updateEnemyBullet(Game* game) {
    if (game->enemyBullet.active) {
        game->enemyBullet.y += game->enemyBullet.speed;
        if (game->enemyBullet.y > WINDOW_HEIGHT) {
            game->enemyBullet.active = false;
        }
    }
}