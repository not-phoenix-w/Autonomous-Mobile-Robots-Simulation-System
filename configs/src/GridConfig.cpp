#include "GridConfig.hpp"

GridConfig GridConfig::fromYAML(const YAML::Node& node) 
{   
    try
    {
        GridConfig grid;
        grid.width = node["width"].as<int>(20);
        grid.height = node["height"].as<int>(20);
        return grid;
    }
    catch(const YAML::Exception& e)
    {
        throw std::runtime_error("Failed to load grid config: " + std::string(e.what()));
    }
}