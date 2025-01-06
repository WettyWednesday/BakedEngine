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