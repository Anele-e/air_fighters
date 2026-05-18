#include "game.h"

void fireBullet(Bullet* bullet, Player* player) {
    if (!bullet->active) {
        bullet->active = true;
        bullet->x = player->x + player->width / 2;
        bullet->y = player->y;
        bullet->speed = 5.0f;
    }
}

void updateBullet(Bullet* bullet) {
    if (bullet->active) {
        bullet->y -= bullet->speed;
        if (bullet->y < 0) {
            bullet->active = false;
        }
    }
}
