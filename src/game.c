#include "game.h"


bool initGame(Game* game) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }
    
    game->running = 1;
    game->window = SDL_CreateWindow(
    WINDOW_TITLE,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN
    );

    if (game->window == NULL){
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    if (game->renderer == NULL){
        printf("Window could not be created: SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

        game->player.x = 375;
        game->player.y = 580;
        game->player.width = 50; 
        game->player.height = 50;

        return true;
    }

void handleEvents(Game* game) {
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            game->running = 0;
        }
        if (event.type == SDL_KEYDOWN){
             switch (event.key.keysym.sym) 
                {
                case SDLK_UP:
                    game->input.up = true;
                    break;
                case SDLK_DOWN:
                    game->input.down = true;
                    break;
                case SDLK_LEFT:
                    game->input.left = true;
                    break;
                case SDLK_RIGHT:
                    game->input.right = true;
                    break;
                case SDLK_ESCAPE:
                    game->running = 0;
                    break;
                }
            }

        if (event.type == SDL_KEYUP){
             switch (event.key.keysym.sym) 
                {
                case SDLK_UP:
                    game->input.up = false;
                    break;
                case SDLK_DOWN:
                    game->input.down = false;
                    break;
                case SDLK_LEFT:
                    game->input.left = false;
                    break;
                case SDLK_RIGHT:
                    game->input.right = false;
                    break;
                
                }
            }
    }
}
        
void updateGame(Game* game) {
    updatePlayer(&game->player, &game->input);
}

void renderGame(Game* game) {
    SDL_Rect playerRect = {
        (int)game->player.x,
        (int)game->player.y,
        game->player.width,
        game->player.height
    };

    SDL_SetRenderDrawColor(game->renderer, 30, 30, 30, 255);
    SDL_RenderClear(game->renderer);

    SDL_SetRenderDrawColor(game->renderer, 230, 50, 50, 255);
    SDL_RenderFillRect(game->renderer, &playerRect);


    SDL_RenderPresent(game->renderer);
}


void destroyGame(Game* game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
