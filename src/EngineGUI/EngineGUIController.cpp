//
// Created by magnu on 28-12-2024.
//

#include "EngineGUIController.h"


void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}
