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

    // if (SDL_Init(SDL_INIT_VIDEO) != 0){
    //     printf("SDL_Init Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // //CREAT WINDOW
    // SDL_Window* window = NULL;

    // window = SDL_CreateWindow(
    //     "Air Fighters",
    //     SDL_WINDOWPOS_CENTERED,
    //     SDL_WINDOWPOS_CENTERED,
    //     800,
    //     800,
    //     SDL_WINDOW_SHOWN
    // );

    // if (window == NULL){
    //     printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return 1;
    // }

    // // Renderer
    // SDL_Renderer* renderer = NULL;

    // renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // if (renderer == NULL){
    //     printf("Window could not be created: SDL_Error: %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return 1;
    // }

    // SDL_Rect player = {375, 275, 50, 50};
    // int moving_speed = 15;
    // int running = 1;
    // SDL_Event event;

    // while (running){
    //     while (SDL_PollEvent(&event)){
    //         if (event.type == SDL_QUIT){
    //             running = 0;
    //         }

    //         else if (event.type == SDL_KEYDOWN) {
    //             switch (event.key.keysym.sym) 
    //             {
    //             case SDLK_UP:
    //                 player.y -= moving_speed;
    //                 break;
    //             case SDLK_DOWN:
    //                 player.y += moving_speed;
    //                 break;
    //             case SDLK_LEFT:
    //                 player.x -= moving_speed;
    //                 break;
    //             case SDLK_RIGHT:
    //                 player.x += moving_speed;
    //                 break;
    //             case SDLK_ESCAPE:
    //                 running = 0;
    //                 break;
                
    //             default:
    //                 break;
    //             }
    //         }
    //     }
    

    // SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    // SDL_RenderClear(renderer);

    // SDL_SetRenderDrawColor(renderer, 230, 50, 50, 255);
    // SDL_RenderFillRect(renderer, &player);

    // //updated
    // SDL_RenderPresent(renderer);

    // }

    
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    return 0;
}

