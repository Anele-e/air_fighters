#include "game.h"

bool checkCollisions(Enemy* enemy, Player* player) {

    return (
        player->x < enemy->x + enemy->width &&
        player->x + player->width > enemy->x &&
        player->y < enemy->y + enemy->height &&
        player->y + player->height > enemy->y
    );
}