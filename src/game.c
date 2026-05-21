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

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (game->renderer == NULL){
        printf("Window could not be created: SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

        game->player.x = 375;
        game->player.y = 580;
        game->player.width = 50; 
        game->player.height = 50;

        game->enemy.x = rand() % (WINDOW_WIDTH - game->enemy.width);
        game->enemy.y = 10;
        game->enemy.width = 50;
        game->enemy.height = 50;

        game->bullet.active = false;

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

                case SDLK_SPACE:
                    game->input.space = true;
                    // if (!game->bullet.active) {
                    //     onRelease(&game->bullet, &game->player);
                    // }
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

                case SDLK_SPACE:
                    game->input.space = false;
                    // game->bullet.active = false;
                    // onRelease(&game->bullet, &game->player);
                    break;
                
                }
            }
    }
}
        
void updateGame(Game* game) {
    updatePlayer(&game->player, &game->input, &game->bullet);
    updateEnemy(game);

    updateBullet(&game->bullet);
    updateEnemyBullet(game);

    if (checkCollisions(&game->enemy, &game->player)) {
        game->running = false;
    }
}

void renderGame(Game* game) {
    SDL_Rect playerRect = {
        (int)game->player.x,
        (int)game->player.y,
        game->player.width,
        game->player.height
    };

    SDL_Rect enemyRect = {
        (int)game->enemy.x,
        (int)game->enemy.y,
        game->enemy.width,
        game->enemy.height
    };

    SDL_Rect bulletRect = {
        (int)game->bullet.x,
        (int)game->bullet.y,
        5,
        10
    };

    SDL_SetRenderDrawColor(game->renderer, 30, 30, 30, 255);
    SDL_RenderClear(game->renderer);

    SDL_SetRenderDrawColor(game->renderer, 230, 50, 50, 255);
    SDL_RenderFillRect(game->renderer, &playerRect);

    SDL_SetRenderDrawColor(game->renderer, 50, 230, 50, 255);
    SDL_RenderFillRect(game->renderer, &enemyRect);

    if (game->bullet.active) {
        SDL_SetRenderDrawColor(game->renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(game->renderer, &bulletRect);
    }

    SDL_RenderPresent(game->renderer);
}


void destroyGame(Game* game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
