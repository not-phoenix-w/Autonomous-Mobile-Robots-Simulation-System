#include "GuiController.hpp"
#include <iostream>

void GuiController::draw() {
    GuiGroupBox({ 10, 10, 160, 140 }, "Simulation Control");

    if (GuiButton({ 20, 40, 120, 30 }, "Start")) state = SimState::RUNNING;
    if (GuiButton({ 20, 80, 120, 30 }, "Pause")) state = SimState::PAUSED;
    if (GuiButton({ 20, 120, 120, 30 }, "Reset")) state = SimState::STOPPED;
}

void GuiController::update(Core& sim) {
    switch (state) {
        case SimState::RUNNING: sim.tick();  break;
        case SimState::PAUSED: /* ничего */ break;
        case SimState::STOPPED: sim.stop(); break;
    }
}
