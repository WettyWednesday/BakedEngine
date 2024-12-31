//
// Created by magnu on 31-12-2024.
//

#include "TileMapManager.h"

void TileMapManager::init(int map_width, int map_height, TileSizes tileSize, float offset)
{
    this->mapWidth = map_width;
    this->mapHeight = map_height;
    this->tileDimension = static_cast<int>(tileSize);
    this->offset = offset;

    tileMap.clear();

    tileMap.resize(map_height, std::vector<std::shared_ptr<Tile>>(map_width));

    for (int y = 0; y < map_height; ++y) {
        for (int x = 0; x < map_width; ++x) {
            int posX = x * tileDimension + offset;
            int posY = y * tileDimension + offset;

            tileMap[y][x] = std::make_shared<Tile>(posX, posY, tileDimension, tileDimension);
        }
    }
}

void TileMapManager::showGridLines()
{
    for (int x = 0; x <= mapWidth; ++x) {
        int lineX = static_cast<int>(x * tileDimension + offset);
        DrawLine(lineX, static_cast<int>(offset), lineX, static_cast<int>(mapHeight * tileDimension + offset), DARKGRAY);
    }

    for (int y = 0; y <= mapHeight; ++y) {
        int lineY = static_cast<int>(y * tileDimension + offset);
        DrawLine(static_cast<int>(offset), lineY, static_cast<int>(mapWidth * tileDimension + offset), lineY, DARKGRAY);
    }
}
