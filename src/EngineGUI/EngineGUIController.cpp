//
// Created by magnu on 28-12-2024.
//

#include "EngineGUIController.h"

#include <iostream>

#include "../TexturesManager/Tile.h"


void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");
    Tile tile1;
    Tile tile2;
    tile1.setNewSize(200, 200, true);

    tile2.setNewSize(200, 200, true);
    tile2.setNewPosition(tile1.getPosition().first + tile1.getSize().first,
                         tile1.getPosition().second);
    tile2.setNewTexture("Grass");

    Texture2D texture1 = LoadTexture(tile1.getTexture().c_str());
    texture1.width = tile1.getSize().first;
    texture1.height = tile1.getSize().second;

    Texture2D texture2 = LoadTexture(tile2.getTexture().c_str());
    texture2.width = tile2.getSize().first;
    texture2.height = tile2.getSize().second;

    if (texture1.id == 0)
    {
        std::cerr << "Failed to load texture!" << std::endl;
        return;
    }
    if (texture2.id == 0)
    {
        std::cerr << "Failed to load texture!" << std::endl;
        return;
    }
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture1, tile1.getPosition().first, tile1.getPosition().second, WHITE);
        DrawTexture(texture2, tile2.getPosition().first, tile2.getPosition().second, WHITE);
        EndDrawing();
    }
    CloseWindow();
}
