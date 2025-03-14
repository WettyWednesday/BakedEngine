#include "BaseLeaf.h"

void BaseLeaf::create()
{
    InitWindow(800, 600, "Raylib BaseLeaf Example");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!visibleLeafs.empty() || !invisibleLeafs.empty())
        {
            for (auto& leaf : visibleLeafs) {
                //TODO:
            }

            for (auto& leaf : invisibleLeafs) {
                //TODO:
            }
        }

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
}

template<typename T>
void BaseLeaf::add(T &&leaf)
{
    static_assert(std::is_base_of_v<VisibleLeaf, std::decay_t<T>> ||
                  std::is_base_of_v<InvisibleLeaf, std::decay_t<T>>,
                  "Object must be derived from either Visible or Invisible Leaf"
    );

    if constexpr (std::is_base_of_v<VisibleLeaf, std::decay_t<T>>) {
        visibleLeafs.push_back(std::make_unique<std::decay_t<T>>(std::forward<T>(leaf)));
    } else if constexpr (std::is_base_of_v<InvisibleLeaf, std::decay_t<T>>) {
        invisibleLeafs.push_back(std::make_unique<std::decay_t<T>>(std::forward<T>(leaf)));
    }
}
