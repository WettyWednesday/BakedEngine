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

    auto totalMapWidth = static_cast<float>(map_width * tileDimension);
    auto totalMapHeight = static_cast<float>(map_height * tileDimension);

    float centerX = static_cast<float>(GetScreenWidth()) / 2.0f + offset;
    float centerY = static_cast<float>(GetScreenHeight()) / 2.0f + offset;

    this->offsetX = centerX - (totalMapWidth / 2.0f);
    this->offsetY = centerY - (totalMapHeight / 2.0f);

    tileMap.clear();

    tileMap.resize(map_height, std::vector<std::shared_ptr<Tile>>(map_width));

    for (int y = 0; y < map_height; ++y) {
        for (int x = 0; x < map_width; ++x) {
            int posX = static_cast<int>(x * tileDimension + offsetX);
            int posY = static_cast<int>(y * tileDimension + offsetY);

            tileMap[y][x] = std::make_shared<Tile>(posX, posY, tileDimension, tileDimension);
        }
    }
}

void TileMapManager::showGridLines(Color color)
{
    for (int x = 0; x <= mapWidth; ++x) {
        int lineX = static_cast<int>(x * tileDimension + offsetX);
        DrawLine(lineX, static_cast<int>(offsetY), lineX, static_cast<int>(mapHeight * tileDimension + offsetY), color);
    }

    for (int y = 0; y <= mapHeight; ++y) {
        int lineY = static_cast<int>(y * tileDimension + offsetY);
        DrawLine(static_cast<int>(offsetX), lineY, static_cast<int>(mapWidth * tileDimension + offsetX), lineY, color);
    }
}
