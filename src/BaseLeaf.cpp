#include "BaseLeaf.h"

void BaseLeaf::create()
{
    InitWindow(800,600,"BaseLeaf");

    auto drawVisible = [&]() {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            for (const auto& leaf : visibleLeafs) {
                leaf->draw();
            }

            EndDrawing();
        }
    };

    auto updateInvisible = [&]() {
        while (!WindowShouldClose()) {
            for (const auto& leaf : invisibleLeafs) {
                leaf->update();
            }
        }
    };

    std::thread drawThread(drawVisible);
    std::thread updateThread(updateInvisible);

    if (drawThread.joinable()) {
        drawThread.join();
    }

    if (updateThread.joinable()) {
        updateThread.join();
    }

    CloseWindow();
}
