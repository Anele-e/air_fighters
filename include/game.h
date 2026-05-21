#ifndef GAME_H

#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define TARGET_FPS 60
#define FIXED_DT (1.0 / TARGET_FPS)
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Air Fighters"
#define MOVING_SPEED 0.5
#define ENEMY_MOVING_SPEED_X 0.2
#define ENEMY_MOVING_SPEED_Y 0.1

typedef struct {
    float x;
    float y;
    int width;
    int height;
} Player;

typedef struct {
    float x;
    float y;
    int width;
    int height;
} Enemy;

typedef struct {
    bool active;
    float x;
    float y;
    float speed;
} Bullet;

typedef struct {
    bool up;
    bool down;
    bool left;
    bool right;
    bool space;
} Input;

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Input input;    
    Player player;
    Enemy enemy;
    Bullet bullet;
    Bullet enemyBullet;
} Game;


// initialize
bool initGame(Game* game);

bool checkCollisions(Enemy* enemy, Player* player);
void handleEvents(Game* game);
void updateGame(Game* game);
void renderGame(Game* game);
void updatePlayer(Player* player, Input* input, Bullet* bullet);
void updateEnemy(Game* game);
void fireBullet(Bullet* bullet, Player* player);
void updateBullet(Bullet* bullet);
void fireEnemyBullet(Game* game, Enemy* enemy);
void updateEnemyBullet(Game* game);

void destroyGame(Game* game);

#endif

