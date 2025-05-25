#include "raylib.h"
#include <vector>
#include "structs.h"
#pragma once

class ActivePointsRenderer final
{
private:
    Point2D beginPoint;
    int cellSize;
    // Texture2D activePointTexture; For the Future

public:
    ActivePointsRenderer() = default;
    ActivePointsRenderer(Point2D beg, int cellSize)
        : beginPoint(beg), cellSize(cellSize) {}

    void draw(const std::vector<Point2D> &points);
    ~ActivePointsRenderer()
    {
        // UnloadTexture(activePointTexture);
    }
};