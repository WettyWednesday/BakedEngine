#include "BaseLeaf.h"

void BaseLeaf::create()
{
    InitWindow(800,600,"BaseLeaf");

    std::thread updateThread([&]() {
        while (running) {
            std::lock_guard<std::mutex> lock(leafMutex);
            for (const auto& leaf : invisibleLeafs) {
                leaf->update();
            }
        }
    });

    while (!WindowShouldClose()) {
        {
            std::lock_guard<std::mutex> lock(leafMutex);
            for (const auto& leaf : visibleLeafs) {
                leaf->update();
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        {
            std::lock_guard<std::mutex> lock(leafMutex);
            for (const auto& leaf : visibleLeafs) {
                leaf->draw();
            }
        }

        EndDrawing();
    }

    running = false;
    if (updateThread.joinable()) {
        updateThread.join();
    }

    CloseWindow();
}

void BaseLeaf::add(std::shared_ptr<InvisibleLeaf> invisibleLeaf)
{

}

void BaseLeaf::add(std::shared_ptr<VisibleLeaf> visibleLeaf)
{

}
