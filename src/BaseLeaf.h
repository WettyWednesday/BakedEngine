#ifndef BASELEAF_H
#define BASELEAF_H

#include <utility>
#include <thread>
#include <atomic>
#include <vector>
#include <memory>

#include "raylib.h"
#include "VisibleLeafs/VisibleLeaf.h"
#include "InvisibleLeafs/InvisibleLeaf.h"

class BaseLeaf
{
public:
    BaseLeaf() = default;

    void create();

private:
    std::vector<std::shared_ptr<VisibleLeaf>> visibleLeafs;
    std::vector<std::shared_ptr<InvisibleLeaf>> invisibleLeafs;
};


#endif //BASELEAF_H
