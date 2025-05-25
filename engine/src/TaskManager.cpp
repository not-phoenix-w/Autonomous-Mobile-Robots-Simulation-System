#include "TaskManager.hpp"

void TaskManager::manageTasks(std::vector<RobotPtr> robots)
{
    if (actual_task.empty())
        return;

    size_t counter = std::min(actual_task.size(), robots.size());
    for (size_t i = 0; i < counter; ++i)
    {   
        auto task = actual_task.front();
        int nearestRobotId = nearestToTask(robots, task.A);
        if (nearestRobotId != -1)
        {
            robots[nearestRobotId]->setTask(task);
            actual_task.pop_front();
            return;
        }
    }
}

int TaskManager::nearestToTask(const std::vector<RobotPtr>& robots, Point2D task_coord)
{
    int nearestRobotId = -1;
    double minDistance = std::numeric_limits<double>::max();

    for (size_t i = 0; i < robots.size(); ++i)
    {
        const auto& robot = robots[i];
        if (robot->getState() != RobotState::Idle) continue;
        
        double distance = abs(robots[i]->getPosition().x - task_coord.x) + abs(robots[i]->getPosition().y - task_coord.y);

        if (distance < minDistance)
        {
            minDistance = distance;
            nearestRobotId = i;
        }
    }

    return nearestRobotId;
}