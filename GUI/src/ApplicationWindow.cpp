#include "ApplicationWindow.hpp"
#include <unistd.h>

ApplicationWindow::ApplicationWindow(const MainConfig& config)
{
    screenHeight = config.screen.height;
    screenWidth = config.screen.width;
    grid = GridRenderer(config.screen.width, config.screen.height, config.grid.width, config.grid.height);
    robots = RobotRenderer({grid.getOffsetX(), grid.getOffsetY()}, grid.getCellSize());
    points = ActivePointsRenderer({grid.getOffsetX(), grid.getOffsetY()}, grid.getCellSize());
    gui = GuiController(20, 20);
}

void ApplicationWindow::draw(const WorldState& state)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    grid.draw();
    points.draw(state.activePoints);
    robots.draw(state.robots);
    EndDrawing();
    usleep(500000);
}

void ApplicationWindow::init()
{
    InitWindow(screenWidth, screenHeight, "Robot Simulation");
    SetTargetFPS(60);
}