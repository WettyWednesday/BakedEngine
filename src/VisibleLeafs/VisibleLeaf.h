#ifndef BAKEDENGINE_VISIBLELEAF_H
#define BAKEDENGINE_VISIBLELEAF_H


class VisibleLeaf{
public:
    virtual ~VisibleLeaf() = default;

    virtual void draw() = 0;
};


#endif //BAKEDENGINE_VISIBLELEAF_H