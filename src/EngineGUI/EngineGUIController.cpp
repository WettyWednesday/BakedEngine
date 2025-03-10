#include "EngineGUIController.h"
#include "../BaseLeaf.h"
#include "../VisibleLeafs/Shapes/CircleLeaf.h"

void EngineGUIController::loadEngine()
{
    BaseLeaf mainBL;

    std::shared_ptr<VisibleLeaf> cl = std::make_shared<CircleLeaf>();
    cl->draw();

    mainBL.add(cl);

    mainBL.create();
}
