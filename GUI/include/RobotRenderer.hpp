#include "structs.h"
#include <vector>
#include "raylib.h"

#pragma once

class RobotRenderer final
{
private:
    Point2D beginPoint;
    int cellSize;

public:
    RobotRenderer() = default;
    RobotRenderer(Point2D beg, int cellSize) : beginPoint(beg), cellSize(cellSize){}

    void draw(const std::vector<RobotInfo>& robots);
    ~RobotRenderer() { }
};