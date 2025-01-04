//
// Created by magnu on 28-12-2024.
//

#include "EngineGUIController.h"

#include <iostream>
#include <backends/imgui_impl_opengl3.h>

#include "../TexturesManager/TextureManager.h"
#include "../TexturesManager/TileMapManager.h"

void EngineGUIController::loadEngine()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BakedEngine GUI");

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();

    io.DisplaySize = ImVec2(SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!ImGui_ImplOpenGL3_Init("#version 330")) {
        std::cerr << "Failed to initialize ImGui OpenGL backend!" << std::endl;
        CloseWindow();
        return;
    }

    TileMapManager tileMapManager1;
    TileMapManager tileMapManager2;
    tileMapManager1.init(GetScreenWidth(),GetScreenHeight(),size32,10);
    tileMapManager2.init(10,10,size32,0);

    while (!WindowShouldClose())
    {
        io.DisplaySize = ImVec2(GetScreenWidth(), GetScreenHeight());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        tileMapManager1.showGridLines(RED);
        tileMapManager2.showGridLines(BLUE);

        displayTileSelectionMenu();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        DrawFPS(SCREEN_WIDTH, 0);
        EndDrawing();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();

    CloseWindow();
}

void EngineGUIController::displayTileSelectionMenu()
{
    ImGui::Begin("Tile Selection",nullptr,ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.26f, 0.4f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.65f, 1.0f, 1.0f));

    ImGui::Text("Textures");

    ImGui::PopStyleColor(2);

    ImGui::End();
}
