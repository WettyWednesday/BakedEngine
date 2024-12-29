#include <iostream>

#include "EngineGUI/EngineGUIController.h"
#include "TexturesManager/Tile.h"

int main()
{
    Tile tile;
    tile.setNewSize(10,10,true);

    std::cout << "Open Engine GUI [G]" << std::endl;
    char in;
    std::cin >> in;
    if (in == 'G' || in == 'g')
    {
        EngineGUIController::loadEngine();
    }
    else
    {
        std::cerr << "Wrong input!" << std::endl;
    }
}
