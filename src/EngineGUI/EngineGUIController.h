//
// Created by magnu on 28-12-2024.
//

#ifndef ENGINEGUICONTROLLER_H
#define ENGINEGUICONTROLLER_H
#include <cstdint>
#include <string>
#include "raylib.h"


class EngineGUIController {
public:
    static void loadEngine();

private:
    constexpr static uint16_t SCREEN_WIDTH = 1080;
    constexpr static uint16_t SCREEN_HEIGHT = 810;
};



#endif //ENGINEGUICONTROLLER_H
