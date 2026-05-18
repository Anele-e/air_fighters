#include "game.h"

void updatePlayer(Player* player, Input* input, Bullet* bullet) {
    if (input->up){
        player->y -= MOVING_SPEED;
    }
    if (input->down){
        player->y += MOVING_SPEED;
    }    
    if (input->left){
        player->x -= MOVING_SPEED;
    }
        
    if (input->right){
        player->x += MOVING_SPEED;
    }

    if (input->space) {
        fireBullet(bullet, player);
    }

    // Keep the player within the window bounds
    if (player->x < 0) {
        player->x = 0;
    }
    if (player->x > WINDOW_WIDTH - player->width) {
        player->x = WINDOW_WIDTH - player->width;
    }
    if (player->y < 0) {
        player->y = 0;
    }
    if (player->y > WINDOW_HEIGHT - player->height) {
        player->y = WINDOW_HEIGHT - player->height;
    }
}



