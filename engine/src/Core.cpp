#include "Core.hpp"

Cells4 Core::getNeighbours(Point2D pos)
{
    Cells4 neighbours;

    neighbours.under = field[pos.y + 1][pos.x];
    neighbours.upper = field[pos.y - 1][pos.x];
    neighbours.left = field[pos.y][pos.x - 1];
    neighbours.right = field[pos.y][pos.x + 1];

    return neighbours;
}

void Core::tick()
{
    if (!running)
        return;

    for (auto &robot : robots)
    {
        auto cells = getNeighbours(robot->getPosition());
        robot->move(cells);
    }

    taskManager.manageTasks(robots);

    logger.logTick(currentTick++, robots);
}

void Core::init(const MainConfig &config)
{
    field.resize(config.grid.height + 2, std::vector<CellPtr>(config.grid.width + 2, nullptr));
    robots.resize(config.robots.robots.size());

    int width = config.grid.width;
    int height = config.grid.height;
    for (int i = 0; i < height + 2; ++i)
    {
        field[i][0] = std::make_shared<Cell>(Point2D{0, i}, i * (width + 2), false);
        field[i][width + 1] = std::make_shared<Cell>(Point2D{0, i}, i * (width + 2), false);
    }
    for (int i = 0; i < width + 2; ++i)
    {
        field[0][i] = std::make_shared<Cell>(Point2D{i, 0}, i, false);
        field[height + 1][i] = std::make_shared<Cell>(Point2D{i, height + 1}, i + (height + 1) * (width + 2), false);
    }

    for (int i = 1; i < height + 1; ++i)
    {
        for (int j = 1; j < width + 1; ++j)
        {
            field[i][j] = std::make_shared<Cell>(Point2D{j, i}, i * (width) + j, true);
        }
    }

    for (size_t i = 0; i < config.robots.robots.size(); ++i)
    {
        const auto &robotConfig = config.robots.robots[i];
        robots[i] = std::make_shared<Robot>(robotConfig.id, field[robotConfig.position.y][robotConfig.position.x]);
    }


    for (const auto &point : config.activePoints.points)
    {
        activePoints[point.id] = point.position;
        auto cell = field[point.position.y][point.position.x];
        cell->isActive = true;
    }

    std::deque<Task> tasks;
    for (const auto &task : config.tasks.tasks)
    {
        tasks.push_back(Task{activePoints[task.beginPointId], activePoints[task.endPointId], task.id});
    }
    taskManager = TaskManager(tasks);
}