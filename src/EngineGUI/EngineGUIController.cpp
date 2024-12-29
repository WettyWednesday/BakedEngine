//
// Created by magnu on 28-12-2024.
//

#include "EngineGUIController.h"

#include <iostream>

#include "../TexturesManager/TextureManager.h"

void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");

    TextureManager TM;
    B_Texture b1;
    Tile t1;
    t1.setNewTexture("Grass");
    b1.textureTile = t1;
    b1.color = WHITE;
    TM.textureInit(b1);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        TM.loadAllTextures();
        DrawFPS(SCREEN_WIDTH, 0);
        EndDrawing();
    }
    CloseWindow();
}
