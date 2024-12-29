//
// Created by magnu on 29-12-2024.
//

#include "ShapeManager.h"

void ShapeManager::drawRect(Vector2 position, Vector2 size, Color color)
{
    DrawRectangleV(position,size,color);
    auto newRect = std::make_shared<Shape>(Shape{position, size, color});
    shapeList.emplace_back(newRect);
}

std::vector<std::shared_ptr<Shape>> ShapeManager::getShapeList()
{
    return shapeList;
}
