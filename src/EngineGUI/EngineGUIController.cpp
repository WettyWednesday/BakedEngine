#include "EngineGUIController.h"

void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        //TODO: Add whatever you wanna test here
        DrawText("Welcome to the GUI :)", SCREEN_WIDTH/2 - 120, SCREEN_HEIGHT/2,24,BLACK);

        EndDrawing();
    }
    CloseWindow();
}
