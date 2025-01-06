#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <memory>
#include <vector>
#include <iostream>

#include "Tile.h"
#include "raylib.h"

struct B_Texture
{
    Tile textureTile;
    Color color;
};

class TextureManager {
public:
    template<typename... Args>
    void textureInit(Args &&... args)
    {
        for (const B_Texture& arg : { std::forward<Args>(args)... }) {
            displayedTextures.emplace_back(arg);
        }
    }

    TextureManager() = default;
    void loadAllTextures();


private:
    std::vector<B_Texture> displayedTextures;
    bool textureLoaded = false;
};




#endif //TEXTUREMANAGER_H
