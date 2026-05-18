#include "game.h"

void updatePlayer(Player* player, Input* input) {
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
}



