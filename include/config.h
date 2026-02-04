#ifndef CONFIG_H
#define CONFIG_H

static const int WINDOW_WIDTH = 1000;
static const int WINDOW_HEIGHT = 700;
static const int TARGET_FPS = 120;
static const char *WINDOW_TITLE = "forest";

typedef enum {
    TITLE,
    GAMEPLAY,
    ENDING,
    LOST,
} GameScreen;

typedef enum {
    RUNNING,
    PAUSED,
    GAMEOVER,
} GameState;

typedef struct {
    int health;
}Player ;

#endif