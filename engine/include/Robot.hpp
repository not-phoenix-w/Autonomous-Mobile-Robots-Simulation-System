#pragma once
#include "structs.h"
#include <memory>

using CellPtr = std::shared_ptr<Cell>;

enum class RobotState
{
    Idle = 0,
    MovingToA,
    MovingToB,
    WorkingA,
    WorkingB
};

const std::vector<std::string> stateNames = {
        "Idle",
        "MovingToA",
        "MovingToB",
        "WorkingA",
        "WorkingB"
};

struct RobotLog
{
    int id;
    Point2D position, destination;
    std::string state;
    Task act_task;
};

class Robot final
{
private:


    CellPtr curCell;
    Point2D destination;
    RobotState state = RobotState::Idle;
    Task act_task;
    int counter = 0;
    int id;
    bool moveToCell(CellPtr cell);

public:
    Robot() {};
    Robot(int id, CellPtr begin) : id(id), curCell(begin), state(RobotState::Idle) { curCell->free = false; }

    void setTask(const Task& task);
    void move(Cells4 cells);

    
    RobotState getState() const { return state; }
    int getId() const { return id; }
    Point2D getPosition() const { return curCell->position; }
    Task getActTask() const { return act_task; }
    RobotLog getLog() const 
    {
        return {id, getPosition(), destination, stateNames[static_cast<int>(state)], act_task};
    }

};