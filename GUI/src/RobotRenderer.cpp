#include "RobotRenderer.hpp"

void RobotRenderer::draw(const std::vector<RobotInfo>& robots)
{
    for (const auto& robot: robots)
    {
        DrawCircle(beginPoint.x + robot.position.x*cellSize - cellSize/2.f,
         beginPoint.y + robot.position.y*cellSize - cellSize/2.f, cellSize / 2.f, RED);
    }
}