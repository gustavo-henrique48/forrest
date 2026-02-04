#include "raylib.h"
#include "config.h"


void drawGameState(GameState state);
void drawGameScreenTitle();
void drawGameScreenGameOver();
void drawGame();


void checkPlayerHealth(GameScreen *screen, GameState *state, Player *player);
void getGameScreen(GameScreen *screen, GameState *state, Player *player);

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    SetTargetFPS(TARGET_FPS);

    GameScreen screen = TITLE;
    GameState state = PAUSED; 
    Player player;

    player.health = 1;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        getGameScreen(&screen, &state, &player);

        drawGameState(state);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void getGameScreen(GameScreen *screen, GameState *state, Player *player) {
    if (*screen == TITLE) {
        drawGameScreenTitle();
        *state = PAUSED;
    } 

    if(IsKeyReleased(KEY_ENTER)){
        checkPlayerHealth(screen, state, player);
    } 

    
}

void checkPlayerHealth(GameScreen *screen, GameState *state, Player *player){
    if(player->health <= 0 ){
        *state = GAMEOVER;
        *screen = LOST;
        drawGameScreenGameOver();
    }         
    //*state = RUNNING;
    //*screen = GAMEPLAY;
    //drawGame();

    if(IsKeyPressed(KEY_F)) player->health = player->health - 1; 
}

void drawGame(){
    ClearBackground(GREEN);
    DrawText("THE FOREST", 200, 280, 40, WHITE);
}

void drawGameScreenTitle(){
    ClearBackground(BLACK);
    DrawText("Welcome to the Forest", 280, 340, 40, WHITE);
    DrawText("Press [ENTER] to enter the game", 350, 400, 20, GREEN);
    DrawText("Press [ESC] to close the game", 350, 440, 20, RED);
}

void drawGameScreenGameOver(){
    ClearBackground(WHITE);
    DrawText("You Lost", 200, 280, 140, RED);
}


void drawGameState(GameState state) {
    if(state == PAUSED) {
            DrawText("THE GAME IS PAUSED", 0, 0, 40, WHITE);
            return;
        } 
    DrawText("THE GAME IS RUNNING", 0, 0, 40, WHITE);

}
