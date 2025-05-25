#pragma once
#include "ActivePointsRenderer.hpp"
#include "GridRenderer.hpp"
#include "GuiController.hpp"
#include "RobotRenderer.hpp"
#include "MainConfig.hpp"
#include "structs.h"

class ApplicationWindow final
{
private:
    GuiController gui;
    GridRenderer grid;
    RobotRenderer robots;
    ActivePointsRenderer points;
    int screenWidth, screenHeight;
public:
    ApplicationWindow(const MainConfig& config);
    void draw(const WorldState& state);
    void init();
};