#include "ActivePointsRenderer.hpp"

void ActivePointsRenderer::draw(const std::vector<Point2D> &points)
{
    for (const auto &point : points)
    {
        DrawTriangle({beginPoint.x + point.x * cellSize - cellSize / 2.f, beginPoint.y + point.y * cellSize + 0.f},
                     {beginPoint.x + point.x * cellSize + 0.f, beginPoint.y + point.y * cellSize - cellSize + 0.f},
                     {beginPoint.x + point.x * cellSize - cellSize + 0.f, beginPoint.y + point.y * cellSize - cellSize + 0.f}, ORANGE);
    }
}