#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include "game.h"


int main() {

    Game air_fighter;
    if (!initGame(&air_fighter)) {
        return 1;
    }

    while (air_fighter.running) {
        handleEvents(&air_fighter);
        updateGame(&air_fighter);
        renderGame(&air_fighter);
    }

    destroyGame(&air_fighter);
    return 0;
}

