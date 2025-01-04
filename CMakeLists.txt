cmake_minimum_required(VERSION 3.28)
project(BakedEngine)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# RayLib
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

# ImGUI
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.89.5
)
FetchContent_MakeAvailable(imgui)

# GLFW
if (NOT TARGET glfw)
    FetchContent_Declare(
            glfw
            GIT_REPOSITORY https://github.com/glfw/glfw.git
            GIT_TAG 3.3.8
    )
    FetchContent_MakeAvailable(glfw)

    target_include_directories(BakedEngine PRIVATE ${glfw_SOURCE_DIR}/include)
    target_link_libraries(BakedEngine PRIVATE glfw)
endif()

add_executable(BakedEngine src/main.cpp
        src/EngineGUI/EngineGUIController.cpp
        src/EngineGUI/EngineGUIController.h
        src/TexturesManager/TileManager.cpp
        src/TexturesManager/TileManager.h
        src/TexturesManager/Tile.h
        src/TexturesManager/Tile.cpp
        src/TexturesManager/TextureManager.cpp
        src/TexturesManager/TextureManager.h
        src/TexturesManager/TileMapManager.cpp
        src/TexturesManager/TileMapManager.h
)

#Raylib
target_link_libraries(BakedEngine PRIVATE raylib)
target_link_directories(BakedEngine PRIVATE ${RAYLIB_INCLUDE_DIRS})

#ImGui
target_include_directories(BakedEngine PRIVATE ${imgui_SOURCE_DIR})
target_sources(BakedEngine PRIVATE
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
)

#GLFW
target_include_directories(BakedEngine PRIVATE ${glfw_SOURCE_DIR}/include)
target_link_libraries(BakedEngine PRIVATE glfw)