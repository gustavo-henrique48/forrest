#include "raylib.h"
#include "config.h"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Welcome to the Forest", 280, 340, 40, WHITE);
        DrawText("Press [ENTER] to enter the game", 350, 400, 20, GREEN);
        DrawText("Press [ESC] to close the game", 350, 440, 20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
