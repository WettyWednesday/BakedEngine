#include "CircleLeaf.h"

void CircleLeaf::draw()
{
    int initialX = 100, initialY = 100;
    float initialRadius = 20;
    auto initialColor = RED;
    create(initialX, initialY, initialRadius, initialColor);
}

void CircleLeaf::create(int _centerX, int _centerY, float _radius, Color _color)
{
    DrawCircle(_centerX, _centerY, _radius, _color);
}

void CircleLeaf::update()
{

}


