#include <yaml-cpp/yaml.h>
#include "structs.h"
#pragma once

class RobotConfig final
{
public:
    Point2D position;
    int id;
    RobotConfig() : position{0, 0}, id(0) {}
    RobotConfig(Point2D pos, int robotId) : position(pos), id(robotId) {}

    static RobotConfig fromYAML(const YAML::Node& node);

};

class RobotConfigList {
public:
    std::vector<RobotConfig> robots;

    static RobotConfigList fromYAML(const YAML::Node& root);
};