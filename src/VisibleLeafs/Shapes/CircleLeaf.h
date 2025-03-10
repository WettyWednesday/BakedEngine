#ifndef BAKEDENGINE_CIRCLELEAF_H
#define BAKEDENGINE_CIRCLELEAF_H

#include "../VisibleLeaf.h"

class CircleLeaf : public VisibleLeaf{
public:
    CircleLeaf() = default;
    void draw() override;
    void update() override;
private:
    void create(int _centerX, int _centerY, float _radius, Color _color);
};


#endif //BAKEDENGINE_CIRCLELEAF_H
