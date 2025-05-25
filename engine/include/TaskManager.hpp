#pragma once
#include <vector>
#include <deque>
#include "structs.h"
#include "Robot.hpp"
#include <cmath>

using RobotPtr = std::shared_ptr<Robot>;

class TaskManager
{
private:
    std::deque<Task> actual_task;
    int nearestToTask(const std::vector<RobotPtr>& robots, Point2D task_coord);

public:
    TaskManager() {};
    TaskManager(std::deque<Task> actual_task) : actual_task(std::move(actual_task)) {};

    void manageTasks(std::vector<RobotPtr> robots);
};