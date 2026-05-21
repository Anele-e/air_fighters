#include "game.h"
#include <stdlib.h>
#include <time.h>

void updateEnemy(Game* game) {
    if (game->enemy.x < game->player.x) {
        game->enemy.x += ENEMY_MOVING_SPEED_X;
    } else if (game->enemy.x > game->player.x) {
        game->enemy.x -= ENEMY_MOVING_SPEED_X;
    }
    game->enemy.y += ENEMY_MOVING_SPEED_Y;

    if (game->enemy.y > WINDOW_HEIGHT) {
        game->enemy.x = rand() % (WINDOW_WIDTH - game->enemy.width);
        game->enemy.y = 10;
    }

    if (game->bullet.active) {
        if (game->bullet.x > game->enemy.x && game->bullet.x < game->enemy.x + game->enemy.width &&
            game->bullet.y > game->enemy.y && game->bullet.y < game->enemy.y + game->enemy.height) {
    
            game->enemy.x = rand() % (WINDOW_WIDTH - game->enemy.width);
            game->enemy.y = 10;
            

            game->bullet.active = false;
        }
}

    if (rand() % 1000 < 5) { // 0.5% chance to fire each frame
        fireEnemyBullet(game, &game->enemy);
    }
}
