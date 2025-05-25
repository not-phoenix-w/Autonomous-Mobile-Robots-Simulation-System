#include "raygui.h"
#include "raylib.h"
#include "Core.hpp"
#pragma once

class GuiController {
private:
    enum class SimState { STOPPED, RUNNING, PAUSED };
    SimState state;

    // GUI элементы
    int buttonWidth = 100;
    int buttonHeight = 30;
    int panelWidth = 200;
    int panelHeight = 400;

    // Цвета
    Color buttonColor = LIGHTGRAY;
    Color buttonHoverColor = GRAY;
    Color buttonActiveColor = DARKGRAY;

    int offsetY, offsetX;
    
public:
    GuiController(int offsetY = 0, int offsetX = 0) {};

    void update(Core& sim); 
    void draw();             

};
