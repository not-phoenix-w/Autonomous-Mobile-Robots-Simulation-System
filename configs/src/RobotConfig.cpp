#include "RobotConfig.hpp"
#include <iostream>
RobotConfig RobotConfig::fromYAML(const YAML::Node& node) 
{   
    try
    {
        RobotConfig r;
        r.id = node["id"].as<int>(); 
        auto posNode = node["position"];
        r.position.x = posNode[0].as<int>(0);
        r.position.y = posNode[1].as<int>(0);
        return r;
    }
    catch(const YAML::Exception& e)
    {
        throw std::runtime_error("Failed to load robot config: " + std::string(e.what()));
    }
}

RobotConfigList RobotConfigList::fromYAML(const YAML::Node& root) {
    RobotConfigList list;
    if (!root["robots"]) return list;

    for (const auto& node : root["robots"]) {

        list.robots.push_back(RobotConfig::fromYAML(node));
    }
    return list;
}
