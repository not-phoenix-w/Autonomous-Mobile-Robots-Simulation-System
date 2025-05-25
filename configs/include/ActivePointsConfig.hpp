#include <yaml-cpp/yaml.h>
#include "structs.h"
#pragma once

class ActivePointsConfig final
{
public:
    Point2D position;
    int id;
    ActivePointsConfig() : position{0, 0}, id(0) {}
    ActivePointsConfig(Point2D pos, int robotId) : position(pos), id(robotId) {}

    static ActivePointsConfig fromYAML(const YAML::Node &node);
};

class ActivePointsConfigList
{
public:
    std::vector<ActivePointsConfig> points;

    static ActivePointsConfigList fromYAML(const YAML::Node &root);
};