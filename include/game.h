#ifndef GAME_H

#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Air Fighters"
#define MOVING_SPEED 15

typedef struct {
    float x;
    float y;
    int width;
    int height;
} Player;

typedef struct {
    bool up;
    bool down;
    bool left;
    bool right;
} Input;

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Input input;    
    Player player;
} Game;


// initialize
bool initGame(Game* game);

//loop
void handleEvents(Game* game);
void updateGame(Game* game);
void renderGame(Game* game);
void updatePlayer(Player* player, Input* input);


void destroyGame(Game* game);

#endif

