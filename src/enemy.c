#include "game.h"
#include <stdlib.h>
#include <time.h>

void updateEnemy(Enemy* enemy, Player* player, Bullet* bullet) {
    if (enemy->x < player->x) {
        enemy->x += ENEMY_MOVING_SPEED_X;
    } else if (enemy->x > player->x) {
        enemy->x -= ENEMY_MOVING_SPEED_X;
    }
    enemy->y += ENEMY_MOVING_SPEED_Y;

    if (enemy->y > WINDOW_HEIGHT) {
        enemy->x = rand() % (WINDOW_WIDTH - enemy->width);
        enemy->y = 10;
    }

    if (bullet->active) {
        if (bullet->x > enemy->x && bullet->x < enemy->x + enemy->width &&
            bullet->y > enemy->y && bullet->y < enemy->y + enemy->height) {
    
            enemy->x = rand() % (WINDOW_WIDTH - enemy->width);
            enemy->y = 10;
            

            bullet->active = false;
        }
}
}
