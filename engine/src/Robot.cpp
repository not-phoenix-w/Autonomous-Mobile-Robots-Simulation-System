#include "Robot.hpp"

void Robot::setTask(const Task& task)
{
    if (state != RobotState::Idle) return;

    act_task = task;
    destination = act_task.A;
    state = RobotState::MovingToA;
    counter = 0;
}

bool Robot::moveToCell(CellPtr cell)
{
    if (cell->free)
    {
        curCell->free = true;
        curCell = cell;
        cell->free = false;
        return true;
    }
    return false;
}

void Robot::move(Cells4 cells)
{
    if (state == RobotState::Idle)
    {
        if (!curCell->isActive) return;
        
        int side = rand() % 4; // Если робот без задания стоит на активной клетке, то он отходит от неё в случайном направлении

        switch(side) 
        {
            case 0:
                if (moveToCell(cells.upper)) break;
            case 1:
                if (moveToCell(cells.under)) break;
            case 2:
                if (moveToCell(cells.left)) break;
            case 3:
                if (moveToCell(cells.right)) break;
        }
    }

    if (state == RobotState::WorkingA)
    {
        if (counter >= act_task.ATime)
        {
            state = RobotState::MovingToB;
            destination = act_task.B;
            counter = 0;
            return;
        }
        ++counter;
        return;
    }

    if (state == RobotState::WorkingB)
    {
        if (counter >= act_task.BTime)
        {
            state = RobotState::Idle;
            counter = 0;
            return;
        }
        ++counter;
        return;
    }

    if (cells.upper->position.y >= destination.y && moveToCell(cells.upper)) return;

    if (cells.under->position.y <= destination.y && moveToCell(cells.under)) return;
    
    if (cells.left->position.x >= destination.x && moveToCell(cells.left)) return;

    if (cells.right->position.x <= destination.x && moveToCell(cells.right)) return;

    if (curCell->position.x == destination.x && curCell->position.y == destination.y)
    {
        if (state == RobotState::MovingToA) state = RobotState::WorkingA;
        if (state == RobotState::MovingToB) state = RobotState::WorkingB;
    }
}