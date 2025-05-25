#include "GridRenderer.hpp"

GridRenderer::GridRenderer(int screenWidth, int screenHeight, int gridsizeX, int gridsizeY)
    : gridsizeX(gridsizeX), gridsizeY(gridsizeY)
{
    cellSize = std::min(screenWidth / (gridsizeX + 2), screenHeight / (gridsizeY + 2)); 
    offsetX = (screenWidth - cellSize * gridsizeX) / 2;
    offsetY = (screenHeight - cellSize * gridsizeY) / 2;
}

void GridRenderer::draw() const
{
    for (int i = 0; i < gridsizeX; i++)
    {
        for (int j = 0; j < gridsizeY; j++)
        {
            DrawRectangleLines(
                i * cellSize + offsetX, j * cellSize + offsetY,
                cellSize, cellSize,
                LIGHTGRAY
            );
        }
    }
}