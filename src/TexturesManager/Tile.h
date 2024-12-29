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
    void setNewSize(int width, int height, bool isAspect);
    void setNewTexture(std::string filename);

    std::pair<int, int> getPosition();
    std::pair<int, int> getSize();
    std::string getTexture();


private:
    int posX = 0;
    int posY = 0;
    const int width = 32;
    const int height = 32;
    std::string textureLoc = "../../Resources/MissingTexture.png";
};


#endif //TILE_H
