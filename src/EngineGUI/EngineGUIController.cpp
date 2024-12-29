//
// Created by magnu on 28-12-2024.
//

#include "EngineGUIController.h"

#include "../Shapes/ShapeManager.h"

void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        ShapeManager sh;
        sh.drawRect({20,20},{30,30}, BLACK);
        ShapeManager::getShapeList();
        EndDrawing();
    }
    CloseWindow();
}
