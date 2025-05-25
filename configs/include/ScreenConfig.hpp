#include <yaml-cpp/yaml.h>
#pragma once

class ScreenConfig final
{
public:
    int width, height;
    ScreenConfig(int width = 800, int height = 600) : width(width), height(height) {}

    static ScreenConfig fromYAML(const YAML::Node& node);
};