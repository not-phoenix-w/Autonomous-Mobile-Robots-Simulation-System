#pragma once
#include <string>
#include <vector>
#include <memory>

struct Point2D
{
    int x, y;
};

struct Task
{
    Point2D A;
    Point2D B;
    int id;
    int ATime = 0;
    int BTime = 0;
};

struct Cell
{
    Cell(Point2D pos, int id, bool isFree) 
        : position(pos), id(id), free(isFree) {}
    Point2D position;
    int id;
    bool free;
    bool isActive;
};

struct Cells4
{
    std::shared_ptr<Cell> under;
    std::shared_ptr<Cell> upper;
    std::shared_ptr<Cell> right;
    std::shared_ptr<Cell> left;
};

struct RobotInfo
{
    int id;
    Point2D position;
    std::string state;
};

struct WorldState
{
    int tick = 0;
    std::vector<RobotInfo> robots;
    std::vector<Point2D> activePoints;
};

