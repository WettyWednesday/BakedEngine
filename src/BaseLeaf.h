#ifndef BASELEAF_H
#define BASELEAF_H

#include <utility>
#include <thread>
#include <atomic>
#include <vector>
#include <memory>
#include <mutex>

#include "raylib.h"
#include "VisibleLeafs/VisibleLeaf.h"
#include "InvisibleLeafs/InvisibleLeaf.h"

class BaseLeaf
{
public:
    BaseLeaf() = default;

    void create();

    void add(std::shared_ptr<VisibleLeaf> visibleLeaf);

    void add(std::shared_ptr<InvisibleLeaf> invisibleLeaf);

private:
    std::vector<std::shared_ptr<VisibleLeaf>> visibleLeafs;
    std::vector<std::shared_ptr<InvisibleLeaf>> invisibleLeafs;
    std::mutex leafMutex;

    bool running = true;
};


#endif //BASELEAF_H
