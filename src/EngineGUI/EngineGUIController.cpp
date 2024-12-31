//
// Created by magnu on 28-12-2024.
//

#include "EngineGUIController.h"

#include <iostream>

#include "../TexturesManager/TextureManager.h"
#include "../TexturesManager/TileMapManager.h"

void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");

    TileMapManager tileMapManager;
    tileMapManager.init(10,10,TileSizes::size32,10);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        tileMapManager.showGridLines();

        DrawFPS(SCREEN_WIDTH, 0);
        EndDrawing();
    }
    CloseWindow();
}
