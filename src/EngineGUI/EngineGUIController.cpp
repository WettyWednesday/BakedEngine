#include "EngineGUIController.h"

void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");

    TileMapManager tileMapManager1;
    TileMapManager tileMapManager2;
    tileMapManager1.init(GetScreenWidth(),GetScreenHeight(),size32,10);
    tileMapManager2.init(10,10,size32,0);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        tileMapManager1.showGridLines(RED);
        tileMapManager2.showGridLines(BLUE);

        DrawFPS(SCREEN_WIDTH, 0);
        EndDrawing();
    }
    CloseWindow();
}
