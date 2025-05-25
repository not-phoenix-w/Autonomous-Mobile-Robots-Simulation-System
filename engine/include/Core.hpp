#pragma once

#include "Robot.hpp"
#include "TaskManager.hpp"
#include "Logger.hpp"
#include "MainConfig.hpp"
#include <map>

using CellPtr = std::shared_ptr<Cell>;
using RobotPtr = std::shared_ptr<Robot>;

class Core final
{
public:
    Core() {}
    void tick();
    void stop() { running = 0; };
    Logger logger{"../log.txt"};
    void start() { running = 1; };
    void init(const MainConfig& config);
    WorldState getState() const
    {
        WorldState state;
        state.tick = currentTick;
        for (const auto& robot : robots)
        {
            state.robots.push_back({robot->getId(), robot->getPosition(), stateNames[static_cast<int>(robot->getState())]});
        }
        for (const auto& point : activePoints)
        {
            state.activePoints.push_back(point.second);
        }
        return state;
    }

private:
    bool running = 0;
    int currentTick = 0;

    std::vector<std::vector<CellPtr>> field;
    std::vector<RobotPtr> robots;
    std::map<int, Point2D> activePoints;
    TaskManager taskManager;

    Cells4 getNeighbours(Point2D pos);

};