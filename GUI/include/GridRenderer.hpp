#include "raylib.h"
#include <algorithm>

#pragma once

class GridRenderer final
{
private:
    int gridsizeX;
    int gridsizeY;
    int offsetX;
    int offsetY;
    int cellSize;

public:
    GridRenderer() = default;
    GridRenderer(int screenWidth, int screenHeight, int gridsizeX, int gridsizeY);

    void draw() const;
    int getCellSize(){ return cellSize; }
    int getOffsetX() { return offsetX; }
    int getOffsetY() { return offsetY; }
};
