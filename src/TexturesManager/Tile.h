//
// Created by magnu on 29-12-2024.
//

#ifndef TILE_H
#define TILE_H
#include <string>
#include <utility>

class Tile
{
public:
    void setNewPosition(int x, int y);
    void setNewSize(int _width, int _height, bool isAspect);
    void setNewTexture(std::string filename);

    std::pair<int, int> getPosition();
    std::pair<int, int> getSize();
    std::string getTexture();


private:
    int posX = 0;
    int posY = 0;
    int width = 32;
    int height = 32;
    std::string textureLoc = "../../Resources/MissingTexture.png";
};

enum TileSizes
{
    size8 = 8,
    size16 = 16,
    size32 = 32,
    size64 = 64,
    size128 = 128,
    size256 = 256,
    size512 = 512,
};

#endif //TILE_H
