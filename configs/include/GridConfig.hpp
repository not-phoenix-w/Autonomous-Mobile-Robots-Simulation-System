#include <yaml-cpp/yaml.h>
#pragma once

class GridConfig final
{
public:
    int width, height;

    GridConfig(int width = 20, int height = 20) : width(width), height(height) {}

    static GridConfig fromYAML(const YAML::Node &node);

    // int getGridSizeX() const { return config["width"].as<int>(20); }
    // int getGridSizeY() const { return config["height"].as<int>(20); }
};