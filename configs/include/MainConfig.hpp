#include "ActivePointsConfig.hpp"
#include <yaml-cpp/yaml.h>
#pragma once

#include "RobotConfig.hpp"
#include "GridConfig.hpp"
#include "ScreenConfig.hpp"
#include "TaskConfig.hpp"

class MainConfig final
{
public:
    RobotConfigList robots;
    GridConfig grid;
    ScreenConfig screen;
    TaskConfigList tasks;
    ActivePointsConfigList activePoints;

    MainConfig() {};

    static MainConfig fromYAML(const YAML::Node &config)
    {
        MainConfig m;
        m.robots = RobotConfigList::fromYAML(config);
        m.grid = GridConfig::fromYAML(config["grid"]);
        m.screen = ScreenConfig::fromYAML(config["screen"]);
        m.tasks = TaskConfigList::fromYAML(config);
        m.activePoints = ActivePointsConfigList::fromYAML(config);
        return m;
    }
};