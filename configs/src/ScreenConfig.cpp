#include "ScreenConfig.hpp"

ScreenConfig ScreenConfig::fromYAML(const YAML::Node& node) 
{   
    try
    {
        ScreenConfig screen;
        screen.width = node["width"].as<int>(800);
        screen.height = node["height"].as<int>(600);
        return screen;
    }
    catch(const YAML::Exception& e)
    {
        throw std::runtime_error("Failed to load screen config: " + std::string(e.what()));
    }
}