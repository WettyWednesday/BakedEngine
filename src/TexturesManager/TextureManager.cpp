#include "TextureManager.h"

void TextureManager::loadAllTextures()
{
    if (!displayedTextures.empty())
    {
        if (!textureLoaded)
        {
            for (B_Texture &b_Text : displayedTextures)
            {

                Texture2D txt = LoadTexture(b_Text.textureTile.getTexture().c_str());
                if (txt.id == 0)
                {
                    std::cerr << "Failed to load texture: " << b_Text.textureTile.getTexture() << std::endl;
                    continue;
                }

                DrawTexture(txt, b_Text.textureTile.getPosition().first, b_Text.textureTile.getPosition().second,
                            b_Text.color);
            }
            textureLoaded = true;
        }
    }
    else
    {
        std::cerr << "Cant load textures, no textures to load!" << std::endl;
    }
}
