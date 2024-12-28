#include <iostream>

#include "EngineGUI/EngineGUIController.h"

int main()
{
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
