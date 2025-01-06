#ifndef ENGINEGUICONTROLLER_H
#define ENGINEGUICONTROLLER_H
#include <cstdint>
#include "../TexturesManager/TileMapManager.h"



class EngineGUIController {
public:
    static void loadEngine();

private:
    static void displayTileSelectionMenu();

    constexpr static uint16_t SCREEN_WIDTH = 1080;
    constexpr static uint16_t SCREEN_HEIGHT = 810;
};



#endif //ENGINEGUICONTROLLER_H
