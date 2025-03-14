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

    template<typename T>
    void add(T&& leaf);

private:
    std::vector<std::unique_ptr<VisibleLeaf>> visibleLeafs;
    std::vector<std::unique_ptr<InvisibleLeaf>> invisibleLeafs;

};


#endif //BASELEAF_H
