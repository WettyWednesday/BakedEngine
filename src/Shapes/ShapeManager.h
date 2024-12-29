//
// Created by magnu on 29-12-2024.
//

#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H
#include <memory>
#include <vector>

#include "raylib.h"

struct Shape
{
    Vector2 position;
    Vector2 size;
    Color color;
};

class ShapeManager {
public:
    ShapeManager() = default;
    ~ShapeManager() = default;

    void drawRect(Vector2 position, Vector2 size, Color color);

    static std::vector<std::shared_ptr<Shape>> getShapeList();

private:
    static std::vector<std::shared_ptr<Shape>> shapeList;
};



#endif //SHAPEMANAGER_H
