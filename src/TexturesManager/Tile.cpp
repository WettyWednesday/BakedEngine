//
// Created by magnu on 29-12-2024.
//

#include  "Tile.h"

#include <algorithm>
#include <iostream>
#include <vector>

void Tile::setNewPosition(int x, int y)
{
    posX = x;
    posY = y;
}

//When isAspect is used, the method finds the closest power of 2. isAspect controls free sizing and controlled
void Tile::setNewSize(int _width, int _height, bool isAspect)
{
    std::vector tileSizes = {size8, size16, size32, size64, size128, size256, size512};

    if (isAspect)
    {
        int maxIn = std::max(_width, _height);

        int closest = tileSizes[0];
        int leastDiff = std::abs(maxIn - closest);

        for (int size : tileSizes)
        {
            int diff = std::abs(maxIn - size);
            if (diff < leastDiff)
            {
                closest = size;
                leastDiff = diff;
            }
        }
        width = height = closest;
    }
    else
    {
        width = _width;
        height = _height;
    }
}

void Tile::setNewTexture(const std::string &filename)
{
    textureLoc = "../Resources/" + filename + ".png";
}

std::pair<int, int> Tile::getPosition()
{
    return std::pair{posX,posY};
}

std::pair<int, int> Tile::getSize()
{
    return std::pair{width, height};
}

std::string Tile::getTexture()
{
    return textureLoc;
}
