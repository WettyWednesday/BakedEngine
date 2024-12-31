//
// Created by magnu on 31-12-2024.
//

#ifndef BAKEDENGINE_TILEMAPMANAGER_H
#define BAKEDENGINE_TILEMAPMANAGER_H

#include <vector>
#include <memory>
#include "Tile.h"
#include "raylib.h"

class TileMapManager {
public:
    TileMapManager() = default;
    void init(int map_width, int map_height, TileSizes tileSize, float offset);
    void showGridLines();

private:
    std::vector<std::vector<std::shared_ptr<Tile>>> tileMap;

    int mapWidth = 0;
    int mapHeight = 0;
    int tileDimension = 0;
    float offset = 0;

};


#endif //BAKEDENGINE_TILEMAPMANAGER_H
