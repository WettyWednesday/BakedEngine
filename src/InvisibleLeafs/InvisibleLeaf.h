#ifndef BAKEDENGINE_INVISIBLELEAF_H
#define BAKEDENGINE_INVISIBLELEAF_H


class InvisibleLeaf {
public:
    virtual ~InvisibleLeaf() = default;

    virtual void update() = 0;
};


#endif //BAKEDENGINE_INVISIBLELEAF_H